#include <iostream>
#include <ctime>
#include "DrawField.h"

//float DrawField::m_speed_figure = 0;

DrawField::DrawField() : BaseApp(80, 50)
{
	m_main_field_coord_x = 21;
	m_main_field_coord_y = 16;
	m_info_field_coord_x = m_main_field_coord_x + 6;
	m_info_field_coord_y = 6;
	m_obj_x = 10;
	m_obj_y = 1;
	m_speed_figure = 0.0f;
	getRandomFigure(m_obj_x, m_obj_y);
	nextSym = GetChar(m_obj_x, m_obj_y);
	currentSym = nextSym;
	srand(time(0));

	drawMainInfoField();
}
void DrawField::KeyPressed(int btnCode)
{
	m_btn_code = btnCode;
	if (m_btn_code == 75)			//left arrow key
		m_obj_x--;
	else if (m_btn_code == 77)		//right arrow key
		m_obj_x++;
	//else if (m_btn_code == 72)		//up arrow key
	else if (m_btn_code == 80)		//down arrow key
		m_obj_y++;
	m_btn_code = 0;
	if (m_obj_x <= 1)
		m_obj_x = 1;
	else if (m_obj_x >= m_main_field_coord_x)
		m_obj_x = m_main_field_coord_x - 1;
}

void DrawField::drawMainInfoField()
{
	for (int x = 0; x <= m_main_field_coord_x; x++) {
		for (int y = 0; y <= m_main_field_coord_y + 1; y++) {
			if ((x == 0 && y <= m_main_field_coord_y)
				|| (x == m_main_field_coord_x && y <= m_main_field_coord_y)
				|| (x <= m_main_field_coord_x && y == 0)
				|| (x <= m_main_field_coord_x && y == m_main_field_coord_y + 1))
				SetChar(x, y, '#');
			else
				SetChar(x, y, '.');
		}
	}
	for (int x = m_main_field_coord_x + 1; x <= m_info_field_coord_x; x++) {
		for (int y = 0; y <= m_info_field_coord_y; y++) {
			if ((x < m_info_field_coord_x && y == 0)
				|| (x == m_info_field_coord_x && y <= m_info_field_coord_y)
				|| (x < m_info_field_coord_x && y == m_info_field_coord_y))
				SetChar(x, y, '#');
			else
				SetChar(x, y, '.');
		}
	}
}

void DrawField::getRandomFigure(int xCoord, int yCoord)
{
	m_obj_x = xCoord;
	m_obj_y = yCoord;
	int s = 1 + rand() % 3;
	switch (s)
	{
	case 1:
		SetChar(m_obj_x, m_obj_y, L'=');
		break;
	case 2:
		SetChar(m_obj_x, m_obj_y, L'#');
		break;
	case 3:
		SetChar(m_obj_x, m_obj_y, L'$');
		break;
	}
	//return 0;
}

void DrawField::UpdateF(float deltaTime)
{
	m_speed_figure += deltaTime;
	if (m_speed_figure >= 0.5f) {
		KeyPressed(m_btn_code);
		SetChar(m_obj_x, m_obj_y, L'.');
		m_obj_y++;
		if (m_obj_y > m_main_field_coord_y)
		{
			m_obj_y = 1;
			currentSym = nextSym;
			getRandomFigure(m_obj_x, m_obj_y);
			nextSym = GetChar(m_obj_x, m_obj_y);
			SetChar(m_info_field_coord_x - 3 , m_info_field_coord_y - 3, nextSym);
		}

		SetChar(m_obj_x, m_obj_y, currentSym);		

		m_speed_figure = 0.0f;
	}
}


