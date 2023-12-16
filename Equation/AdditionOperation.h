#pragma once
#include "BinaryOperation.h"
class AdditionOperation :
    public BinaryOperation
{
public:
    AdditionOperation();
    AdditionOperation(string s);
    void createOperation(int n = MaxNums);
    int calculate();
private:

};

