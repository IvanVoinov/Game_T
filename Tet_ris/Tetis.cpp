#include "Tetis.h"


Tetis::Tetis() 
	: mfigure()
	, mfield(&mfigure)
	, m_Game(&mfield, &mfigure, this)
	, m_WaitTime(0.58)
{
	m_diffTime = 0.0f;
}

void Tetis::KeyPressed(int btnCode)
{
	if (btnCode == 75)							//left arrow key - move to the left
	{
		m_Game.moveLeft();
	}
	else if (btnCode == 77)						//right arrow key - move to the right
	{
		m_Game.moveRight();
	}
	else if (btnCode == 72)						//up key - change rotation
	{					
		m_Game.changeRotation();
	}
	else if (btnCode == 80)						//down key - move down
	{
		m_Game.keyDown();						
	}
	else if (btnCode == 32)						//space key - throw figure to the end of the board
	{
		m_Game.throwFigure();
	}
}

void Tetis::UpdateF(float deltaTime)
{
	if (m_diffTime >= m_WaitTime)
	{
		m_Game.figureMoveDown();
		m_diffTime = 0.0f;
		deltaTime = 0.0f;
	}
	m_diffTime += deltaTime;
	m_Game.drawScene();
}