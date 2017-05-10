#pragma once
#include "Figure.h"
#include "Field.h"
#include "BaseApp.h"
#include <ctime>

class Game
{
public:
	Game(Field *pField, Figure* pFigure, BaseApp* pBaseApp);
	void drawScene();
	void createNewFigure();
	void drawBoard();
	void figureMoveDown();
	void moveLeft();
	void moveRight();
	void changeRotation();
	void keyDown();
	void throwFigure();
private:
	int m_PosX, m_PosY;
	int m_Form, m_Rotation;
	int m_NextPosX, m_NextPosY;
	int m_NextForm, m_NextRotation;
	Field* pm_Field;
	BaseApp* pm_BaseApp;
	Figure* m_Figure;
	int getRandom(int paA, int paB);
	void initGame();
	void drawFigure(int paX, int paY, int paFigure, int paRotation);
	

};