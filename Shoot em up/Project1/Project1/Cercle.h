#pragma once
#include "Geometry.h"

#define DEFAULT_PRECISION 30

class Cercle : public Geometry
{
	int m_precision;

public:
	Cercle(int radius, int precision = DEFAULT_PRECISION);

	void Draw(SDL_Renderer* renderer) override;
	int GetRadius() const { return m_width / 2; }
	void Update() override;
};
