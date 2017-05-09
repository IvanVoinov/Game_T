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
	virtual void KeyPressed(int btnCode){};
	void SetGame(Game* pGame);
private:
	Game* pm_Game;
	const float m_WaitTime;
	float m_diffTime;
};
