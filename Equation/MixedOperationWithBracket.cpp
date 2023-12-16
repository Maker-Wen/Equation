#include "MixedOperationWithBracket.h"

void MixedOperationWithBracket::createOperation(int n)
{
    operation.clear();
    islaw = true;
    int countNums = (rand() % (n - MinNums)) + MinNums + 1;   //最少为3个运算符
    int limit = 99;
    int leftB = rand() % (countNums - 1);
    int rightB;

    // 避免括号在算式两端出现
    if(leftB == 0)
        rightB = rand() % (countNums - leftB - 2) + leftB + 1;
    else
        rightB = rand() % (countNums - leftB - 1) + leftB + 1;

    bool haveB = false;
    int num1 = rand() % limit + 1;
    if (leftB == 0) {
        operation += '(';
    }
    operation += to_string(num1);

    for (int i = 1; i < countNums; i++) {
        int num2 = 0;
        char op = generateOperator();
        if (op == '-') {
            num2 = rand() % num1 + 1;
        }
        else if (op == '*' && num1 < 50) {
            num2 = rand() % (limit / num1 - 1) + 2;   // -1最大为150， -2最大为100
            while (num1 == num2) {
                num2 = rand() % (limit / num1 - 1) + 2;
            }
        }
        else if (op == '/' && num1 >= 4) {
            vector<int> nums;
            int l = 1, r = sqrt(num1);
            for (int i = 1; i <= r; i++) {
                if (num1 % i == 0)
                    nums.push_back(i);
            }
            // 避免除1
            if (nums.size() == 1) {    
                op = '+';
                num2 = rand() % (limit - num1 + 1) + 1;
            }
            else
                num2 = nums[rand() % (nums.size() - 1) + 1];
        }
        else {
            num2 = rand() % (limit - num1 + 1) + 1;
            while (num1 == num2) {
                num2 = rand() % (limit - num1 + 1) + 1;
            }
        }
        operation += op;
        if (leftB == i) {
            operation += '(';
        }

        operation += to_string(num2);
        if (rightB == i) {
            operation += ')';
        }
        num1 = num2;
    }
    value = calculate();
}

