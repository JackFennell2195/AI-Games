#include <SFML/Graphics.hpp>
#include <iostream>
class NPC 
{
public:
	void setUpAssets();
	void dynamicWander();
	void dynamicSeek(sf::Vector2f& pos);
	void dynamicArrive(sf::Vector2f& pos);
	void dynamicFlee(sf::Vector2f& pos);
	void dynamicPursue(sf::Vector2f& pos);
	void npcMove();

	sf::Texture m_NPCTexture;
	sf::Sprite m_NPCSprite;

	sf::Texture m_NPCTexture2;
	sf::Sprite m_NPCSprite2;

	sf::Texture m_NPCTexture3;
	sf::Sprite m_NPCSprite3;

	sf::Texture m_NPCTexture4;
	sf::Sprite m_NPCSprite4;

	sf::Texture m_NPCTexture5;
	sf::Sprite m_NPCSprite5;

	sf::Vector2f m_NPCPosition;
	sf::Vector2f m_NPCVelocity{ -6.0f, 0.0f };

	sf::Vector2f m_NPCPosition2;
	sf::Vector2f m_NPCVelocity2{ -6.0f, 0.0f };

	sf::Vector2f m_NPCPosition3;
	sf::Vector2f m_NPCVelocity3{ -6.0f, 0.0f };

	sf::Vector2f m_NPCPosition4;
	sf::Vector2f m_NPCVelocity4{ -6.0f, 0.0f };

	sf::Vector2f m_NPCPosition5;
	sf::Vector2f m_NPCVelocity5{ -6.0f, 0.0f };

private:
	float const MAX_SPEED{ 10.0f };

	float m_randomDirection;
	float m_magnitude;
	float m_distance;
	float m_arrivalRadius{ 260.0f };
	float m_rotation = { 0 };
	float m_maxRotation = { 0 };
	sf::Vector2f m_direction;
};
