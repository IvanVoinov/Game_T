#include "Field.h"


Field::Field(Figure* paFigure)
{
	pm_Figure = paFigure;
	initBoard();
}

bool Field::isFreePlace(int paX, int paY)
{ 
 	if ((paX >= 0 && paX < MAIN_FIELD_WIDHT) || (paY >= 0 && paY < MAIN_FIELD_HEIGHT))
	{
		if (m_Field[paY][paX] == POS_FREE)
			return true;
		else
			return false;
	}
	return false;
}

bool Field::isPossibleMove(int paX, int paY, int paBlock, int paRotation)
{
	for (int x = 0; x < SHAPES_SYMBOLS; x++)
	{
   		for (int y = 0; y < SHAPES_SYMBOLS; y++)
		{
			if (pm_Figure->getFigureType(paBlock, paRotation, y, x) != 0)
			{
				if (!(isFreePlace(paX + y, paY + x))) 
				{
					return false;
				}
			}
		}
	}
	return true;
}

void Field::storeFigure(int paX, int paY, int paBlock, int paRotation)
{
	for (int x = 0; x < SHAPES_SYMBOLS; x++)
	{
		for (int y = 0; y < SHAPES_SYMBOLS; y++)
		{
			if (pm_Figure->getFigureType(paBlock, paRotation, x, y) != 0)
			{
				m_Field[paY + y][paX + x] = POS_FILLED;
			}
		}
	}

}

void Field::deletePossibleLine()
{
	for (int y = 1; y < MAIN_FIELD_HEIGHT - 1; y++)
	{
		int x = 0;
		while (x < MAIN_FIELD_WIDHT - 1)
		{
			if (m_Field[y][x] != POS_FILLED)
				break;
			x++;
		}
		if (x == MAIN_FIELD_WIDHT - 1) 
			deleteLine(y);
	}
}


void Field::initBoard()
{
	for(int x = 0; x < MAIN_FIELD_WIDHT; x++)
	{
		for (int y = 0; y < MAIN_FIELD_HEIGHT; y++)
		{
			if ((x == 0) || (x == MAIN_FIELD_WIDHT - 1)
				|| (y == 0) || (y == MAIN_FIELD_HEIGHT - 1)) 
			{
				m_Field[y][x] = POS_FILLED;
			}
			else 
			{
				m_Field[y][x] = POS_FREE;
			}
		}
	}
}

void Field::deleteLine(int line)
{
	for (int y = line; y > 1; y--)
	{
		for (int x = 1; x < MAIN_FIELD_WIDHT - 1; x++)
		{
			m_Field[y][x] = m_Field[y - 1][x];
		}
	}
}
