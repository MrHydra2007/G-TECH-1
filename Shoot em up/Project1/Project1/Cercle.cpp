#include "Cercle.h"
#include "InputManager.h"
#include <iostream>
#include <SDL.h>

Cercle::Cercle(int radius, int precision) : Geometry(radius * 2, radius * 2)
{
	m_precision = precision;
}

void Cercle::Draw(SDL_Renderer* renderer)
{
	float perimeter = 2 * M_PI;
	float step = perimeter / m_precision;

	float radius = GetRadius();

	Vector2 center = GetPosition(0.5f, 0.5f);

	int lastX = radius * cos(0) + center.x;
	int lastY = radius * sin(0) + center.y;

	for (int i = 1; i <= m_precision; i++)
	{
		int currentX = radius * cos(step * i) + center.x;
		int currentY = radius * sin(step * i) + center.y;

		SDL_RenderDrawLine(renderer, lastX, lastY, currentX, currentY);

		lastX = currentX;
		lastY = currentY;
	}
}

void Cercle::Update()
{
	InputManager& IM = InputManager::getInstance();

	Vector2 currentPos = GetPosition(0.5f, 0.5f);

	int speed = 1; 
	
	if (IM.isHeld(SDL_SCANCODE_A) || IM.isHeld(SDL_SCANCODE_LEFT))
	{
		SetPosition(currentPos.x - speed, currentPos.y, 0.5f, 0.5f);
	}
	if (IM.isHeld(SDL_SCANCODE_D) || IM.isHeld(SDL_SCANCODE_RIGHT))
	{
		SetPosition(currentPos.x + speed, currentPos.y, 0.5f, 0.5f);
	}
	if (IM.isHeld(SDL_SCANCODE_W) || IM.isHeld(SDL_SCANCODE_UP))
	{
		SetPosition(currentPos.x, currentPos.y - speed, 0.5f, 0.5f);
	}
	if (IM.isHeld(SDL_SCANCODE_S) || IM.isHeld(SDL_SCANCODE_DOWN))
	{
		SetPosition(currentPos.x, currentPos.y + speed, 0.5f, 0.5f);
	}

	//if (currentPos.x > 801)
		//currentPos.x - 801;
}