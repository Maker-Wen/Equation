#pragma once
#include<unordered_map>
#include "BinaryOperation.h"
class MixtureOperation :
    public BinaryOperation
{
public:
    MixtureOperation();
    MixtureOperation(string s);
    int calculate();
    void calc(stack<int>& nums, stack<char>& ops);

    // 创建不带括号的算式
    void createOperation(int n = MaxNums);


    char generateOperator();

    // 存储运算符优先级
    static unordered_map<char, int> mp;
protected:
};

