#include "Image.h"

void Image::Draw(SDL_Renderer* renderer)
{
    SDL_Surface* image = SDL_LoadBMP("C:/Users/icotvaquero/Documents/lettuce.bmp");
    if (!image)
    {
        printf("Erreur de chargement de l'image : %s", SDL_GetError());
        return;
    }
    SDL_Texture* monImage = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
}