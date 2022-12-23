#include "framework.h"

ObRect::ObRect()
{
    vertex[0] = Vector2(-0.5f, 0.5f);
    vertex[1] = Vector2(-0.5f, -0.5f);
    vertex[2] = Vector2(0.5f, -0.5f);
    vertex[3] = Vector2(0.5f, 0.5f);
}

ObRect::~ObRect()
{
}

void ObRect::Render()
{
    GameObject::Render();

    Vector2 transformVertex[4];

    for (int i = 0; i < 4; i++)
    {
        transformVertex[i] = Vector2::Transform(vertex[i], W);
    }

    MoveToEx(g_MemDC, transformVertex[0].x, transformVertex[0].y, NULL);
    LineTo(g_MemDC, transformVertex[1].x, transformVertex[1].y);
    LineTo(g_MemDC, transformVertex[2].x, transformVertex[2].y);
    LineTo(g_MemDC, transformVertex[3].x, transformVertex[3].y);
    LineTo(g_MemDC, transformVertex[0].x, transformVertex[0].y);

    //MoveToEx(g_MemDC, position.x * scale.x * cosf(45 * ToRadian + rotation) + 100,
    //    position.y + 100 * sinf(45 * ToRadian + rotation) * scale.y, NULL);

    //// Vertex * S * R * T

    //LineTo(g_MemDC, position.x + 100 * cosf(135 * ToRadian + rotation) * scale.x,
    //    position.y + 100 * sinf(135 * ToRadian + rotation) * scale.y);

    //LineTo(g_MemDC, position.x + 100 * cosf(225 * ToRadian + rotation) * scale.x,
    //    position.y + 100 * sinf(225 * ToRadian + rotation) * scale.y);

    //LineTo(g_MemDC, position.x + 100 * cosf(315 * ToRadian + rotation) * scale.x,
    //    position.y + 100 * sinf(315 * ToRadian + rotation) * scale.y);

    //LineTo(g_MemDC, position.x + 100 * cosf(45 * ToRadian + rotation) * scale.x,
    //    position.y + 100 * sinf(45 * ToRadian + rotation) * scale.y);
}
