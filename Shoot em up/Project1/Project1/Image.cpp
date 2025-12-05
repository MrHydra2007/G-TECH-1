#include "Image.h"
#include<SDL_image.h>
#include<iostream>


Image::Image(SDL_Renderer* renderer, const char* path) : Geometry(0, 0, -1, -1)
{
	SDL_Surface* image_sur = IMG_Load(path);
	if (image_sur == nullptr) {
		std::cout << "Error loading image: " << IMG_GetError();
		return;
	}

	m_texture = SDL_CreateTextureFromSurface(renderer, image_sur);
	if (m_texture == nullptr) {
		std::cout << "Error creating texture";
		return;
	}

	SDL_FreeSurface(image_sur);

	SDL_QueryTexture(m_texture, NULL, NULL, &m_width, &m_height);
}

void Image::Draw(SDL_Renderer* renderer)
{
	SetPosition(400, 400, 0.5f, 0.5f);
	SDL_Rect dst = { m_x, m_y, m_width, m_height };

	SDL_RenderCopy(renderer, m_texture, NULL, &dst);
}
