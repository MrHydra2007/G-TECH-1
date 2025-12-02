#include "Geometry.h"

Geometry::Geometry(int posX, int posY, int w, int h) : m_x(posX), m_y(posY), m_width(w), m_height(h) {}

void Geometry::SetPosition(int x, int y, float anchorX, float anchorY)
{
    m_x = x - (m_width * anchorX);
    m_y = y - (m_height * anchorY);
}

//Vector2 Geometry::GetPosition(float anchorX, float anchorY)
//{

//}