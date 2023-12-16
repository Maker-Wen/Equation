#include "SubtractOperation.h"

SubtractOperation::SubtractOperation() : BinaryOperation()
{
}

SubtractOperation::SubtractOperation(string s) : BinaryOperation(s)
{
	if (islaw) {
		value = calculate();
	}
}

int SubtractOperation::calculate()
{
	int x = operation.find('-');
	int n = operation.size();
	int left = stoi(operation.substr(0, x));
	int right = stoi(operation.substr(x + 1));
	return left - right;
}


void SubtractOperation::createOperation(int n)
{
	operation.clear();
	islaw = true;
	int leftNum = rand() % MAXVALUE;
	int rightNum = rand() % (leftNum + 1);
	operation = to_string(leftNum) + "-" + to_string(rightNum);
	value = leftNum - rightNum;
}
