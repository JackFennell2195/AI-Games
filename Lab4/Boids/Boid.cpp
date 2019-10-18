// This file defines the boid class. This includes the attributes found in
// boids -- speed, location on the board, acceleration, etc.
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include "SFML/Graphics.hpp"
#include "Boid.h"

// Global Variables for borders()
// desktopTemp gets screen resolution of PC running the program
sf::VideoMode desktopTemp = sf::VideoMode::getDesktopMode(); 
const int window_height = desktopTemp.height;
const int window_width = desktopTemp.width;

#define w_height window_height
#define w_width window_width
#define PI 3.141592635

using namespace std;

// =============================================== //
// ======== Boid Functions from Boid.h =========== //
// =============================================== //

// Adds force Pvector to current force Pvector
void Boid::applyForce(Pvector force)
{
	acceleration.addVector(force);
}

Pvector Boid::Move(vector<Boid>& Boids)
{

	Pvector sumOfAll(0, 0);
	//Seperation variables
	float desiredseparation = 20;
	Pvector seperationSteer(0, 0);
	int seperationCount = 0;

	//Allignment variables
	Pvector allignmentSum(0, 0);
	int allignmentCount = 0;
	Pvector allignmentSteer(0,0);

	//Cohesion variables
	Pvector cohesionSum(0, 0);
	int cohesionCount = 0;

	for (int i = 0; i < Boids.size(); i++)
	{
		// Calculate distance from current boid to boid we're looking at
		float a = location.distance(Boids[i].location);
		if (a < neighbourDistance) //Only nearest neighbours
		{
			// If this is a fellow boid and it's too close, move away from it
			if ((a > 0) && (a < desiredseparation))
			{
				Pvector diff(0, 0);
				diff = diff.subTwoVector(location, Boids[i].location);
				diff.normalize();
				diff.divScalar(a);      // Weight by distance
				seperationSteer.addVector(diff);
				seperationCount++;
			}
			// If current boid is a predator and the boid we're looking at is also
			// a predator, then separate only slightly 
			if ((a > 0) && (a < desiredseparation) && predator == true && Boids[i].predator == true)
			{
				Pvector pred2pred(0, 0);
				pred2pred = pred2pred.subTwoVector(location, Boids[i].location);
				pred2pred.normalize();
				pred2pred.divScalar(a);
				seperationSteer.addVector(pred2pred);
				seperationCount++;
			}
			// If current boid is not a predator, but the boid we're looking at is
			// a predator, then create a large separation Pvector
			else if ((a > 0) && (a < desiredseparation + 70) && Boids[i].predator == true)
			{
				Pvector pred(0, 0);
				pred = pred.subTwoVector(location, Boids[i].location);
				pred.mulScalar(900);
				seperationSteer.addVector(pred);
				seperationCount++;
			}
		}

		float b = location.distance(Boids[i].location);
		if ((b > 0) && (b < neighbourDistance)) // 0 < d < 50. Only nearest neighbours
		{
			allignmentSum.addVector(Boids[i].velocity);
			allignmentCount++;
		}

		float c = location.distance(Boids[i].location);
		if ((c > 0) && (c < neighbourDistance))
		{
			cohesionSum.addVector(Boids[i].location);
			cohesionCount++;
		}

	}

	// Adds average difference of location to acceleration
	if (seperationCount > 0)
		seperationSteer.divScalar((float)seperationCount);
	if (seperationSteer.magnitude() > 0)
	{
		// Steering = Desired - Velocity
		seperationSteer.normalize();
		seperationSteer.mulScalar(maxSpeed);
		seperationSteer.subVector(velocity);
		seperationSteer.limit(maxForce);
		return seperationSteer;
	}

	if (allignmentCount > 0)
	{
		allignmentSum.divScalar((float)allignmentCount);// Divide sum by the number of close boids (average of velocity)
		allignmentSum.normalize();	   		// Turn sum into a unit vector, and
		allignmentSum.mulScalar(maxSpeed);    // Multiply by maxSpeed
		// Steer = Desired - Velocity
		allignmentSteer = allignmentSteer.subTwoVector(allignmentSum, velocity); //sum = desired(average)  
		allignmentSteer.limit(maxForce);

		return allignmentSteer;
	}
	else 
	{
		Pvector temp(0, 0);
		return temp;
	}

	if (cohesionCount > 0)
	{
		cohesionSum.divScalar(cohesionCount);
		return seek(cohesionSum);
	}
	else {
		Pvector temp(0, 0);
		return temp;
	}

	seperationSteer.mulScalar(1.5);
	allignmentSteer.mulScalar(1.0); // Might need to alter weights for different characteristics
	cohesionSum.mulScalar(1.0);

	sumOfAll.addVector(seperationSteer);
	sumOfAll.addVector(allignmentSteer);
	sumOfAll.addVector(cohesionSum);
	return sumOfAll;
}

// Seek function limits the maxSpeed, finds necessary steering force and
// normalizes the vectors.
Pvector Boid::seek(Pvector& v)
{
	Pvector desired;
	desired.subVector(v);  // A vector pointing from the location to the target
	// Normalize desired and scale to maximum speed
	desired.normalize();
	desired.mulScalar(maxSpeed);
	// Steering = Desired minus Velocity
	acceleration.subTwoVector(desired, velocity);
	acceleration.limit(maxForce);  // Limit to maximum steering force
	return acceleration;
}

//Update modifies velocity, location, and resets acceleration with values that
//are given by the three laws.
void Boid::update()
{
	//To make the slow down not as abrupt
	acceleration.mulScalar(.4);
	// Update velocity
	velocity.addVector(acceleration);
	// Limit speed
	velocity.limit(maxSpeed);
	location.addVector(velocity);
	// Reset accelertion to 0 each cycle
	acceleration.mulScalar(0);
}

//Run runs flock on the flock of boids for each boid.
//Which applies the three rules, modifies accordingly, updates data, checks is data is
//out of range, fixes that for SFML, and renders it on the window.
void Boid::run(vector <Boid>& v)
{
	flock(v);
	update();
	borders();
}

//Applies all three laws for the flock of boids and modifies to keep them from
//breaking the laws.
void Boid::flock(vector<Boid>& v) 
{
	Pvector move = Move(v);


	// Arbitrarily weight these forces
	//sep.mulScalar(1.5);
	//ali.mulScalar(1.0); // Might need to alter weights for different characteristics
	//coh.mulScalar(1.0);
	// Add the force vectors to acceleration
	applyForce(move);
	

}

// Checks if boids go out of the window and if so, wraps them around to the other side.
void Boid::borders()
{
	if (location.x < 0) location.x = w_width; 
	if (location.y < 0) location.y += w_height;
	if (location.x > w_width) location.x = 0;
	if (location.y > w_height) location.y = 0;
}

// Calculates the angle for the velocity of a boid which allows the visual 
// image to rotate in the direction that it is going in.
float Boid::angle(Pvector& v)
{
	// From the definition of the dot product
	float angle = (float)(atan2(v.x, -v.y) * 180 / PI);
	return angle;
}

void Boid::swarm(vector <Boid>& v)
{
	/*		Lenard-Jones Potential function

				Vector R = me.position - you.position
				Real D = R.magnitude()
				Real U = -A / pow(D, N) + B / pow(D, M)
				R.normalise()
				force = force + R*U
	*/

	Pvector R(0, 0);
	float D;
	float U;
	Pvector force(0, 0);
	int count = 0;


	
		R = R.subTwoVector(location, v.back().location);
		D = R.magnitude();

		U = -A / pow(D, N) + B / pow(D, M);
		R.normalize();
		R.mulScalar(U);
		force.addVector(R);
	
		

		applyForce(force);
		update();
		borders();
}

