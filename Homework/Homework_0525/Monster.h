#pragma once

class Monster
{
	// c++에서는 함수에도 그걸 만든 프로그래머의 의도를 부여할수가 있습니다.

public:
	void StatusRender();
	void DamagePrint(const char* const _AttName, int _Att);
	void Damage(int _Att);
	const char* GetName();
	int GetAtt();
	bool IsDeath();

private:
	// 캡슐화
	char Name[40] = "Monster";
	int Att = 10;
	int Hp = 100;
};