#include "Image.h"
#include<iostream>

void Image::Draw(SDL_Renderer* renderer)
{
    SDL_Surface* image = SDL_LoadBMP("C:/Users/icotvaquero/Documents/image.bmp");
    if (!image)
    {
        std::cout<<"Erreur de chargement de l'image.";
        return;
    }
    SDL_Texture* monImage = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
}
