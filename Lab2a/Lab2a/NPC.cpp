#include "NPC.h"

void NPC::setUpAssets()
{

	if (!m_NPCTexture.loadFromFile("ASSETS\\IMAGES\\NPC.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	m_NPCSprite.setTexture(m_NPCTexture);
	m_NPCSprite.setPosition(800.0f, 600.0f);

	m_NPCPosition = m_NPCSprite.getPosition();
}
