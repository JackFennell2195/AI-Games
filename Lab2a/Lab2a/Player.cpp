#include "Player.h"
  
void Player::setUpAssets()
{
	if (!m_playerTexture.loadFromFile("ASSETS\\IMAGES\\player.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	m_playerSprite.setTexture(m_playerTexture);
	m_playerSprite.setPosition(250.0f, 250.0f);
	m_playerSprite.setOrigin(m_playerTexture.getSize().x / 2, m_playerTexture.getSize().y / 2);
	m_playerPosition = m_playerSprite.getPosition();
	
}
void Player::playerInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_magnitude = std::sqrt(std::pow(m_playerVelocity.x, 2) + std::pow(m_playerVelocity.y, 2));

		if (m_magnitude != 0)
		{
			m_direction = m_playerVelocity / m_magnitude;

		}
		else
		{
			m_direction = (sf::Vector2f(std::cos(m_rotation * 3.14159265358979323846 / 180), (std::sin(m_rotation * 3.14159265358979323846 / 180))));
		}

		m_playerVelocity += m_direction;
	}

	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_playerVelocity *= 0.8f;
		if (m_magnitude < 0)
		{
			m_playerVelocity = sf::Vector2f(0, 0);
		}
		
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&& !(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)))
	{
		m_rotation -= 1.0f;
		m_playerSprite.setRotation(m_rotation);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)))
	{
		m_rotation += 1.0f;
		m_playerSprite.setRotation(m_rotation);
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
	{
		m_magnitude = std::sqrt(std::pow(m_playerVelocity.x, 2) + std::pow(m_playerVelocity.y, 2));
		m_playerVelocity = m_magnitude * (sf::Vector2f(std::cos(m_rotation * 3.14159265358979323846 / 180), (std::sin(m_rotation * 3.14159265358979323846 / 180))));
	}

	
}

void Player::playerMove()
{
	if (m_magnitude > MAX_SPEED)
	{
		m_playerVelocity = m_direction * MAX_SPEED;
	} 

	m_playerPosition = m_playerPosition + m_playerVelocity;
	m_playerSprite.setPosition(m_playerPosition);
}
