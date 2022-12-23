#include "framework.h"
#include "MainGame.h"

MainGame::~MainGame()
{
}

void MainGame::Init()
{
    //MemDc �޸𸮻��� dc�� �ϳ� �� �߰�
    HBITMAP	 m_hOldBitmap, m_hBitmap;
    HDC	hdc = GetDC(g_hwnd); //���� �ڵ�
    g_MemDC = CreateCompatibleDC(hdc);
    m_hBitmap = CreateCompatibleBitmap(hdc, 800, 600);
    m_hOldBitmap = (HBITMAP)SelectObject(g_MemDC, m_hBitmap);
    ReleaseDC(g_hwnd, hdc);

    player.SetWorldPos(Vector2(400.0f, 300.0f));
    player.scale = Vector2(80.0f, 80.0f);
    player.rotation = 0.0f;
    player.isAxis = true;

    pet.SetParentRT(player);
    pet.SetLocalPos(Vector2(100.0f, 100.0f));
    pet.scale = Vector2(30.0f, 30.0f);
    pet.rotation = 0.0f;
    pet.isAxis = true;

    for (int i = 0; i < 10; i++)
    {
        missile[i].SetLocalPos(Vector2(2000.0f, 2000.0f));
        missile[i].scale.x = 30.0f;
        missile[i].rotation = 0.0f;
    }

    isFired = false;
}

void MainGame::Update()
{
    if (INPUT->KeyPress(VK_UP))
    {
        player.MoveWorldPos(-player.GetDown() * 200.0f * DELTA);
    }
    if (INPUT->KeyPress(VK_DOWN))
    {
        player.MoveWorldPos(player.GetDown() * 200.0f * DELTA);
    }
    if (INPUT->KeyPress(VK_LEFT))
    {
        player.rotation -= 120.0f * ToRadian * DELTA;
    }
    if (INPUT->KeyPress(VK_RIGHT))
    {
        player.rotation += 120.0f * ToRadian * DELTA;
    }

    if (INPUT->KeyDown('R'))
    {
        isFired = false;

        for (int i = 0; i < 10; i++)
        {
            missile[i].SetWorldPos(Vector2(2000.0f, 2000.0f));
        }

        maxmissile = 0;
    }

    //�߻�
    if (INPUT->KeyDown(VK_SPACE))
    {
        //�߻��ض�
        if (maxmissile < 10)
        {
            isFired = true;
            missile[maxmissile].rotation = DirToRadian(player.GetRight());
            missile[maxmissile].SetWorldPos(player.GetWorldPos());

            maxmissile++;
        }
    }

    if (isFired)
    {
        for (int i = 0; i < 10; i++)
        {
            missile[i].MoveWorldPos(missile[i].GetRight() * 200.0f * DELTA);
        }
    }

    pet.revolution += 30.0f * ToRadian * DELTA;

    player.Update();
    pet.Update();

    for (int i = 0; i < 10; i++)
    {
        missile[i].Update();
    }

    //Ű�� ������ �� wm_paint �� �߻� ���Ѷ�
    InvalidateRect(g_hwnd, NULL, false);
}

void MainGame::Render()
{
    PAINTSTRUCT ps;
    //hdc-> ��ȭ��
    g_hdc = BeginPaint(g_hwnd, &ps);

    //������ ���
    PatBlt(g_MemDC, 0, 0, 800, 600, WHITENESS);
    string FPS = "FPS : " + to_string(TIMER->GetFPS());
    TextOutA(g_MemDC, 0, 0, FPS.c_str(), FPS.size());

    player.Render();
    pet.Render();
    for (int i = 0; i < 10; i++)
    {
        missile[i].Render();
    }

    //��� ���� g_MemDC���� g_hdc��
    BitBlt(g_hdc, 0, 0, 800, 600, g_MemDC, 0, 0, SRCCOPY);

    EndPaint(g_hwnd, &ps);
}