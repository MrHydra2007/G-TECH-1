#pragma once
#include "Geometry.h"

class Cercle : public Geometry
{
public:
	Cercle(int x, int y, int width, int height) : Geometry(x, y, width, height) {}

	void Geometry::Draw(SDL_Renderer* renderer) override;
};

