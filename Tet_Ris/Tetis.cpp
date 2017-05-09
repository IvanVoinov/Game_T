#include "Tetis.h"



Tetis::Tetis() : m_WaitTime(0.3), pm_Game(0)
{
	//m_WaitTime = 0.3f;
	m_diffTime = 0.0f;
}

void Tetis::UpdateF(float deltaTime)
{
	m_diffTime += deltaTime;
	pm_Game->drawScene();
	if (m_diffTime >= m_WaitTime){ 
		pm_Game->drawScene();
	m_diffTime = 0.0f;
	deltaTime = 0.0f;
	}
		/*SetChar(m_obj_x, m_obj_y, L'.');
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
		m_diffTime = 0.0f;
	}*/
}

void Tetis::SetGame(Game* pGame)
{
	pm_Game = pGame;
}
