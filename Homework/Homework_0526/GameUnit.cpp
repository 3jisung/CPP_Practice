#include "GameUnit.h"

int4 GameUnit::GetPos()
{
    return Pos;
}

void GameUnit::SetPos(const int4& _Pos)
{
    // ������ �׳� ���� �ȴ�.
    // => ���� �������.
    // => �����Ϸ��� �⺻�������� �����Ǿ� �ִ�.
    Pos = _Pos;
}