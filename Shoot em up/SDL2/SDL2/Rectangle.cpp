#include "Rectangle.h"

void Rectangle::Draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderDrawLine(renderer, x, y, x + width, y);
	SDL_RenderDrawLine(renderer, x, y + height, x + width, y + height);
	SDL_RenderDrawLine(renderer, x, y, x, y + height);
	SDL_RenderDrawLine(renderer, x + width, y, x + width, y + height);
}