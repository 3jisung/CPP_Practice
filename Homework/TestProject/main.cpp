#include <iostream>

using namespace std;


class TestClass
{
public:
	int* a;

public:

};

int Test()
{
	return 0;
}


int main()
{
	TestClass ta;
	int a = 10;
	ta.a = &a;
	TestClass tb = ta;
	a = 60;

	cout << *ta.a << *tb.a << endl;

	return 0;
}