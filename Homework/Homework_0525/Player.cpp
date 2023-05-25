#include "Player.h"
#include <iostream>
#include "StringManage.h"

void Player::StatusRender()
{
	int Count = 0;

	Count = StringManage::StringCount(Name);

	// 40���� ���������.

	// �ٹٲ��� �ȵǰ� �ֽ��ϴ�.
	printf_s("%s", Name);

	for (size_t i = 0; i < StringManage::LineCount - Count; i++)
	{
		printf_s("-");
	}
	printf_s("\n");

	printf_s("���ݷ� : %d\n", Att);
	printf_s("ü  �� : %d\n", Hp);
	for (size_t i = 0; i < StringManage::LineCount; i++)
	{
		printf_s("-");
	}
	printf_s("\n");
}

void Player::DamagePrint(const char* const _AttName, int _Att)
{
	printf_s("%s�� %s�� �����߽��ϴ�.\n", _AttName, Name);
	printf_s("%s�� %d�� �������� �Ծ����ϴ�.\n", Name, _Att);
}

void Player::Damage(int _Att)
{
	Hp -= _Att;
}

const char* Player::GetName()
{
	return Name;
}

int Player::GetAtt()
{
	return Att;
}

bool Player::IsDeath()
{
	return Hp <= 0;
}
