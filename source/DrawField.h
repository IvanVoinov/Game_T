#include <iostream>
#include "BaseApp.h"

class DrawField : public BaseApp
{
public:
	DrawField();
	void drawMainInfoField();
	void rand_symbols(int mX, int mY);
	virtual void UpdateF(float deltaTime);
private:
	bool m_direction;
	int m_main_field_coord_x;
	int m_main_field_coord_y;
	int m_info_field_coord_x;
	int m_info_field_coord_y;
	int m_obj_x;
	int m_obj_y;
};
