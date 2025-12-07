#include "Geometry.h"

Geometry::Geometry(int width, int height)
{
    m_x = 0;
    m_y = 0;
    m_width = width;
    m_height = height;
}

void Geometry::SetPosition(int x, int y, float anchorX, float anchorY)
{
    m_x = x - (m_width * anchorX);
    m_y = y - (m_height * anchorY);
}

Vector2 Geometry::GetPosition(float anchorX, float anchorY) const
{
    Vector2 pos;
    pos.x = m_x + (m_width * anchorX);
    pos.y = m_y + (m_height * anchorY);

    return pos;
}


void Geometry::Resize(int width, int height)
{
    m_width = width;
    m_height = height;
}