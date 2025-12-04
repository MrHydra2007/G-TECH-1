#include "Image.h"
#include<SDL_image.h>
#include<iostream>

void Image::Draw(SDL_Renderer* renderer)
{
	SDL_Surface* image_sur = IMG_Load("C:/Users/icotvaquero/Documents/image_test.png");
	if (image_sur == nullptr) {
		std::cout << "Error loading image: " << IMG_GetError();
		return;
	}

	SDL_Texture* image_tex = SDL_CreateTextureFromSurface(renderer, image_sur);
	if (image_tex == nullptr) {
		std::cout << "Error creating texture";
		return;
	}

	SDL_RenderCopy(renderer, image_tex, nullptr, nullptr);
}
