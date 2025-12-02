#include "Cercle.h"



void Cercle::Draw(SDL_Renderer* renderer, float centerX, float centerY, float radius, float precision)
{
	if (precision < 2)
	{
		return;
	}
	float step = (2 * M_PI) / precision;
	for (int i = 0; i <= precision; ++i)
	{
		int x1 = radius * cos(step * i) + centerX;
		int y1 = radius * sin(step * i) + centerY;

		int x2 = radius * cos(step * (i + 1)) + centerX;
		int y2 = radius * sin(step * (i + 1)) + centerY;
		SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
	}
}