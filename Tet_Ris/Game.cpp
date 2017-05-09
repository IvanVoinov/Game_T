#include "Game.h"

Game::Game(Field *pField, Figure* pFigure, BaseApp* pBaseApp)
: m_PosX(0)
, m_PosY(0)
, m_Form(0)
, m_Rotation(0)
, m_NextPosX(0)
, m_NextPosY(0)
, m_NextForm(0)
, m_NextRotation(0)
{
	pm_BaseApp = pBaseApp;
	pm_Field = pField;
	m_Figure = pFigure;
	initGame();
}

void Game::initGame()
{
	srand((unsigned int)time(0));
	m_Form = getRandom(0, 6);
	m_Rotation = getRandom(0, 3);
	m_PosX = (MAIN_FIELD_WIDHT / 2) + m_Figure->getXStartPosition(m_Form, m_Rotation);
	m_PosY = m_Figure->getYStartPosition(m_Form, m_Rotation);
	m_NextForm = getRandom(0, 6);
	m_NextRotation = getRandom(0, 3);
	m_NextPosX = INFO_FIELD_WIDHT - 3;
	m_NextPosY = INFO_FIELD_HEIGHT - 3;
}

void Game::figureMoveDown()
{
	if (pm_Field->isPossibleMove(m_PosX, m_PosY + 1, m_Form, m_Rotation)){
		m_PosY ++;
		drawFigure(m_PosX, m_PosY, m_Form, m_Rotation);
	}
	else {
		pm_Field->StoreFigure(m_PosX, m_PosY, m_Form, m_Rotation);
		m_Form = m_NextForm;
		m_Rotation = m_NextRotation;
		m_PosX = (MAIN_FIELD_WIDHT / 2) + m_Figure->getXStartPosition(m_Form, m_Rotation);
		m_PosY = m_Figure->getYStartPosition(m_Form, m_Rotation);
		m_NextForm = getRandom(0, 6);
		m_NextRotation = getRandom(0, 3);
	}

}
void Game::drawScene()
{
	drawBoard();
	drawFigure(m_PosX, m_PosY, m_Form, m_Rotation);
	drawFigure(m_NextPosX, m_NextPosY, m_NextForm, m_NextRotation);
}

void Game::createNewFigure()
{
	m_Form = m_NextForm;
	m_Rotation = m_NextRotation;
	m_PosX = m_NextPosX;
	m_PosY = m_NextPosY;
	m_NextForm = getRandom(0, 6);
	m_NextRotation = getRandom(0, 3);
}

int Game::getRandom(int paA, int paB)
{
	return rand() % (paB - paA + 1) + paA;
}

void Game::drawFigure(int paX, int paY, int paFigure, int paRotation)
{
	for (int i = 0; i < SHAPES_SYMBOLS; i++){
		for (int j = 0; j < SHAPES_SYMBOLS; j++){
			if (m_Figure->getFigureType(paFigure, paRotation, j, i) != 0)
				pm_BaseApp->SetChar(j + paX, i + paY, '*');
		}
	}
}

void Game::drawBoard()
{
	for (int x = 0; x < MAIN_FIELD_WIDHT; x++){
		for (int y = 0; y < MAIN_FIELD_HEIGHT; y++){
			if (!pm_Field->isFreePlace(x, y))
				pm_BaseApp->SetChar(x, y, '*');
			else
				pm_BaseApp->SetChar(x, y, '.');
		}
	}
	for (int x = 0; x < MAIN_FIELD_WIDHT; x++) {
		for (int y = 0; y < MAIN_FIELD_HEIGHT; y++) {
			if ((x == 0)
				|| (x == MAIN_FIELD_WIDHT - 1)
				|| (y == 0)
				|| (y == MAIN_FIELD_HEIGHT - 1))
				pm_BaseApp->SetChar(x, y, '#');
		}
	}
	for (int x = MAIN_FIELD_WIDHT + 1; x <= INFO_FIELD_WIDHT; x++) {
		for (int y = 0; y <= INFO_FIELD_HEIGHT; y++) {
			if ((x < INFO_FIELD_WIDHT && y == 0)
				|| (x == INFO_FIELD_WIDHT && y <= INFO_FIELD_HEIGHT)
				|| (x < INFO_FIELD_WIDHT && y == INFO_FIELD_HEIGHT))
				pm_BaseApp->SetChar(x, y, '#');
		}
	}
}

void Game::moveLeft()
{
	if(pm_Field->isPossibleMove(m_PosX - 1, m_PosY, m_Form, m_Rotation)){
		m_PosX--;
		drawFigure(m_PosX, m_PosY, m_Form, m_Rotation);
	}
}
void Game::moveRight()
{
	if(pm_Field->isPossibleMove(m_PosX + 1, m_PosY, m_Form, m_Rotation)){
		m_PosX++;
		drawFigure(m_PosX, m_PosY, m_Form, m_Rotation);
	}
}

void Game::changeRotation()
{
	int newRotation = (m_Rotation + 1) % 4; // constant
	if(pm_Field->isPossibleMove(m_PosX, m_PosY, m_Form, newRotation)) {
		m_Rotation = newRotation;
		drawFigure(m_PosX, m_PosY, m_Form, m_Rotation);
	}
}
void Game::keyDown(){}