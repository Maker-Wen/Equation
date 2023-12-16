#pragma once
#include "BinaryOperation.h"
class DivisionOperation :
    public BinaryOperation
{
public:
    DivisionOperation();
    DivisionOperation(string s);
    int calculate();
    void createOperation(int n);
};

