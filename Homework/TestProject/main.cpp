#include <iostream>

using namespace std;


class TestClass
{
public:
	int a = 10;

public:
	// static �Լ��� ��ü ���� ȣ���� �����ϴ�
	// ��, static �Լ����� this�� �������� �ʴ´�.
	// ���� �Ϲ����� ��������� ����� �� ����.
	static void Test()
	{
		
	}
};

int main()
{
	TestClass ta;

	TestClass::Test();

	return 0;
}