#include <iostream>
#include <conio.h> // 키를 누를때까지 기다리는 함수(_getch())

using namespace std;

// 숙제 1 -- 문자의 오른쪽끝을 맞춰오세요. 이름은 알파뱃만
// 오른쪽끝 -------

// 숙제 2 -- 실시간으로 만들어오세요.
// 데미지 메세지가 나오는순간 체력이 곧바로 감소되게 만들어라.

// 숙제 3 -- 누군가 죽었다. 누군가의 Hp가 0이 된순간 종료.

// 몬스터와 플레이어가 서로 한대씩 때리면서
// 한명이 죽으면 끝납니다.
// 지금 그걸 그래픽으로 표현할 방법이 없으니까.
// 글자로 표현하겠습니다.


int StringCount(const char* const _Arr)
{
    if (_Arr == nullptr)
    {
        cout << "nullptr가 참조 되었습니다." << endl;
        return -1;
    }

    int cnt = -1;
    while (_Arr[++cnt]);

    return cnt;
}


void StatusRender(const char* const _Name, int _Att, int _Hp)
{
    // 40개로 맞춰오세요.

    // 줄바꿈이 안되고 있습니다.
    
    if (_Name == nullptr)
    {
        cout << "nullptr가 참조 되었습니다." << endl;
        return;
    }

    int strLen = StringCount(_Name);
    const int maxLen = 40;
    char varLine[maxLen + 1] = {};
    char fixLine[maxLen + 1] = {};

    for (size_t i = 0; i < maxLen; i++)
    {
        varLine[i] = '-';
        fixLine[i] = '-';
    }

    fixLine[maxLen] = '\0';
    varLine[maxLen - strLen] = '\0';

    printf_s("%s%s\n", _Name, varLine);
    printf_s("공격력 : %d\n", _Att);
    printf_s("체  력 : %d\n", _Hp);
    printf_s("%s\n", fixLine);
}


void DamagePrint(const char* const _AttName, const char* const _DefName, int _Att)
{
    printf_s("%s가 %s를 공격했습니다.\n", _AttName, _DefName);
    printf_s("%s는 %d의 데미지를 입었습니다.\n", _DefName, _Att);
}


void Damage(int& _Hp, int _Att)
{
    _Hp -= _Att;

    if (_Hp <= 0)
    {
        _Hp = 0;
    }
}


int main()
{
    int PlayerHp = 200;
    int PlayerAtt = 10;
    char PlayerName[40] = "ppp";

    int MonsterHp = 100;
    int MonsterAtt = 70;
    char MonsterName[40] = "mmm";

    int turn = 1;
    
    // 람다 함수를 이용한 동일 작업 처리
    auto StatusUI = [&]()     // & : 모든 외부 변수를 call by reference 방식으로 호출하여 람다 함수 내부에서 사용할 수 있도록 한다.
    {
        system("cls");
        StatusRender(PlayerName, PlayerAtt, PlayerHp);
        StatusRender(MonsterName, MonsterAtt, MonsterHp);
    };

    StatusUI();
    cout << "PRESS ANY KEY" << endl;
    _getch();

    while (true)
    {
        switch (turn)
        {
        case 1:
            Damage(MonsterHp, PlayerAtt);

            StatusUI();
            DamagePrint(PlayerName, MonsterName, PlayerAtt);

            turn = 2;
            break;

        case 2:
            Damage(PlayerHp, MonsterAtt);

            StatusUI();
            DamagePrint(MonsterName, PlayerName, MonsterAtt);

            turn = 1;
            break;

        default:
            break;
        }

        if (PlayerHp <= 0)
        {
            cout << PlayerName << " 플레이어가 사망하였습니다." << endl;
            break;
        }
        else if (MonsterHp <= 0)
        {
            cout << MonsterName << " 몬스터가 사망하였습니다." << endl;
            break;
        }
        else
        {
            _getch();
        }
    }

    return 0;
}