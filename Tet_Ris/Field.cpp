#include "Field.h"

//need to fix problem with SetChar metod


Field::Field(Figure* paFigure)
{
	m_Figure = paFigure;
	initBoard();
}

bool Field::isFreePlace(int paX, int paY)
{ 
 	if ((paX >= 0 && paX < MAIN_FIELD_WIDHT) || (paY >= 0 && paY < MAIN_FIELD_HEIGHT)){
		if (m_Field[paY][paX] == POS_FREE)
			return true;
		else
			return false;
	}
	return false;
}

bool Field::isPossibleMove(int paX, int paY, int paBlock, int paRotation)
{
	for (int i = 0; i < SHAPES_SYMBOLS; i++){
		for (int j = 0; j < SHAPES_SYMBOLS; j++){
			if (m_Figure->getFigureType(paBlock, paRotation, j, i) != 0){
				if (!(isFreePlace(paX + j, paY + i))) {
					return false;
				}
			}
		}
	}
	return true;
}

void Field::StoreFigure(int paX, int paY, int paBlock, int paRotation)
{
	for (int x = 0; x < SHAPES_SYMBOLS; x++){
		for (int y = 0; y < SHAPES_SYMBOLS; y++){
			if (m_Figure->getFigureType(paBlock, paRotation, x, y) != 0){
				m_Field[paY + y][paX + x] = POS_FILLED;
			}
		}
	}

}

void Field::deletePossibleLine()
{
	for (int j = 0; j < MAIN_FIELD_HEIGHT; j++){
		int i = 0;
		while (i < MAIN_FIELD_WIDHT){
			if (m_Field[i][j] != POS_FILLED)
				break;
			i++;
		}
		if (i == MAIN_FIELD_WIDHT) deleteLine(j);
	}
}

bool Field::isGameOver()
{
	for (int i = 0; i < MAIN_FIELD_WIDHT; i++){
		if (m_Field[i][0] == POS_FILLED)
			return true;
	}
	return false;
}

void Field::initBoard()
{
	for(int x = 0; x < MAIN_FIELD_WIDHT; x++){
		for (int y = 0; y < MAIN_FIELD_HEIGHT; y++){
			if ((x == 0) || (x == MAIN_FIELD_WIDHT -1)
				|| (y == 0) || (y == MAIN_FIELD_HEIGHT -1)) {
				m_Field[y][x] = POS_FILLED;
			}
			else {
				m_Field[y][x] = POS_FREE;
			}
		}
	}
}

void Field::deleteLine(int paY)
{
	for (int j = paY; j > 0; j--){
		for (int i = 0; i < MAIN_FIELD_WIDHT; i++){
			m_Field[i][j] = m_Field[i][j-1];
		}
	}
}
