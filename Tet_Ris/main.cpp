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
	app.Run();
	system("pause");
	return 0;
}