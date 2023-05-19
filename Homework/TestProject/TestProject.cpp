#include <iostream>

using namespace std;

void Test(int a, ...)
{

}

int main()
{
    Test(1, 2);
    Test(1, 2, 'a', 4, true);
}
