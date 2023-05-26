#pragma once
#include "GlobalVariable.h"

class int4;
class ConsoleScreen
{
public:
    void Init(char _BaseCh);
    void SetPixel(const int4& _Pos, char _Ch);
    void Clear();
    void Print();

protected:

private:
    char BaseCh = ' ';
    char ArrScreen[YLine][XLine + 1] = {};
};