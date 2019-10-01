#include <SFML/Graphics.hpp>
#include <iostream>
class NPC 
{
public:
	void setUpAssets();

	sf::Texture m_NPCTexture;
	sf::Sprite m_NPCSprite;

	sf::Vector2f m_NPCPosition;
	sf::Vector2f m_NPCVelocity{ -6.0f, 0.0f };

	float m_NPCSpeed{ -5.0f };

};
