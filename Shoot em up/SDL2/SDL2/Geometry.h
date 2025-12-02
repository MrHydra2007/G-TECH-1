#pragma once
#include <SDL.h>
class Geometry
{
protected:
	int x;
	int y;
	int width;
	int height;

public:
	Geometry(int x, int y, int width, int height);
	~Geometry() = default;

	virtual void Draw(SDL_Renderer* renderer) = 0;
};

