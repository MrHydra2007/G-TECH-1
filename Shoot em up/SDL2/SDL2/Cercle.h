#pragma once
#include "Geometry.h"

class Cercle : public Geometry
{
public:
	Cercle(float centerX, float centerY, float radius, float precision) : Geometry(x, y, width, height) {}

	void Geometry::Draw(SDL_Renderer* renderer, float centerX, float centerY, float radius, float precision) override;
};

