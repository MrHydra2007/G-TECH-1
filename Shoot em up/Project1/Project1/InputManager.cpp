#include "InputManager.h"
#include<iostream>
#include"Geometry.h"

bool InputManager::HandleInput()
{
	KeyData KD;

	if (KD.isDown)
	{
		std::cout << "Kew Down" << std::endl;
		KD.isDown = false;
	}
	if (KD.isUp)
	{
		std::cout << "Key Up" << std::endl;
		KD.isUp = false;
	}

	if (KD.isHeld)
	{
		std::cout << "Key Held" << std::endl;
		KD.isHeld = false;
	}

	/*if (input.isMouseDown)
	{
		std::cout << "click aux coordonnees: " << event.button.x << ", " << event.button.y << std::endl;
		input.isMouseDown = false;
	}

	if (input.isMouseUp)
	{
		std::cout << "\n";
		input.isMouseUp = false;
	}

	if (input.isMouseHeld)
	{
		std::cout << "Click held" << std::endl;
		input.isMouseHeld = false;
	}*/

	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_MOUSEBUTTONDOWN:
		    isMouseDown = true;
			break;

		case SDL_MOUSEBUTTONUP:
			isMouseUp = true;
			break;

		case SDL_QUIT:
			return false;
			break;

		case SDL_KEYUP:
			keys[event.key.keysym.scancode] = { false, true, false};

			break;

		case SDL_KEYDOWN:
			keys[event.key.keysym.scancode] = { true, false, false };

			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				return false;
				break;
			}
			break;
		}
	}
	return true;
}