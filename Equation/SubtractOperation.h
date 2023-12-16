#pragma once
#include "BinaryOperation.h"
class SubtractOperation :
    public BinaryOperation
{
public:
    SubtractOperation();
    SubtractOperation(string s);
    int calculate();
    void createOperation(int n);
};

