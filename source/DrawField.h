#include <iostream>
#include "BaseApp.h"

class DrawField : public BaseApp
{
public:
	DrawField();

	virtual void UpdateF(float deltaTime);
	virtual void KeyPressed(int btnCode);

private:
	float m_speed_figure;
	wchar_t nextSym;
	wchar_t currentSym;
};