#pragma once
#include "BinaryOperation.h"
class MutiplicationOperation :
    public BinaryOperation
{
public:
    MutiplicationOperation();
    MutiplicationOperation(string s);
    int calculate();
    void createOperation(int n);
};


