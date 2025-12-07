#include "AssetManager.h"
#include<iostream>
#include<SDL.h>
#include<SDL_image.h>

AssetManager* AssetManager::Instance = nullptr;

AssetManager* AssetManager::Get()
{
	if (Instance == nullptr)
		Instance = new AssetManager();

	return Instance;
}


SDL_Texture* AssetManager::LoadTexture(SDL_Renderer* renderer, const char* path)
{
	auto it = m_textures.find(path);

	if (it != m_textures.end())
		return it->second;

	SDL_Surface* surface = IMG_Load(path);

	if (surface == NULL)
	{
		std::cout << "Image not found" << std::endl;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);

	m_textures[path] = texture;

	return texture;
}