#include "framework.h"

ObStar::ObStar()
{
    vertex[0] = Vector2(0.5f * cosf(0 * ToRadian), 0.5f * sinf(0 * ToRadian));
    vertex[1] = Vector2(0.5f * cosf(144 * ToRadian), 0.5f * sinf(144 * ToRadian));
    vertex[2] = Vector2(0.5f * cosf(288 * ToRadian), 0.5f * sinf(288 * ToRadian));
    vertex[3] = Vector2(0.5f * cosf(72 * ToRadian), 0.5f * sinf(72 * ToRadian));
    vertex[4] = Vector2(0.5f * cosf(216 * ToRadian), 0.5f * sinf(216 * ToRadian));
}

ObStar::~ObStar()
{
}

void ObStar::Render()
{
    Vector2 transformVertex[5];

    for (int i = 0; i < 5; i++)
    {
        transformVertex[i] = Vector2::Transform(vertex[i], W);
    }

    MoveToEx(g_MemDC, transformVertex[0].x, transformVertex[0].y, NULL);
    LineTo(g_MemDC, transformVertex[1].x, transformVertex[1].y);
    LineTo(g_MemDC, transformVertex[2].x, transformVertex[2].y);
    LineTo(g_MemDC, transformVertex[3].x, transformVertex[3].y);
    LineTo(g_MemDC, transformVertex[4].x, transformVertex[4].y);
    LineTo(g_MemDC, transformVertex[0].x, transformVertex[0].y);

    /*MoveToEx(g_MemDC, position.x + 100 * cosf(0 * ToRadian + rotation) * scale.x,
        position.y + 100 * sinf(0 * ToRadian + rotation) * scale.y, NULL);

    LineTo(g_MemDC, position.x + 100 * cosf(144 * ToRadian + rotation) * scale.x,
        position.y + 100 * sinf(144 * ToRadian + rotation) * scale.y);

    LineTo(g_MemDC, position.x + 100 * cosf(288 * ToRadian + rotation) * scale.x,
        position.y + 100 * sinf(288 * ToRadian + rotation) * scale.y);

    LineTo(g_MemDC, position.x + 100 * cosf(72 * ToRadian + rotation) * scale.x,
        position.y + 100 * sinf(72 * ToRadian + rotation) * scale.y);

    LineTo(g_MemDC, position.x + 100 * cosf(216 * ToRadian + rotation) * scale.x,
        position.y + 100 * sinf(216 * ToRadian + rotation) * scale.y);

    LineTo(g_MemDC, position.x + 100 * cosf(0 * ToRadian + rotation) * scale.x,
        position.y + 100 * sinf(0 * ToRadian + rotation) * scale.y);*/
}
