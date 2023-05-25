#include <iostream>

using namespace std;


class TestClass
{
public:
	int a = 10;

public:
	// static 함수는 객체 없이 호출이 가능하다
	// 즉, static 함수에는 this가 존재하지 않는다.
	// 따라서 일반적인 멤버변수를 사용할 수 없다.
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