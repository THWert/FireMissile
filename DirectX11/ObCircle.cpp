#include "framework.h"

ObCircle::ObCircle()
{
    for (int i = 0; i < 60; i++)
    {
        vertex[i] = Vector2(0.5f * cosf(i * 6 * ToRadian), 0.5f * sinf(i * 6 * ToRadian));
    }
}

ObCircle::~ObCircle()
{
}

void ObCircle::Render()
{
    GameObject::Render();

    Vector2 transformVertex[60];

    for (int i = 0; i < 60; i++)
    {
        transformVertex[i] = Vector2::Transform(vertex[i], W);
    }

    MoveToEx(g_MemDC, transformVertex[0].x, transformVertex[0].y, NULL);

    for (int i = 0; i < 60; i++)
    {
        LineTo(g_MemDC, transformVertex[i].x, transformVertex[i].y);
    }
    LineTo(g_MemDC, transformVertex[0].x, transformVertex[0].y);
}
