#pragma once
#include "BaseApp.h"
#include "Figure.h"
#include "Field.h"
#include "Game.h"

class Tetis : public BaseApp
{
public:
	Tetis();
	virtual void UpdateF(float deltaTime);
	virtual void KeyPressed(int btnCode);
private:
	Figure mfigure;
	Field mfield;
	Game m_Game;
	const float m_WaitTime;						//move speed figure
	float m_diffTime;
};
