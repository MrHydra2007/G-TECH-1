#include "InputManager.h"

void InputManager::HandleInput(SDL_Renderer* renderer)
{
	bool running = true;
	InputManager input;
	SDL_Event event;

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

		if (input.isMouseDown)
		{
			std::cout<< "click aux coordonnees: " << event.button.x << ", " << event.button.y << std::endl;
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
		}


		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_MOUSEBUTTONDOWN:
				input.isMouseDown = true;
				break;

			case SDL_MOUSEBUTTONUP:
				input.isMouseUp = true;
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
				if (input.isKeyDown == true && input.isKeyUp == false)
				{
					input.isKeyHeld = true;
				}
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