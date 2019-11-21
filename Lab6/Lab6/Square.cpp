#include "Square.h"

Square::Square(sf::RenderWindow& t_window) :m_window(t_window)
{
}

Square::~Square()
{
}

void Square::setSize(sf::Vector2f t_size)
{
	m_square.setFillColor(sf::Color(0, 0, 0, 0));
	m_square.setOutlineColor(sf::Color::Black);
	m_square.setOutlineThickness(1.2);
	m_square.setSize(t_size);
}

void Square::setPosition(sf::Vector2f t_position)
{
	m_square.setPosition(t_position);
}

void Square::setID(int t_ID)
{
	m_ID = t_ID;
}

void Square::render()
{
	m_window.draw(m_square);
}

sf::Vector2f Square::getSquarePosition()
{
	return m_square.getPosition();
}

sf::Vector2f Square::getSquareSize()
{
	return m_square.getSize();
}

int Square::getID()
{
	return m_ID;
}
