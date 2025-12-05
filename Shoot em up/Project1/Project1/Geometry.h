#pragma once
#include <SDL.h>
#include "Math.h"

class Geometry
{
protected:
	int m_x;
	int m_y;
	int m_width;
	int m_height;

public:
	Geometry(int x, int y, int width, int height);
	~Geometry() = default;

	virtual void Update() {};
	virtual void Draw(SDL_Renderer* renderer) = 0;
	void SetPosition(int x, int y, float anchorX, float anchorY);
	Vector2 GetPosition(float anchorX, float anchorY) const;
};