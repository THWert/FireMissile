#include "framework.h"

ObLine::ObLine()
{
	vertex[0] = Vector2(0.0f, 0.0f);
	vertex[1] = Vector2(1.0f, 0.0f);
}

ObLine::~ObLine()
{
}

void ObLine::Render()
{
    Vector2 transformVertex[2];

    for (int i = 0; i < 2; i++)
    {
        transformVertex[i] = Vector2::Transform(vertex[i], W);
    }

    MoveToEx(g_MemDC, transformVertex[0].x, transformVertex[0].y, NULL);
    LineTo(g_MemDC, transformVertex[1].x, transformVertex[1].y);
}
