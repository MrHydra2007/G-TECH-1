#include "InputManager.h"

void InputManager::HandleInput(SDL_Renderer* renderer)
{
	bool running = true;
	InputManager input;

	while (running)
	{
		if (input.isKeyDown)
		{
			std::cout << "Kew Down" << std::endl;
			input.isKeyDown = false;
		}
		if (input.isKeyUp)
		{
			std::cout << "Key Up" << std::endl;
			input.isKeyUp = false;
		}

		if (input.isKeyHeld)
		{
			std::cout << "Key Held" << std::endl;
			input.isKeyHeld = false;
		}

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_MOUSEBUTTONDOWN:
				std::cout << "click aux coordonnees: " << event.button.x << ", " << event.button.y << std::endl;
				break;

			case SDL_MOUSEBUTTONUP:
				std::cout << "\n";
				break;

			case SDL_QUIT:
				running = false;
				break;

			case SDL_KEYUP:
				input.isKeyUp = true;
				input.isKeyHeld = false;
				input.isKeyDown = false;
				break;

			case SDL_KEYDOWN:
				if (event.key.repeat)
					input.isKeyHeld = true;
				else
					input.isKeyDown = true;

				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					running = false;
					break;
				}
				break;
			}
		}
	}
}