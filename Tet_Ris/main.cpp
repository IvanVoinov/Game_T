#include "Tetis.h"
#include "Game.h"
#include "Figure.h"
#include "Field.h"
#include "expml.h"
int main()
{
	Figure mfigure;
	Field mfield(&mfigure);
	Tetis app;
	Game mGame(&mfield, &mfigure, &app);
	app.SetGame(&mGame);

	//mfield.m_Field[3][3] = 1;
	//mfield.m_Field[3][4] = 1;
	//mfield.m_Field[3][5] = 1;
	//bool b = mfield.isPossibleMove(20, 1, 0, 0);

	app.Run();
	system("pause");
	return 0;
}