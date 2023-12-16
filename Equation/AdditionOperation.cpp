#include "AdditionOperation.h"

AdditionOperation::AdditionOperation() : BinaryOperation()
{
}

AdditionOperation::AdditionOperation(string s) : BinaryOperation(s)
{
	if (islaw) {
		value = calculate();
	}
}


void AdditionOperation::createOperation(int n)
{
	operation.clear();
	islaw = true;
	int leftNum = rand() % MAXVALUE;
	int rightNum = rand() % (MAXVALUE - leftNum);
	while (leftNum == rightNum) {
		leftNum = rand() % MAXVALUE;
		rightNum = rand() % (MAXVALUE - leftNum);
	}
	value = leftNum + rightNum;
	operation = to_string(leftNum) + "+" + to_string(rightNum);
}

int AdditionOperation::calculate()
{
	int x = operation.find('+');
	int n = operation.size();
	int left = stoi(operation.substr(0, x));
	int right = stoi(operation.substr(x + 1));
	return left + right;
}
