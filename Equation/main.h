#include<iostream>
#include <stdlib.h>
#include "BinaryOperation.h"
#include "Equation.h"
#include "MixtureOperation.h"

using namespace std;
int BinaryOperation::MAXVALUE = 100;
int BinaryOperation::MINVALUE = 0;
unordered_map<char, int> MixtureOperation::mp = {
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2}
};
int BinaryOperation::MaxNums = 10;
int BinaryOperation::MinNums = 2;
vector<char> BinaryOperation::Ops = {
    '+',
    '-',
    '*',
    '/'
};
int BinaryOperation::NumOps = 4;
unordered_map<string, int> Equation::equation;