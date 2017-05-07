#include "Field.h"


Field::Field(Figure* paFigure, int paScreenHeight)
{
	m_ScreenHeight = paScreenHeight;
	m_Figure = paFigure;
	initBoard();
}

int Field::getXPosition(int paPos)
{
	return MAIN_FIELD_WIDHT/2 + paPos;
}

int Field::getYPosition(int paPos)
{
	return MAIN_FIELD_HEIGHT + paPos;
}

bool Field::isFreePlace(int paX, int paY)
{
	if (m_Field[paX][paY] == POS_FREE)
		return true;
	else
		return false;
}

bool Field::isPossibleMove(int paX, int paY, int paBlock, int paRotation)
{
	for (int i1 = paX, i2 = 0; i1 < paX + SHAPES_SYMBOLS; i1++, i2++){
		for (int j1 = paY, j2 = 0; j1 < paY + SHAPES_SYMBOLS; j1++; j2++){
			if (i1 < 0 
				|| i1 > MAIN_FIELD_WIDHT - 1 
				|| j1 > MAIN_FIELD_HEIGHT - 1){
				if (m_Figure->getFigureType(paBlock, paRotation, j2, i2) != 0)
						return 0;
			}
			if (j1 >= 0){
				if ((m_Figure->getFigureType(paBlock, paRotation, j2, i2) != 0)
					&& (!isFreePlace(i1, j1)))
					return false;
			}
		}
	}
	return true;
}

void Field::StoreFigure(int paX, int paY, int paBlock, int paRotation)
{
	for (int i1 = paX, i2 = 0; i1 < paX + SHAPES_SYMBOLS; i1++, i2++){
		for (int j1 = paY, j2 = 0; j1 < paY + SHAPES_SYMBOLS; j1++, j2++){
			if(m_Figure->getFigureType(paBlock, paRotation, j2, i2) != 0)
				m_Figure[i1][j1] = POS_FILLED;
		}
	}
}

void Field::deletePossibleLine()
{
	for (int j = 0; j < MAIN_FIELD_HEIGHT; j++){
		int i = 0;
		while (i < MAIN_FIELD_WIDHT){
			if (m_Figure[i][j] != POS_FILLED)
				break;
			i++;
		}
		if (i == MAIN_FIELD_WIDHT) deleteLine(j);
	}
}

bool Field::isGameOver()
{
	for (int i = 0; i < MAIN_FIELD_WIDHT; i++){
		if (m_Figure[i][0] == POS_FILLED)
			return true;
	}
	return false;
}

void Field::initBoard()
{
	for (int x = 0; x <= MAIN_FIELD_WIDHT; x++) {
		for (int y = 0; y <= MAIN_FIELD_HEIGHT + 1; y++) {
			if ((x == 0 && y <= MAIN_FIELD_HEIGHT)
				|| (x == MAIN_FIELD_WIDHT && y <= MAIN_FIELD_HEIGHT)
				|| (x <= MAIN_FIELD_WIDHT && y == 0)
				|| (x <= MAIN_FIELD_WIDHT && y == MAIN_FIELD_HEIGHT + 1))
				SetChar(x, y, '#');
			else
				m_Field[x][y] = POS_FREE;
		}
	}
	for (int x = MAIN_FIELD_WIDHT + 1; x <= INFO_FIELD_WIDHT; x++) {
		for (int y = 0; y <= INFO_FIELD_HEIGHT; y++) {
			if ((x < INFO_FIELD_WIDHT && y == 0)
				|| (x == INFO_FIELD_WIDHT && y <= INFO_FIELD_HEIGHT)
				|| (x < INFO_FIELD_WIDHT && y == INFO_FIELD_HEIGHT))
				SetChar(x, y, '#');
			else
				m_Field[x][y] = POS_FREE;
		}
	}
}

void Field::deleteLine(int paY)
{
	for (int j = paY; j > 0; j--){
		for (int i = 0; i < MAIN_FIELD_WIDHT; i++){
			m_Figure[i][j] = m_Figure[i][j-1];
		}
	}
}
