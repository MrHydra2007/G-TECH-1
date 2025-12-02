#include "Cercle.h"



void Cercle::Draw(SDL_Renderer* renderer)
{
	if (height < 2)
	{
		return;
	}
	float step = (2 * M_PI) / height;
	for (int i = 0; i <= height; ++i)
	{
		int x1 = width * cos(step * i) + x;
		int y1 = width * sin(step * i) + y;

		int x2 = width * cos(step * (i + 1)) + x;
		int y2 = width * sin(step * (i + 1)) + y;
		SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
	}
}