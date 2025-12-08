#pragma once
#include "Math.h"

struct SDL_Renderer;
class Cercle;

class Geometry
{
protected:
	int m_x;
	int m_y;
	int m_width;
	int m_height;

public:
	Geometry(int width, int height);
	~Geometry() = default;

	virtual void Resize(int width, int height);

	virtual void Update() {};
	virtual void Draw(SDL_Renderer* renderer) = 0;
	virtual bool Colision(const Geometry& other) { return false; };
	void SetPosition(int x, int y, float anchorX = 0.5f, float anchorY = 0.5f);
	Vector2 GetPosition(float anchorX = 0.5f, float anchorY = 0.5f) const;
};