#pragma once
#include "GameUnit.h"
#include "Wall.h"

class Player : public GameUnit
{
public:
    // 레퍼런스는 기본적으로 8바이트 참조입니다.
    // int4를 그냥 16바이트입니다.
    // int4&를 그냥 8바이트입니다.
    // int4*를 그냥 8바이트입니다.

    // 내가 넣으려는 인자가 합쳐서 8바이트가 넘어갈때
    // 그걸 구조체나 클래스로 묶어서 참조형태로 넘기는게 대부분의 상황에서
    // 무조건 이득이다.

    void AddPos(const int4& _Pos);
    void Input();
    Wall* GetObstacle(int idx);
    void SetObstacle(int idx, Wall* _Other);
    void ShotBullet();
    bool GetShotState();
    int4 GetBullet();

    //Player(const Player&) = delete;

protected:

private:
    Wall* obstacleArr[10];
    bool shotState = false;
    int4 bullet;
};