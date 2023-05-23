#include <iostream>

using namespace std;


class TestClass
{
public:
	int a;

public:
	TestClass() : a(20)
	{

	}

	TestClass(int _a) : a(_a)
	{

	}
};

void Test(TestClass* t)
{
	t->a = 10;
}

int Test()
{

}

int main()
{
	TestClass ta;
	TestClass* tb;
	
	ta.a = 5;
	cout << ta.a << endl;
	Test(&ta);
	cout << ta.a << endl;
	
	

	return 0;
}