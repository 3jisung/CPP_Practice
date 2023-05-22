#include <iostream>

using namespace std;

// 배열의 글자 수를 세는 함수
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

// 배열 내 글자 내용을 변경하는 함수
void ChangeCh(char* _Arr, char _PrevCh, char _NextCh)
{
    if (_Arr == nullptr)
    {
        cout << "nullptr가 참조 되었습니다." << endl;
        return;
    }

    int idx = 0;
    while (_Arr[idx++])
    {
        if (_Arr[idx] == _PrevCh)
        {
            _Arr[idx] = _NextCh;
        }
    }

    return;
}

int main()
{
    // 한글 들어가지 않습니다.
    {
        char Arr[100] = "aa0aa";

        cout << "StringCount Method" << endl;
        int Result = StringCount(Arr);

        if (Result != -1)
        {
            cout << Arr << " 의 글자 수 : " << Result << endl << endl << endl;
        }
    }

    {
        char Arr[100] = "aaa bbb ccc";
        cout << "ChangeCh Method" << endl << "변경 전 : " << Arr << endl;

        ChangeCh(Arr, 'c', 'd');

        cout << "변경 후 : " << Arr << endl;
    }
}