#include <SDL.h>
#include <iostream>



void DrawHorizontalLine(SDL_Renderer* renderer, int x, int y, int length)
{
	SDL_SetRenderDrawColor(renderer,0 , 255, 0, 255);
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


void DrawLine(SDL_Renderer* renderer, int x1, int y1, int x2, int y2)
{
	int diffx = x2 - x1;
	int diffy = y2 - y1;

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

	if (diffx < 0)
	{
		for (int i = diffx; i != 0; ++i)
		{
			SDL_RenderDrawPoint(renderer, x1, y1);
		}
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

void DrawRectangle(SDL_Renderer* renderer, int x, int y, int width, int height)
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	SDL_RenderDrawLine(renderer, x, y, x + width, y);
	SDL_RenderDrawLine(renderer, x, y + height, x + width, y + height);
	SDL_RenderDrawLine(renderer, x, y, x, y + height);
	SDL_RenderDrawLine(renderer, x + width, y, x + width, y + height);
}


void DrawCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius, int precision) 
{
	if (precision < 2) 
	{
		return;
	}
	float angleStep = (2.0 * M_PI) / precision;

	for (int i = 0; i < precision; i++) 
	{
		float angle1 = i * angleStep;
		float angle2 = ((i + 1) % precision) * angleStep;

		int x1 = centerX + (int)(radius * cos(angle1));
		int y1 = centerY + (int)(radius * sin(angle1));

		int x2 = centerX + (int)(radius * cos(angle2));
		int y2 = centerY + (int)(radius * sin(angle2));

		SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
	}
}


void Draw(SDL_Renderer* renderer)
{
	DrawSquare(renderer, 20, 20, 100, 100);
	DrawHorizontalLine(renderer, 200, 300, 50);
	DrawVerticalLine(renderer, 500, 10, 50);
	DrawLine(renderer, 20, 300, 50, 150);
	DrawRectangle(renderer, 100, 300, 400, 100);
	DrawCircle(renderer, 150, 150, 100, 5000);
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

		SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);;


		if (!window)
		{
			std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
			SDL_Quit();
			return 1;
		}

	Draw(renderer);
	SDL_Delay(2000);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}