#include "Player.h"
#include "GlobalVariable.h"
#include <conio.h>

void Player::AddPos(const int4& _Pos)
{
    int4 tempPos = Pos;
    tempPos += _Pos;

    for (size_t i = 0; i < wallCount; i++)
    {
        if (obstacleArr[i] != nullptr && obstacleArr[i]->GetPos() == tempPos)
        {
            return;
        }
    }

    Pos += _Pos;

    if (Pos.X < 0)
    {
        Pos.X = 0;
    }
    else if (Pos.X >= XLine)
    {
        Pos.X = XLine - 1;
    }
    else if (Pos.Y < 0)
    {
        Pos.Y = 0;
    }
    else if (Pos.Y >= YLine)
    {
        Pos.Y = YLine - 1;
    }
}

void Player::Input()
{
    char Select = (char)_getch();

    switch (Select)
    {
    case 'a':
        AddPos(Left);
        break;
    case 'd':
        AddPos(Right);
        break;
    case 'w':
        AddPos(Up);
        break;
    case 's':
        AddPos(Down);
        break;
    case 'c':
        if (shotState == false)
        {
            ShotBullet();
        }
    default:
        break;
    }
}

void Player::ShotBullet()
{
    static int sec = 0;

    if (shotState == false)
    {
        bullet = Pos;
        shotState = true;
        return;
    }

    else if (sec % 3 == 0)
    {
        bullet += Left;

        for (size_t i = 0; i < wallCount; i++)
        {
            if (obstacleArr[i] != nullptr && bullet == obstacleArr[i]->GetPos())
            {
                delete obstacleArr[i];
                obstacleArr[i] = nullptr;

                shotState = false;
                sec = 0;

                break;
            }
        }

        if (bullet.X <= 0)
        {
            shotState = false;
            sec = 0;
        }
    }

    sec++;
}

Wall* Player::GetObstacle(int idx)
{
    return obstacleArr[idx];
}

void Player::SetObstacle(int idx, Wall* _Other)
{
    obstacleArr[idx] = _Other;
}

bool Player::GetShotState()
{
    return shotState;
}

int4 Player::GetBullet()
{
    return bullet;
}