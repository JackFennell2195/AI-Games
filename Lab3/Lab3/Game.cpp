#include "Game.h"
#include <iostream>


/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 2200U, 1800U, 32U }, "Lab 3" },
	m_exitGame{false} //when true game will exit
{
	setupSprites(); // load texture
}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
Game::~Game()
{
}


/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
	}
}


/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
	move();
	boundaryCheck(player.m_playerPosition);
	boundaryCheck(npc.m_NPCPosition);
	boundaryCheck(npc2.m_NPCPosition2);
	boundaryCheck(npc3.m_NPCPosition3);
	boundaryCheck(npc4.m_NPCPosition4);
	boundaryCheck(npc5.m_NPCPosition5);
	player.playerInput(); 
}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear();
	m_window.draw(player.m_playerSprite);
	m_window.draw(npc.m_NPCSprite);
	m_window.draw(npc2.m_NPCSprite2);
	m_window.draw(npc3.m_NPCSprite3);
	m_window.draw(npc4.m_NPCSprite4);
	m_window.draw(npc5.m_NPCSprite5);
	m_window.display();
}

void Game::move()
{
	player.playerMove();
	
	npc.npcMove();
	npc2.npcMove();
	npc3.npcMove();
	npc4.npcMove();
	npc5.npcMove();

	npc.dynamicWander();
	npc2.dynamicSeek(player.m_playerPosition);
	npc3.dynamicFlee(player.m_playerPosition);
}

void Game::boundaryCheck(sf::Vector2f& pos)
{
	if (pos.x+250 < 0)
	{
		pos.x = m_window.getSize().x;
	}
	if (pos.x > 2200)
	{
		pos.x = -250;
	}
	if (pos.y + 250 < 0)
	{
		pos.y = m_window.getSize().y;
	}
	if (pos.y > 1800)
	{
		pos.y = -250;
	}

}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprites()
{
	player.setUpAssets();
	npc.setUpAssets();
	npc2.setUpAssets();
	npc3.setUpAssets();
	npc4.setUpAssets();
	npc5.setUpAssets();
}


