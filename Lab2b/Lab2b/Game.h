#ifndef GAME_HPP
#define GAME_HPP  
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "NPC.h"

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

	Player player;
	NPC npc;
	NPC npc2;
	NPC npc3;

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	
	void move();
	void boundaryCheck(sf::Vector2f &pos);
	void setupSprites();
	
	sf::RenderWindow m_window; // main SFML window
	bool m_exitGame; // control exiting game
};

#endif // !GAME_HPP

