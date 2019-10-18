#include "NPC.h"

void NPC::setUpAssets()
{

	if (!m_NPCTexture.loadFromFile("ASSETS\\IMAGES\\NPC.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	m_NPCSprite.setTexture(m_NPCTexture);
	m_NPCSprite.setPosition(800.0f, 600.0f);
	m_NPCSprite.setOrigin(m_NPCTexture.getSize().x / 2, m_NPCTexture.getSize().y / 2);
	m_NPCPosition = m_NPCSprite.getPosition();

	if (!m_NPCTexture2.loadFromFile("ASSETS\\IMAGES\\NPC2.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	m_NPCSprite2.setTexture(m_NPCTexture2);
	m_NPCSprite2.setPosition(400.0f, 500.0f);
	m_NPCSprite2.setOrigin(m_NPCTexture2.getSize().x / 2, m_NPCTexture2.getSize().y / 2);
	m_NPCPosition2 = m_NPCSprite2.getPosition();


	if (!m_NPCTexture3.loadFromFile("ASSETS\\IMAGES\\NPC3.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	m_NPCSprite3.setTexture(m_NPCTexture3);
	m_NPCSprite3.setPosition(400.0f, 1000.0f);
	m_NPCSprite3.setOrigin(m_NPCTexture3.getSize().x / 2, m_NPCTexture3.getSize().y / 2);
	m_NPCPosition3 = m_NPCSprite3.getPosition();

	if (!m_NPCTexture4.loadFromFile("ASSETS\\IMAGES\\NPC4.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	m_NPCSprite4.setTexture(m_NPCTexture4);
	m_NPCSprite4.setPosition(400.0f, 1300.0f);
	m_NPCSprite4.setOrigin(m_NPCTexture4.getSize().x / 2, m_NPCTexture4.getSize().y / 2);
	m_NPCPosition4 = m_NPCSprite4.getPosition();


	if (!m_NPCTexture5.loadFromFile("ASSETS\\IMAGES\\NPC5.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	m_NPCSprite5.setTexture(m_NPCTexture5);
	m_NPCSprite5.setPosition(400.0f, 1600.0f);
	m_NPCSprite5.setOrigin(m_NPCTexture5.getSize().x / 2, m_NPCTexture5.getSize().y / 2);
	m_NPCPosition5 = m_NPCSprite3.getPosition();
}

void NPC::setUpFieldOfView()
{
	fieldOfView[0].position = m_NPCPosition;

}

void NPC::dynamicWander()
{
	m_randomDirection = (rand() % 3) - 1;

	m_maxRotation = (rand() % 11);
	m_rotation = m_rotation + (m_maxRotation * m_randomDirection);

	m_magnitude = std::sqrt(std::pow(m_NPCVelocity.x, 2) + std::pow(m_NPCVelocity.y, 2));
	m_direction = sf::Vector2f(std::cos(m_rotation * (3.14159265358979323846 / 180)), std::sin(m_rotation) * (3.14159265358979323846 / 180));
	m_NPCVelocity = m_magnitude * (sf::Vector2f(std::cos(m_rotation * (3.14159265358979323846 / 180)), std::sin(m_rotation * (3.14159265358979323846 / 180))));

	m_NPCVelocity += m_direction;

	if (MAX_SPEED < m_magnitude)
	{
		m_NPCVelocity = m_direction * MAX_SPEED;
	}
	m_NPCSprite.setRotation(m_rotation);

}

void NPC::dynamicSeek(sf::Vector2f& pos)
{
	m_direction.x = pos.x - m_NPCPosition2.x;
	m_direction.y = pos.y - m_NPCPosition2.y;

	m_distance = std::sqrt((m_direction.x * m_direction.x) + (m_direction.y * m_direction.y));
	m_rotation = std::atan(m_direction.y / m_direction.x) * (180 / 3.14159265358979323846);

	m_NPCSprite2.setRotation(m_rotation);

	if (m_distance >= m_arrivalRadius)
	{
		m_NPCVelocity2 = (m_direction / (m_distance * .2f));
	}
	else
	{
		dynamicArrive(pos);
	}


}

void NPC::dynamicArrive(sf::Vector2f& pos)
{
	
	m_direction.x = pos.x - m_NPCPosition2.x;
	m_direction.y = pos.y - m_NPCPosition2.y;
	m_distance = std::sqrt((m_direction.x * m_direction.x) + (m_direction.y * m_direction.y));


	m_rotation = std::atan(m_direction.y / m_direction.x) * (180 / 3.14159265358979323846);
	m_NPCSprite2.setRotation(m_rotation);

	if (m_distance < m_arrivalRadius)
	{
		m_direction.x = m_distance * MAX_SPEED * (m_distance/m_arrivalRadius);
		m_direction.y = m_distance * MAX_SPEED * (m_distance / m_arrivalRadius);
	}
	
}

void NPC::dynamicFlee(sf::Vector2f& pos)
{
	m_direction.x = pos.x - m_NPCPosition3.x;
	m_direction.y = pos.y - m_NPCPosition3.y;

	m_distance = std::sqrt((m_direction.x * m_direction.x) + (m_direction.y * m_direction.y));
	m_rotation = std::atan(m_direction.y / m_direction.x) * (180 / 3.14159265358979323846);

	m_NPCSprite3.setRotation(m_rotation);

	if (m_distance <= m_arrivalRadius)
	{
		m_NPCVelocity3 = -(m_direction / (m_distance * .2f));
	}

}

void NPC::dynamicPursue(sf::Vector2f& pos)
{


}

void NPC::npcMove()
{
	if (m_magnitude > MAX_SPEED)
	{
		m_NPCVelocity = m_direction * MAX_SPEED;
		m_NPCVelocity2 = m_direction * MAX_SPEED;
		m_NPCVelocity3 = m_direction * MAX_SPEED;
		m_NPCVelocity4 = m_direction * MAX_SPEED;
		m_NPCVelocity4 = m_direction * MAX_SPEED;
	}

	m_NPCPosition = m_NPCPosition + m_NPCVelocity;
	m_NPCSprite.setPosition(m_NPCPosition);

	m_NPCPosition2 = m_NPCPosition2 + m_NPCVelocity2;
	m_NPCSprite2.setPosition(m_NPCPosition2);

	m_NPCPosition3 = m_NPCPosition3 + m_NPCVelocity3;
	m_NPCSprite3.setPosition(m_NPCPosition3);

	m_NPCPosition4 = m_NPCPosition4 - m_NPCVelocity4;
	m_NPCSprite4.setPosition(m_NPCPosition4);

	m_NPCPosition5 = m_NPCPosition5 - m_NPCVelocity5;
	m_NPCSprite5.setPosition(m_NPCPosition5);
}


