#include <SFML/Graphics.hpp>
#include <iostream>
class NPC 
{
public:
	void setUpAssets();
	void kinematicWander();
	void kinematicSeek();
	void kinematicArrive();
	void kinematicFlee();
	void npcMove();

	sf::Texture m_NPCTexture;
	sf::Sprite m_NPCSprite;

	sf::Texture m_NPCTexture2;
	sf::Sprite m_NPCSprite2;

	sf::Texture m_NPCTexture3;
	sf::Sprite m_NPCSprite3;

	sf::Vector2f m_NPCPosition;
	sf::Vector2f m_NPCVelocity{ -6.0f, 0.0f };

	sf::Vector2f m_NPCPosition2;
	sf::Vector2f m_NPCVelocity2{ -6.0f, 0.0f };

	sf::Vector2f m_NPCPosition3;
	sf::Vector2f m_NPCVelocity3{ -6.0f, 0.0f };

private:
	float const MAX_SPEED{ 10.0f };

	float m_randomDirection;
	float m_magnitude;
	float m_rotation = { 0 };
	float m_maxRotation = { 0 };
	sf::Vector2f m_direction;
};
