#include <SDL.h>
#include "Rectangle.h"
#include "Geometry.h"
#include "Cercle.h"
#include <iostream>

Rectangle rect = Rectangle(150, 100, 200, 100);
Cercle cercle = Cercle(250, 200, 100, 25);

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

void Draw(SDL_Renderer* renderer)
{
	//DrawSquare(renderer, 20, 20, 100, 100);
	//DrawHorizontalLine(renderer, 200, 300, 50);
	//DrawVerticalLine(renderer, 500, 10, 50);
	//DrawLine(renderer, 20, 300, 50, 150);
	rect.Draw(renderer);
	cercle.Draw(renderer);

	SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("SDL", 100, 100, 640, 480, SDL_WINDOW_RESIZABLE);
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

	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
		}
		Draw(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}