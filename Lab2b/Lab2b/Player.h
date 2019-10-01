#include <SFML/Graphics.hpp>
#include <iostream>
class Player
{
public:
	void setUpAssets();
	void playerInput();
	void playerMove();

	sf::Texture m_playerTexture; // texture used for Player 
	sf::Sprite m_playerSprite; // sprite used for Player 

	sf::Vector2f m_playerPosition;
	sf::Vector2f m_playerVelocity{ 5.0f, 0.0f };


private:

	float const MAX_SPEED{ 15.0f };
	float m_magnitude;
	float m_rotation = {0};
	sf::Vector2f m_direction;


};
