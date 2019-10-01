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
	m_NPCSprite2.setPosition(400.0f, 300.0f);
	m_NPCSprite2.setOrigin(m_NPCTexture2.getSize().x / 2, m_NPCTexture2.getSize().y / 2);
	m_NPCPosition2 = m_NPCSprite2.getPosition();


	if (!m_NPCTexture3.loadFromFile("ASSETS\\IMAGES\\NPC3.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	m_NPCSprite3.setTexture(m_NPCTexture3);
	m_NPCSprite3.setPosition(400.0f, 300.0f);
	m_NPCSprite3.setOrigin(m_NPCTexture3.getSize().x / 2, m_NPCTexture3.getSize().y / 2);
	m_NPCPosition3 = m_NPCSprite3.getPosition();

}

void NPC::kinematicWander()
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

void NPC::kinematicSeek()
{
}

void NPC::kinematicArrive()
{
}

void NPC::kinematicFlee()
{
}

void NPC::npcMove()
{
	if (m_magnitude > MAX_SPEED)
	{
		m_NPCVelocity = m_direction * MAX_SPEED;
	}

	m_NPCPosition = m_NPCPosition + m_NPCVelocity;
	m_NPCSprite.setPosition(m_NPCPosition);
}


