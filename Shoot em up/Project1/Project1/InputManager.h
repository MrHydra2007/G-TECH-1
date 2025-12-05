#pragma once
#include<SDL.h>
#include<iostream>

class InputManager
{
public:
	static void HandleInput(SDL_Renderer* renderer);

private :

	bool isKeyDown = false;
	bool isKeyUp = false;
	bool isKeyHeld = false;

	bool isMouseDown = false;
	bool isMouseUp = false;
	bool isMouseHeld = false;
};

