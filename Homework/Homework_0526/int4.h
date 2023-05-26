#pragma once

class int4
{
public:
    int X = 0;
    int Y = 0;
    int Z = 0;
    int W = 0;

public:
    void operator=(const int4& _Other);
    void operator+=(const int4& _Other);
    bool operator==(const int4& _Other);
};