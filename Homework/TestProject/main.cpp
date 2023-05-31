
#include <crtdbg.h>

class Bullet
{

};


// 그럼 bool bool bool bool bool
// 8바이트씩 차지하죠?
// 160바이트


#define INFIHP         0x01
#define INFIATT        0x02

void GameStartInt(int _Option)
{
    if (0 != (_Option & INFIHP))
    {
        int a = 0;
    }

    if (0 != (_Option & INFIATT))
    {
        int a = 0;
    }
}

void GameStart(bool _InfinityHP, bool _InfinityAtt)
{

}

int main()
{
    // 00000000 00000000 00000000 00000000

//#define _CRTDBG_ALLOC_MEM_DF        0x01 // 00000000 00000000 00000000 00000001
//#define _CRTDBG_DELAY_FREE_MEM_DF   0x02 // 00000000 00000000 00000000 00000010
//#define _CRTDBG_CHECK_ALWAYS_DF     0x04 // 00000000 00000000 00000000 00000100
//#define _CRTDBG_RESERVED_DF         0x08
//#define _CRTDBG_CHECK_CRT_DF        0x10
//#define _CRTDBG_LEAK_CHECK_DF       0x20

    // 옵션최적화를 위한것.
    // _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF 
    // 00000000 00000000 00000000 00000001 | 00000000 00000000 00000000 00000010
    // 00000000 00000000 00000000 00000011 
    GameStartInt(INFIHP | INFIATT);


    // 20년 넘은 함수다.
    // 제대로된 C++ 프로그래머라면 모든 일을 정지하고 저거부터 잡습니다.
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //_CrtSetBreakAlloc(77);

    // 대부분의 언어는 요즘 가비지 컬렉터라는 
    // 힙사용시 자동삭제  기능을 내부에서 우리가 모르게 너희그냥 써
    // 우리가 알아서 지워줄께. 언어자체에서

    // 과거의 프로그래밍 언어니 c++은
    // 그런걸 안씁니다.
    // 프로그래머가 직접 지워줘야하고
    // 대부분의 프로그래밍 업계를 선도하는 사람들이
    // c++ 퇴출해야 한다고 하는 이유 대부분이 여기에도 있다.
    // 그사람들 눈에는 대다수의 프로그래머가 자격이 없어.
    // 꼼꼼하지도 않고 메모리에 대해서도 모르고
    // 자격이 없는데 코딩을 하느거야.

    // C# java 파이썬 루아 러스트 go => 자동으로 잡아주고 
    // 언어자체에서 우리가 모르는 사이에 삭제를 한다.
    // 게임은 안되.
    // 계획적으로 메모리가 사용되어야 하고

    //while (true)
    //{
        // new int()해놓고 포인터로 받지 않으면
        // lost pointer <= 이제 못찾는다. 
        // 

    // new를 했으면 받아라 => lost포인터가 되는 순간 leck이 된다.
    // new를 했으면 지우는 코드를 먼처 쳐라 그리고 확인까지 해라. 
    // 중단점을 걸고 그 코드에 들어오는지 확인해라.
    // 코드를 쳤으니 실행된다고 생각하지 마라.

    {
        int* Ptr = new int();

        if (nullptr == Ptr)
        {
            delete Ptr;
        }
    }

    {
        // 포인터는 랜덤인덱스 연산자가 있기 때문에.
        // Ptr[0];
        // *Ptr;
        // 배열을 받을수도 있고 int하나를 받을수 있다.
        // 내가 이포인터에 배열을 담아놨는지 그냥 값하나를 담아놨는지 잘 기억해야 합니다.

        int* Ptr = new int[20];

        if (nullptr == Ptr)
        {
            // 배열일 경우에는 delete[]로 삭제해야 한다.
            delete[] Ptr;
        }
    }


    // 릭이 난다고 큰문제는 없다. 4바이트
    // 메모리 누수 때문에 컴퓨터가 느려진다 => 개소리.
    // 운영체제가 우리프로그램의 크기는 다 감시하고 있다. 

    // 내프로그램이 문제가 생길 여지

    
}