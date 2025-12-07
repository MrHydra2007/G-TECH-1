#pragma once
#include<map>
#include<SDL.h>

struct KeyData
{
	bool isDown = false;
	bool isUp = false;
	bool isHeld = false;
};


class InputManager
{
public:
	static InputManager& getInstance() {
		static InputManager instance;
		return instance;
	}
	bool HandleInput();

	bool isDown(SDL_Scancode code) { return keys[code].isDown; }

protected :
	std::map<SDL_Scancode, KeyData> keys;

	bool isMouseDown = false;
	bool isMouseUp = false;
	bool isMouseHeld = false;
};

