#include "DivisionOperation.h"

DivisionOperation::DivisionOperation() : BinaryOperation()
{
}

DivisionOperation::DivisionOperation(string s) : BinaryOperation(s)
{
	if (islaw) {
		value = calculate();
	}
}

int DivisionOperation::calculate()
{
	int x = operation.find('/');
	int n = operation.size();
	int left = stoi(operation.substr(0, x));
	int right = stoi(operation.substr(x + 1));
	if (float(left) / right != left / right) {
		islaw = false;
	}
	return left / right;
}

void DivisionOperation::createOperation(int n)
{
	operation.clear();
	islaw = true;
	int left = rand() % MAXVALUE;
	int right;
	if (left == 0) {
		right = rand() % (MAXVALUE - 1) + 1;
	}
	else {
		vector<int> nums;
		int l = 1, r = sqrt(left);
		for (int i = l; i <= r; i++) {
			if (left % i == 0)
				nums.push_back(i);
		}
		if (nums.size() > 1) {
			right = nums[rand() % (nums.size() - 1) + 1];
		}
		else
			right = 1;
	}
	operation = to_string(left) + "/" + to_string(right);
	value = left / right;
}

