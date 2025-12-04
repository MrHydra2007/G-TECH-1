#include <SDL.h>
#include "SDL_image.h"
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
	Image img(renderer, "C:/Users/icotvaquero/Documents/image.bmp");


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



/*
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"

		int main(int argc, char* argv[]) {
			if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
				std::cout << "Error SDL2 Initialization : " << SDL_GetError();
				return 1;
			}

			SDL_Window* window = SDL_CreateWindow("First program", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
			if (window == NULL) {
				std::cout << "Error window creation";
				return 3;
			}

			SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == NULL) {
				std::cout << "Error renderer creation";
				return 4;
			}

			SDL_Surface* lettuce_sur = IMG_Load("C:/Users/icotvaquero/Documents/image.bmp");
			if (lettuce_sur == NULL) {
				std::cout << "Error loading image: " << IMG_GetError();
				return 5;
			}

			SDL_Texture* lettuce_tex = SDL_CreateTextureFromSurface(renderer, lettuce_sur);
			if (lettuce_tex == NULL) {
				std::cout << "Error creating texture";
				return 6;
			}

			SDL_FreeSurface(lettuce_sur);

			while (true) {
				SDL_Event e;
				if (SDL_PollEvent(&e)) {
					if (e.type == SDL_QUIT) {
						break;
					}
				}

				SDL_RenderClear(renderer);
				SDL_RenderCopy(renderer, lettuce_tex, NULL, NULL);
				SDL_RenderPresent(renderer);
			}

			SDL_DestroyTexture(lettuce_tex);
			SDL_DestroyRenderer(renderer);
			SDL_DestroyWindow(window);
			SDL_Quit();

			return 0;
		}
		*/