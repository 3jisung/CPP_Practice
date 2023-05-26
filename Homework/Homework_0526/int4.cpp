#include "int4.h"

void int4::operator=(const int4& _Other)
{
    X = _Other.X;
    Y = _Other.Y;
    Z = _Other.Z;
    W = _Other.W;
}

void int4::operator+=(const int4& _Other)
{
    X += _Other.X;
    Y += _Other.Y;
    Z += _Other.Z;
    W += _Other.W;
}

bool int4::operator==(const int4& _Other)
{
    return (this->X == _Other.X && this->Y == _Other.Y && this->Z == _Other.Z && this->W == _Other.W);
}