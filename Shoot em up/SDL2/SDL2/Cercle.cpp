#include "Cercle.h"



void Cercle::Draw(SDL_Renderer* renderer)
{
	if (m_height < 2)
	{
		return;
	}
	float step = (2 * M_PI) / m_height;
	for (int i = 0; i <= m_height; ++i)
	{
		int x1 = m_width * cos(step * i) + m_x;
		int y1 = m_width * sin(step * i) + m_y;

		int x2 = m_width * cos(step * (i + 1)) + m_x;
		int y2 = m_width * sin(step * (i + 1)) + m_y;
		SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
	}
}