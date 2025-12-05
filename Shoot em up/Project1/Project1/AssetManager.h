#pragma once
#include<vector>

struct SDL_Texture;
struct SDL_Renderer;


class AssetManager
{
	static AssetManager* Instance;

	std::vector<SDL_Texture*> m_textures;
	std::vector<const char*> m_path;

public:
	static AssetManager* Get();

	SDL_Texture* LoadTexture(SDL_Renderer* renderer, const char* path);
};

