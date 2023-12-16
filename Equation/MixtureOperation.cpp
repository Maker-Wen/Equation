#include "MixtureOperation.h"

MixtureOperation::MixtureOperation() : BinaryOperation()
{
    
}

MixtureOperation::MixtureOperation(string s) : BinaryOperation(s)
{
    if (islaw) {
        value = calculate();
    }
}

int MixtureOperation::calculate()
{
    replaceSpace(operation);
    int n = operation.size();
    stack<int> nums;
    stack<char> ops;
    nums.push(0);

    for (int i = 0; i < n; i++) {
        char c = operation[i];
        if (c == '(') {
            ops.push(c);
        }
        else if (c == ')') {
            while (!ops.empty()) {
                if (ops.top() != '(') {
                    calc(nums, ops);
                }
                else {
                    ops.pop();
                    break;
                }
            }
        }
        else {
            if (isdigit(c)) {
                int cur = 0;
                int j = i;
                while (j < n && isdigit(operation[j])) {
                    cur = cur * 10 + (operation[j] - '0');
                    j++;
                }
                nums.push(cur);
                i = j - 1;
            }
            else {
                if (i > 0 && (operation[i - 1] == '(' || operation[i - 1] == '+' || operation[i - 1] == '-')) {
                    nums.push(0);
                }
                while (!ops.empty() && ops.top() != '(') {
                    char pre = ops.top();
                    if (mp[pre] >= mp[c]) {
                        calc(nums, ops);
                    }
                    else {
                        break;
                    }
                }
                ops.push(c);
            }
        }
        }
    while (!ops.empty() && ops.top() != '(') {
        calc(nums, ops);
    }
    return nums.top();
}

void MixtureOperation::calc(stack<int>& nums, stack<char>& ops)
{
    if (nums.empty() || nums.size() < 2 || ops.empty()) {
        return;
    }
    int b = nums.top(); nums.pop();
    int a = nums.top(); nums.pop();
    char op = ops.top();    ops.pop();
    int ans = 0;
    if (op == '+') {
        ans = a + b;
    }
    else if (op == '-') {
        ans = a - b;
    }
    else if (op == '*') {
        ans = a * b;
    }
    else if (op == '/') {
        if (b == 0) {
            islaw = false;
            ans = a;
        }
        else {
            ans = a / b;
            if ((float)a / b != ans) {
                islaw = false;
            }
        }
    }
    if (ans < 0)
        islaw = false;
    nums.push(ans);
}


void MixtureOperation::createOperation(int n)
{
    // 生成无括号混合算式
    operation.clear();
    islaw = true;
    int countNums = (rand() % (n - MinNums)) + MinNums; // <= n-1
    int limit = 99;
    int num1 = rand() % limit + 1;
    operation += to_string(num1);
    for (int i = 1; i <= countNums; i++) {
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
        // 最后为加
        else {
            num2 = rand() % (limit - num1 + 1) + 1;
            while (num1 == num2) {
                num2 = rand() % (limit - num1 + 1) + 1;
            }
        }
        operation += op;
        operation += to_string(num2);
        num1 = num2;
    }
    value = calculate();
}


char MixtureOperation::generateOperator()
{
    char ans;
    int random = rand() % 6;
    if (random == 0 || random == 4) {
        ans = '+';
    }
    else if (random == 1 || random == 5) {
        ans = '-';
    }
    else if (random == 2) {
        ans = '*';
    }
    else{
        ans = '/';
    }
    return ans;
}
