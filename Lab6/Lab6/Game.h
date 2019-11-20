#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Square.h"
class Game
{
public:
	Game();
	~Game();
	void run();



private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void processClicks(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();

	void createGrid();
	void getSquareClicked();

	int m_gridWidth = 50;
	int m_gridHeight = 50;
	int m_gridSize = (m_gridHeight * m_gridWidth);

	std::vector<Square*> m_square;
	sf::RenderWindow m_window; // main SFML window
	bool m_exitGame; // control exiting game

};

#endif // !GAME_HPP