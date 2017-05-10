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
	if (btnCode == 75)							//left arrow key
	{
		m_Game.moveLeft();
	}
	else if (btnCode == 77)						//right arrow key
	{
		m_Game.moveRight();
	}
	else if (btnCode == 72){					//up key - rotation
		m_Game.changeRotation();
	}
	else if (btnCode == 80)
	{
		m_Game.keyDown();
	}
	else if (btnCode == 32)
	{
		m_Game.throwFigure();
	}
}

void Tetis::UpdateF(float deltaTime)
{
	if (m_diffTime >= m_WaitTime){
		m_Game.figureMoveDown();
		m_diffTime = 0.0f;
		deltaTime = 0.0f;
	}
	m_diffTime += deltaTime;
	m_Game.drawScene();
}