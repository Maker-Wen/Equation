#include "MutiplicationOperation.h"

MutiplicationOperation::MutiplicationOperation() : BinaryOperation()
{
}

MutiplicationOperation::MutiplicationOperation(string s) : BinaryOperation(s)
{
	if (islaw) {
		value = calculate();
	}
}

int MutiplicationOperation::calculate()
{
	int x = operation.find('*');
	int n = operation.size();
	int left = stoi(operation.substr(0, x));
	int right = stoi(operation.substr(x + 1));
	return left * right;
}

void MutiplicationOperation::createOperation(int n)
{
	operation.clear();
	islaw = true;
	int left = rand() % (MAXVALUE / 2);
	int right;
	if (left == 0) {
		right = rand() % (MAXVALUE - 1) + 1;	// 要求乘法两端不能相等
	}
	else {
		right = rand() % (MAXVALUE / left + 1);
	}
	while (left == right) {
		right = rand() % (MAXVALUE / left + 1);
	}
	operation = to_string(left) + "*" + to_string(right);
	value = left * right;
}