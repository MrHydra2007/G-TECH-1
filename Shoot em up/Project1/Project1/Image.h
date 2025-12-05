#pragma once
#include "Geometry.h"
#include <string>

struct SDL_Texture;


class Image : public Geometry
{

    SDL_Texture* m_texture;
public:
    Image(SDL_Renderer* renderer, const char* path);
    ~Image() = default;

    void Draw(SDL_Renderer* renderer) override;
    void Resize(int width, int height) override;

};
