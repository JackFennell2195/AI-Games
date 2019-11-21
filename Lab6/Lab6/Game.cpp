#include "Game.h"
#include <iostream>
/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 1400U, 1400U, 32U }, "SFML Game" },
	m_exitGame{ false } //when true game will exit
{
	createGrid();
}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
Game::~Game()
{
}

/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if (sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
		if (sf::Event::MouseButtonPressed == newEvent.type) //user pressed a key
		{
			processClicks(newEvent);
		}
	}
}


/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}

void Game::processClicks(sf::Event t_event)
{
	if (sf::Mouse::Left == t_event.key.code)
	{
		getSquareClicked();
	}
	if (sf::Mouse::Right == t_event.key.code)
	{
		getSquareClicked();
	}
	if (sf::Mouse::Middle == t_event.key.code)
	{
		createObstacle();
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Blue);
	for (int i = 0; i < (m_gridSize - 1); i++)
	{
		m_square[i]->render();
	}
	m_window.display();
}

void Game::createGrid()
{
	for (int i = 0; i < (m_gridSize - 1); i++)
	{
		m_square.push_back(new Square(m_window));
		m_square[i]->setSize(sf::Vector2f((m_window.getSize().x / m_gridHeight),(m_window.getSize().y / m_gridWidth)));
		m_square[i]->setID(i);
	}

	float x = 0;
	float y = 0;
	float xcount = 0;
	float ycount = 0;
	for (int j = 0; j < (m_gridSize - 1); j++)
	{
		m_square[j]->setPosition(sf::Vector2f(x, y));

		if (x < (m_window.getSize().x) - (m_square[j]->getSquareSize().x))
		{
			x += m_square[j]->getSquareSize().x;
		}
		else
		{
			xcount++;
			ycount++;
			x = 0;
			y = (m_square[j]->getSquareSize().y * ycount);
		}
	}
}

void Game::getSquareClicked()
{
	
	sf::Vector2f m_click = sf::Vector2f(sf::Mouse::getPosition(m_window).x, sf::Mouse::getPosition(m_window).y);
	for (int k = 0; k < (m_gridSize - 1); k++)
	{
		if (m_square[k]->getSquarePosition().x >= m_click.x && ((m_square[k]->getSquarePosition().y >= m_click.y)))
		{
			
		}
		else
		{

		}
	}

}

void Game::createObstacle()
{
	sf::Vector2f m_click = sf::Vector2f(sf::Mouse::getPosition(m_window).x, sf::Mouse::getPosition(m_window).y);
	for (int l = 0; l < (m_gridSize - 1); l++)
	{

	}

}
