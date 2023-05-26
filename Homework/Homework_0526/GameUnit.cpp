#include "GameUnit.h"

int4 GameUnit::GetPos()
{
    return Pos;
}

void GameUnit::SetPos(const int4& _Pos)
{
    // 뭔가가 그냥 거저 된다.
    // => 내가 만들었다.
    // => 컴파일러나 기본문법으로 생략되어 있다.
    Pos = _Pos;
}