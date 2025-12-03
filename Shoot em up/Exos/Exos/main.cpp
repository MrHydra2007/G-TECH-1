#include <SDL.h>
#include "Rectangle.h"
#include "Geometry.h"
#include "Cercle.h"
#include <iostream>
#include "Image.h"

void DrawHorizontalLine(SDL_Renderer* renderer, int x, int y, int length)
{
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	for (int i = 0; i < length; ++i)
	{
		SDL_RenderDrawPoint(renderer, x + i, y);
	}
}

void DrawVerticalLine(SDL_Renderer* renderer, int x, int y, int length)
{
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	for (int i = 0; i < length; ++i)
	{
		SDL_RenderDrawPoint(renderer, x, y + i);
	}
}

void DrawLine(SDL_Renderer* renderer, float x1, float y1, float x2, float y2)
{
	float diffx = x2 - x1;
	float diffy = y2 - y1;

	int distx = abs(diffx);
	int disty = abs(diffy);

	int max = std::max(distx, disty);

	float stepX = diffx / (float)max;
	float stepY = diffy / (float)max;

	float x = 1;
	float y = 1;

	for (int i = 0; i < max; ++i)
	{
		SDL_RenderDrawPoint(renderer, x, y);
		x += stepX;
		y += stepY;
	}
}

void DrawSquare(SDL_Renderer* renderer, int x1, int y1, int x2, int y2)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	for (int i = x1; i < x2; ++i)
	{
		for (int p = y1; p < y2; ++p)
		{
			SDL_RenderDrawPoint(renderer, i, p);
		}
	}
}

int main(int argc, char* argv[])
{

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("SDL", 100, 100, 801, 801, SDL_WINDOW_RESIZABLE);
	if (!window)
	{
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer)
	{
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}

	bool running = true;
	SDL_Event event;

	Rectangle rect = Rectangle(0, 0, 100, 60);
	Image img(renderer, "");


	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

	

		rect.SetPosition(0, 0, 0.f, 0.f);
		rect.Draw(renderer);
		rect.SetPosition(800, 0, 1.f, 0.f);
		rect.Draw(renderer);
		rect.SetPosition(800, 800, 1.f, 1.f);
		rect.Draw(renderer);
		rect.SetPosition(0, 800, 0.f, 1.f);
		rect.Draw(renderer);
		rect.SetPosition(400, 400, 0.5f, 0.5f);
		rect.Draw(renderer);

		img.SetPosition(0, 0, 0.f, 0.f);
		img.Draw(renderer);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}