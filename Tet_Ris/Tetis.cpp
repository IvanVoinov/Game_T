#include "Tetis.h"


void Tetis::KeyPressed(int btnCode)
{
	if (btnCode == 75)							//left arrow key
	{
		pm_Game->moveLeft();
	}
	else if (btnCode == 77)						//right arrow key
	{
		pm_Game->moveRight();
	}
	else if (btnCode == 72){					//up key - rotation
		pm_Game->changeRotation();
	}
}

Tetis::Tetis() : m_WaitTime(0.58), pm_Game(0)
{
	m_diffTime = 0.0f;
}

void Tetis::UpdateF(float deltaTime)
{
	if (m_diffTime >= m_WaitTime){
		pm_Game->figureMoveDown();
		m_diffTime = 0.0f;
		deltaTime = 0.0f;
	}
	m_diffTime += deltaTime;
	pm_Game->drawScene();
}

void Tetis::SetGame(Game* pGame)
{
	pm_Game = pGame;
}
