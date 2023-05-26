#pragma once
#include "GameUnit.h"
#include "Wall.h"

class Player : public GameUnit
{
public:
    // ���۷����� �⺻������ 8����Ʈ �����Դϴ�.
    // int4�� �׳� 16����Ʈ�Դϴ�.
    // int4&�� �׳� 8����Ʈ�Դϴ�.
    // int4*�� �׳� 8����Ʈ�Դϴ�.

    // ���� �������� ���ڰ� ���ļ� 8����Ʈ�� �Ѿ��
    // �װ� ����ü�� Ŭ������ ��� �������·� �ѱ�°� ��κ��� ��Ȳ����
    // ������ �̵��̴�.

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