#pragma once
#include "Figure.h"

#define MAIN_FIELD_WIDHT 22
#define MAIN_FIELD_HEIGHT 16
#define INFO_FIELD_WIDHT 28
#define INFO_FIELD_HEIGHT 6
#define SHAPES_SYMBOLS 5
#define ROTATION 4

class Field
{
public:
	Field(Figure* paFigure);
	bool isFreePlace(int paX, int paY);
	bool isPossibleMove(int paX, int paY, int paBlock, int paRotation);
	void storeFigure(int paX, int paY, int paBlock, int paRotation);
	void deletePossibleLine();
	bool isGameOver();
private:
	enum {POS_FREE = 0, POS_FILLED};
	void initBoard();
	void deleteLine(int paY);
	Figure* pm_Figure;
	int m_Field[MAIN_FIELD_HEIGHT][MAIN_FIELD_WIDHT];
};
