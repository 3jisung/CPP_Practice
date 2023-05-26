#include "ConsoleScreen.h"
#include <iostream>

void ConsoleScreen::Init(char _BaseCh)
{
    BaseCh = _BaseCh;
    Clear();
}

void ConsoleScreen::SetPixel(const int4& _Pos, char _Ch)
{
    ArrScreen[_Pos.Y][_Pos.X] = _Ch;
}

void ConsoleScreen::Clear()
{
    system("cls");
    for (size_t y = 0; y < YLine; y++)
    {
        for (size_t x = 0; x < XLine; x++)
        {
            ArrScreen[y][x] = BaseCh;
        }
        ArrScreen[y][XLine] = 0;
    }
}

void ConsoleScreen::Print()
{
    for (size_t y = 0; y < YLine; y++)
    {
        printf_s(ArrScreen[y]);
        printf_s("\n");
    }
}