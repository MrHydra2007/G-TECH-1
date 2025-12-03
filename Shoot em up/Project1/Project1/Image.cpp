#include "Image.h"
#include<iostream>

void Image::Draw(SDL_Renderer* renderer)
{
    SDL_Surface* lettuce_sur = SDL_LoadBMP("lettuce.png");
    if (lettuce_sur == NULL) {
        std::cout << "Error loading image: " << SDL_GetError();
        return;
    }


}
