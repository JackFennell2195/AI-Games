#pragma once
#include <SFML/Graphics.hpp>

class Square
{
public:
	Square(sf::RenderWindow& t_window);
	~Square();

	void setSize(sf::Vector2f t_size);
	void setPosition(sf::Vector2f t_position);
	void setID(int t_ID);
	void render();

	sf::Vector2f getSquarePosition();
	sf::Vector2f getSquareSize();
	int getID();

private:
	sf::RenderWindow& m_window;
	sf::RectangleShape m_square;
	int m_ID;
};
