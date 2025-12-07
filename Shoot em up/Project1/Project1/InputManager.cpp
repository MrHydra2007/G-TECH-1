#include "InputManager.h"
#include <iostream>

bool InputManager::HandleInput()
{
	for (auto& pair : keys)
	{
		pair.second.isDown = false;
		pair.second.isUp = false;
	}

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
			keys[event.key.keysym.scancode].isUp = true;
			keys[event.key.keysym.scancode].isHeld = false;
			break;

		case SDL_KEYDOWN:
			if (event.key.repeat == 0)
			{
				keys[event.key.keysym.scancode].isDown = true;
			}
			keys[event.key.keysym.scancode].isHeld = true;

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