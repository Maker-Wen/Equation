#include "BinaryOperation.h"


BinaryOperation::BinaryOperation() {
	operation = "";
	value = 0;
}

BinaryOperation::BinaryOperation(string s)
{
    replaceSpace(s);
    if (checkIsLaw(s)) {
        //cout << "算式合法" <<endl;
        operation.assign(s);
    }
    else {
        islaw = false;
        //cout << "式子不合法" << endl;
    }
}

BinaryOperation::~BinaryOperation()
{

}

void BinaryOperation::replaceSpace(string& s)
{
    int pos = s.find(" ");
    while (pos != -1) {
        s.replace(pos, 1, "");
        pos = s.find(" ");
    }
}

bool BinaryOperation::checkIsLaw(string& s)
{
    int n = s.size();
    if (n == 0) {
        return true;
    }
    stack<char> ops;
    bool isop = true;
    for (int i = 0; i < s.size(); i++) {
        char e = s[i];
        if (e == '(') {
            ops.push(e);
            isop = true;
        }
        else if (e == ')') {
            if (ops.empty() || isop) {
                return false;
            }
            ops.pop();
        }
        else if (e == '+' || e == '-' || e == '*') {
            if (isop) {
                return false;
            }
            isop = true;
        }
        else if (e == '/') {
            if (isop || (i < s.size() - 1 && s[i + 1] == '0')) {
                return false;
            }
            isop = true;
        }
        else if(isdigit(e)){
            isop = false;
        }
        // 出现未设定的字符
        else {
            return false;
        }
    }
    return ops.empty() && !isop;
}


void BinaryOperation::printOperation()
{
	cout << operation << endl;
}

const string& BinaryOperation::getOperation()
{
    return operation;
}

int BinaryOperation::getValue()
{
	return value;
}

bool BinaryOperation::getLaw()
{
    return islaw;
}


