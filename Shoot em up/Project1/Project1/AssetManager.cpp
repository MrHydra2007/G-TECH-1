#include "AssetManager.h"
#include<iostream>
#include<SDL.h>

AssetManager* AssetManager::Instance = nullptr;

AssetManager* AssetManager::Get()
{
	if (Instance == nullptr)
		Instance = new AssetManager();

}


SDL_Texture* AssetManager::LoadTexture(SDL_Renderer* renderer, const char* path)
{
	auto it = m_textures.find(path);

	if (it != m_textures.end())
		return it.second;

	SDL_Surface* surface = SDL_LoadBMP(path);
}