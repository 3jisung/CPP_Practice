#include <iostream>
#include <cmath>

using namespace std;


// Ch와 같은 문자가 몇개들어있는지 세어서 리턴해주는 함수
int ChCount(const char* const _string, char Ch)
{
    if (_string == nullptr)
    {
        cout << "nullptr가 참조 되었습니다." << endl;
        return -1;
    }

    int cnt = 0;
    int idx = -1;
    while (_string[++idx])
    {
        if (_string[idx] == Ch)
        {
            ++cnt;
        }
    }

    return cnt;
}


// 공백을 제거하는 함수
void TrimDelete(char* _string)
{
    if (_string == nullptr)
    {
        cout << "nullptr가 참조 되었습니다." << endl;
        return;
    }

    int checkIdx = -1;
    int valueIdx = 0;
    while (_string[++checkIdx])
    {
        if (_string[checkIdx] != ' ')
        {
            _string[valueIdx++] = _string[checkIdx];
        }
    }
    _string[valueIdx] = '\0';

    return;
}


// 정수의 자릿수를 구하는 함수
int DigitsCount(int _Number)
{
    if (_Number < 0)
    {
        cout << "0 이상의 값만 입력해 주세요." << endl;
        return -1;
    }
    
    int cnt = 1;
    while (_Number >= 10)
    {
        _Number /= 10;
        ++cnt;
    }

    return cnt;
}


// 문자열을 카피하는 함수
void StrCopy(const char* const _Left, char* _Right)
{
    if (_Left == nullptr || _Right == nullptr)
    {
        cout << "nullptr가 참조 되었습니다." << endl;
        return;
    }

    int idx = -1;
    while (_Left[++idx])
    {
        _Right[idx] = _Left[idx];
    }
    _Right[idx] = '\0';
    
    return;
}


// 0 이상의 정수를 입력 받아 스트링으로 변환하는 함수
void NumberToString(int _Number, char* _Right)
{
    if (_Right == nullptr)
    {
        cout << "nullptr가 참조 되었습니다." << endl;
        return;
    }
    else if (_Number < 0)
    {
        cout << "0 이상의 값만 입력해 주세요." << endl;
        return;
    }

    int digit = DigitsCount(_Number);
    _Right[digit] = '\0';

    int zeroNumAscii = 48;      // 아스키코드 48~57번 = 숫자 0~9
    int idx = -1;

    // 숫자를 큰 자릿수부터 한 개씩 잘라가며 배열에 채워 넣는 루프문
    while (digit)
    {
        int div = (int)pow(10, --digit);            // 나눠줄 값 계산(_Number의 초기값이 312라면 100으로 나눠 몫이 3이 나오도록 한다. loof문이 반복될 때마다 나눠줄 값도 바뀌어야 하므로 증감연산자를 사용하여 digit값을 조정한다.)
        int quo = _Number / div;                    // 몫을 구하여 현재 가장 큰 자릿수의 숫자를 quo 변수에 담는다.
        _Right[++idx] = char(zeroNumAscii + quo);   // 위에서 구한 숫자를 배열의 앞 주소부터 채워 넣는다.(아스키코드 48번부터 숫자 0이므로 48에 quo 값을 더한 뒤 형변환 하여 원하는 숫자를 배열에 넣는다.)
        _Number %= div;                             // _Number의 가장 큰 자릿수를 제외한 나머지 값으로 변수 값을 업데이트 하고, 모든 숫자를 배열에 넣을 때까지 loof문을 반복한다.
    }

    return;
}


int main()
{
    // 문자열의 마지막에 들어가는 0은 글자로 치지 않습니다.
    {
        char Arr[256] = "ab aaa ccc ddd eee";
        char testToken = 'a';

        cout << "ChCount Method" << endl;
        int Result = ChCount(Arr, testToken);

        if (Result != -1)
        {
            cout << "문자열 : " << Arr << endl << "비교 토큰 : " << testToken << endl << "같은 문자의 개수 : " << Result << endl << endl << endl;
        }
    }

    {
        char Arr[256] = "aa  b  c dd ee    ";
        cout << "TrimDelete Method" << endl << "변경 전 : [" << Arr << "]" << endl;

        TrimDelete(Arr);

        cout << "변경 후 : [" << Arr << "]" << endl << endl << endl;
    }

    {
        int testValue = 1013120;

        cout << "DigitsCount Method" << endl;
        int Result = DigitsCount(testValue);

        if (Result != -1)
        {
            cout << "정수 : " << testValue << endl << "자릿수 : " << Result << endl << endl << endl;
        }
    }

    {
        char originText[256] = "aaaa bbb ccc";
        char ArrCopyText[256] = {};

        cout << "StrCopy Method" << endl << "복사 대상 : " << originText << endl << "복사 전 텍스트 : " << ArrCopyText << endl;
        StrCopy("aaaa bbb ccc", ArrCopyText);

        cout << "복사 후 텍스트 : " << ArrCopyText << endl << endl << endl;
    }

    {
        int num = 141245;
        char Result[256] = {};

        cout << "NumberToString Method" << endl << "정수 : " << num << endl << "변환 전 : " << Result << endl;
        NumberToString(num, Result);

        cout << "변환 후 : " << Result << endl;
    }
}