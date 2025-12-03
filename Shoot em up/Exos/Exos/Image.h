#pragma once
#include "Geometry.h"
#include <string>

class Image : public Geometry
{
public:
    Image(SDL_Renderer* renderer, std::string& path) : Geometry(m_x, m_y, m_width, m_height) {}
    ~Image() = default;

    void Draw(SDL_Renderer* renderer) override;

private:
    SDL_Texture* texture{ nullptr };
};
