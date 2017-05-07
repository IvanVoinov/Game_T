#pragma once
#include "Figure.h"

#define MAIN_FIELD_WIDHT 22
#define MAIN_FIELD_HEIGHT 16
#define INFO_FIELD_WIDHT 28
#define INFO_FIELD_HEIGHT 6
#define SHAPES_SYMBOLS 5

class Field
{
public:
	Field(Figure* paFigure, int paScreenHeight);
	int getXPosition(int paPos);
	int getYPosition(int paPos);
	bool isFreePlace(int paX, int paY);
	bool isPossibleMove(int paX, int paY, int paBlock, int paRotation);
	void StoreFigure(int paX, int paY, int paBlock, int paRotation);
	void deletePossibleLine();
	bool isGameOver();

private:
	enum {POS_FREE, POS_FILLED};
	int m_Field[MAIN_FIELD_WIDHT][MAIN_FIELD_HEIGHT];
	Figure* m_Figure;
	int m_ScreenHeight;
	void initBoard();
	void deleteLine(int paY);
};
