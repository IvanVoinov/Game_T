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
	int m_PosX, m_PosY;
	int m_Form, m_Rotation;
private:
	int m_NextPosX, m_NextPosY;
	int m_NextForm, m_NextRotation;
	Field* m_Field;
	Figure* m_Figure;
	BaseApp* pm_BaseApp;
	int getRandom(int paA, int paB);
	void initGame();
	void drawFigure(int paX, int paY, int paFigure, int paRotation);
	

};