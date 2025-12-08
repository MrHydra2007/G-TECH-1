#include "Cercle.h"
#include "InputManager.h"
#include <iostream>
#include <SDL.h>
#include <cmath>

Cercle::Cercle(int radius, int precision) : Geometry(radius * 2, radius * 2)
{
	m_precision = precision;
}

void Cercle::DrawAtPosition(SDL_Renderer* renderer, Vector2 center)
{
	float perimeter = 2 * M_PI;
	float step = perimeter / m_precision;
	float radius = GetRadius();

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

void Cercle::Draw(SDL_Renderer* renderer)
{
	Vector2 center = GetPosition(0.5f, 0.5f);
	float radius = GetRadius();
	int screenWidth = 800;
	int screenHeight = 800;

	DrawAtPosition(renderer, center);

	Vector2 newPos;

	if (center.x - radius < 0)
	{
		newPos.x = center.x + screenWidth;
		newPos.y = center.y;
		DrawAtPosition(renderer, newPos);
	}
	if (center.x + radius > screenWidth)
	{
		newPos.x = center.x - screenWidth;
		newPos.y = center.y;
		DrawAtPosition(renderer, newPos);
	}
	if (center.y - radius < 0)
	{
		newPos.x = center.x;
		newPos.y = center.y + screenHeight;
		DrawAtPosition(renderer, newPos);
	}
	if (center.y + radius > screenHeight)
	{
		newPos.x = center.x;
		newPos.y = center.y - screenHeight;
		DrawAtPosition(renderer, newPos);
	}

	if (center.x - radius < 0 && center.y - radius < 0)
	{
		newPos.x = center.x + screenWidth;
		newPos.y = center.y + screenHeight;
		DrawAtPosition(renderer, newPos);
	}
	if (center.x + radius > screenWidth && center.y - radius < 0)
	{
		newPos.x = center.x - screenWidth;
		newPos.y = center.y + screenHeight;
		DrawAtPosition(renderer, newPos);
	}
	if (center.x - radius < 0 && center.y + radius > screenHeight)
	{
		newPos.x = center.x + screenWidth;
		newPos.y = center.y - screenHeight;
		DrawAtPosition(renderer, newPos);
	}
	if (center.x + radius > screenWidth && center.y + radius > screenHeight)
	{
		newPos.x = center.x - screenWidth;
		newPos.y = center.y - screenHeight;
		DrawAtPosition(renderer, newPos);
	}
}

bool Cercle::Colision(const Geometry& other)
{
	// "otherCircle" c'est le pointeur que l'on veut pouvoir utiliser
	//"dynamic_cast" fais la transformation en sécurité des pointeurs, verifie que l'objet pointé soit bien dans ce cas un Cercle
	//"other" est une reference de Geometry&, "&" recupere l'adresse, ce qui nous donne l'equivalent a Geometry*.
	const Cercle* otherCircle = dynamic_cast<const Cercle*>(&other);

	if (otherCircle)
	{
		Vector2 center1 = GetPosition(0.5f, 0.5f);
		Vector2 center2 = otherCircle->GetPosition(0.5f, 0.5f);

		float distX = center2.x - center1.x;
		float distY = center2.y - center1.y;
		float distance = sqrt(distX * distX + distY * distY);

		float radius1 = GetRadius();
		float radius2 = otherCircle->GetRadius();

		return distance <= (radius1 + radius2);
	}

	return false;
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

	if (currentPos.x > 801)
		SetPosition(currentPos.x - 801, currentPos.y, 0.5f, 0.5f);
	if (currentPos.x < 0)
		SetPosition(currentPos.x + 801, currentPos.y, 0.5f, 0.5f);
	if (currentPos.y < 0)
		SetPosition(currentPos.x, currentPos.y + 801, 0.5f, 0.5f);
	if (currentPos.y > 801)
		SetPosition(currentPos.x, currentPos.y - 801, 0.5f, 0.5f);
}


