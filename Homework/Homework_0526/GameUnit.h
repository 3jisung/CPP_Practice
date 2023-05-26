#pragma once
#include "int4.h"

class GameUnit
{
public:
	int4 GetPos();
	void SetPos(const int4& _Pos);

protected:
	int4 Pos;
};