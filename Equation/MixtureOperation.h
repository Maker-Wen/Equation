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

    // �����������ŵ���ʽ
    void createOperation(int n = MaxNums);


    char generateOperator();

    // �洢��������ȼ�
    static unordered_map<char, int> mp;
protected:
};

