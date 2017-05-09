#include "expml.h"

expml::expml() : BaseApp(100, 80)
{

}

void expml::drawBoard()
{
	for (int x = 0; x <= 22; x++) {
		for (int y = 0; y <= 16 + 1; y++) {
			if ((x == 0 && y <= 16)
				|| (x == 22 && y <= 16)
				|| (x <= 22 && y == 0)
				|| (x <= 22 && y == 16 + 1))
				SetChar(x, y, '#');
			else
				SetChar(x, y, '.');
		}
	}
	for (int x = 22 + 1; x <= 28; x++) {
		for (int y = 0; y <= 6; y++) {
			if ((x < 28 && y == 0)
				|| (x == 28 && y <= 6)
				|| (x < 28 && y == 6))
				SetChar(x, y, '#');
		}
	}
	/*for (int x = 0; x < 22; x++){
		for (int y = 0; y < 16; y++){
			if (!m_Field->isFreePlace(x, y))
				SetChar(x, y, '*');
		}
	}*/
}