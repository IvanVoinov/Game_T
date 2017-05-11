#include "Game.h"

Game::Game(Field* paField, Figure* paFigure, BaseApp* paBaseApp)
	: m_PosX(0)
	, m_PosY(0)
	, m_Form(0)
	, m_Rotation(0)
	, m_NextPosX(0)
	, m_NextPosY(0)
	, m_NextForm(0)
	, m_NextRotation(0)
{
	pm_BaseApp = paBaseApp;
	pm_Field = paField;
	pm_Figure = paFigure;
	initGame();
}

void Game::initGame()
{
	srand(time(0));
	m_Form = getRandom(0, 6);
	m_Rotation = getRandom(0, 3);
	m_PosX = (MAIN_FIELD_WIDHT / 2) + pm_Figure->getXStartPosition(m_Form, m_Rotation);
	m_PosY = pm_Figure->getYStartPosition(m_Form, m_Rotation);
	m_NextForm = getRandom(0, 6);
	m_NextRotation = getRandom(0, 3);
	m_NextPosX = INFO_FIELD_WIDHT - 6;
	m_NextPosY = INFO_FIELD_HEIGHT - 5;
}

void Game::figureMoveDown()
{
	if (pm_Field->isPossibleMove(m_PosX, m_PosY + 1, m_Form, m_Rotation)) 
	{
		m_PosY++;
		pm_Field->deletePossibleLine();
		drawBoard();
		drawFigure(m_PosX, m_PosY, m_Form, m_Rotation);
	}
	else 
	{
		pm_Field->storeFigure(m_PosX, m_PosY, m_Form, m_Rotation);
		pm_Field->deletePossibleLine();
		m_Form = m_NextForm;
		m_Rotation = m_NextRotation;
		m_PosX = (MAIN_FIELD_WIDHT / 2) + pm_Figure->getXStartPosition(m_Form, m_Rotation);
		m_PosY = pm_Figure->getYStartPosition(m_Form, m_Rotation);
		m_NextForm = getRandom(0, 6);
		m_NextRotation = getRandom(0, 3);
		if (!pm_Field->isPossibleMove(m_PosX, m_PosY, m_Form, m_Rotation))
		{
			exit(0);
		}
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
	for (int x = 0; x < SHAPES_SYMBOLS; x++) 
	{
		for (int y = 0; y < SHAPES_SYMBOLS; y++) 
		{
			if (pm_Figure->getFigureType(paFigure, paRotation, y, x) != 0)
				pm_BaseApp->SetChar(y + paX, x + paY, '*');
		}
	}
}

void Game::drawBoard()
{
	for (int x = 0; x < MAIN_FIELD_WIDHT; x++) 
	{
		for (int y = 0; y < MAIN_FIELD_HEIGHT; y++) 
		{
			if (!pm_Field->isFreePlace(x, y))
				pm_BaseApp->SetChar(x, y, '*');
			else
				pm_BaseApp->SetChar(x, y, '.');
		}
	}
	for (int x = 0; x < MAIN_FIELD_WIDHT; x++) 
	{
		for (int y = 0; y < MAIN_FIELD_HEIGHT; y++) 
		{
			if (x == 0 || x == MAIN_FIELD_WIDHT - 1 || y == 0 || y == MAIN_FIELD_HEIGHT - 1)
				pm_BaseApp->SetChar(x, y, '#');
		}
	}
	for (int x = MAIN_FIELD_WIDHT; x < INFO_FIELD_WIDHT; x++) 
	{
		for (int y = 0; y <= INFO_FIELD_HEIGHT; y++) 
		{
			if (x < INFO_FIELD_WIDHT && y == 0 || x == INFO_FIELD_WIDHT - 1 || y == INFO_FIELD_HEIGHT)
				pm_BaseApp->SetChar(x, y, '#');
			else
				pm_BaseApp->SetChar(x, y, '.');
	}
}
}

void Game::moveLeft()
{
	if (pm_Field->isPossibleMove(m_PosX - 1, m_PosY, m_Form, m_Rotation)) 
	{
		m_PosX--;
		drawFigure(m_PosX, m_PosY, m_Form, m_Rotation);
	}
}
void Game::moveRight()
{
	if (pm_Field->isPossibleMove(m_PosX + 1, m_PosY, m_Form, m_Rotation)) 
	{
		m_PosX++;
		drawFigure(m_PosX, m_PosY, m_Form, m_Rotation);
	}
}

void Game::changeRotation()
{
	int newRotation = (m_Rotation + 1) % ROTATION;
	if (pm_Field->isPossibleMove(m_PosX, m_PosY, m_Form, newRotation)) 
	{
		m_Rotation = newRotation;
		drawFigure(m_PosX, m_PosY, m_Form, m_Rotation);
	}
}
void Game::keyDown()
{
	if (pm_Field->isPossibleMove(m_PosX, m_PosY + 1, m_Form, m_Rotation)) 
	{
		m_PosY++;
		drawFigure(m_PosX, m_PosY, m_Form, m_Rotation);
	}
}

void Game::throwFigure()
{
	while (pm_Field->isPossibleMove(m_PosX, m_PosY + 1, m_Form, m_Rotation))
	{
		m_PosY++;
		drawFigure(m_PosX, m_PosY, m_Form, m_Rotation);
	}
	
}
