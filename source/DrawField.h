#include <iostream>
#include "BaseApp.h"

class DrawField : public BaseApp
{
public:
	DrawField();
	void drawMainInfoField();
	virtual void UpdateF(float deltaTime);
	virtual void KeyPressed(int btnCode);
	void getRandomFigure(int xCoord, int yCoord);
private:
	int m_main_field_coord_x;
	int m_main_field_coord_y;
	int m_info_field_coord_x;
	int m_info_field_coord_y;
	int m_obj_x;
	int m_obj_y;
	int m_btn_code;
	float m_speed_figure;
	wchar_t nextSym;
	wchar_t currentSym;
};