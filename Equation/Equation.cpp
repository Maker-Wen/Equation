#include "Equation.h"

Equation::Equation()
{
	equation.clear();
}

Equation::~Equation()
{
}

void Equation::createEquation(int mode)
{
    BinaryOperation* a;
    if (mode == 1) {
        char op = BinaryOperation::Ops[rand() % 2];
        if (op == '+')
            a = new AdditionOperation();
        else
            a = new SubtractOperation();
        a->createOperation();
        while (equation.count(a->getOperation()) || !a->getLaw()) {
            a->createOperation();
        }
    }
    else if (mode == 2) {
        char op = BinaryOperation::Ops[rand() % 4];
        if (op == '+') {
            a = new AdditionOperation();
        }
        else if (op == '-') {
            a = new SubtractOperation();
        }
        else if (op == '*') {
            a = new MutiplicationOperation();
        }
        else {
            a = new DivisionOperation();
        }
        a->createOperation();
        while (equation.count(a->getOperation()) || !a->getLaw()) {
            a->createOperation();
        }
    }
    else if (mode == 3) {
        a = new MixtureOperation();
        a->createOperation(4);
        while (equation.count(a->getOperation()) || !a->getLaw()) {
            a->createOperation(4);
        }
    }
    else if (mode == 4) {
        a = new MixtureOperation();
        a->createOperation(6);
        while (equation.count(a->getOperation()) || !a->getLaw()) {
            a->createOperation(6);
        }
    }
    else if (mode == 5) {
        a = new MixtureOperation();
        a->createOperation(8);
        while (equation.count(a->getOperation()) || !a->getLaw()) {
            a->createOperation(8);
        }
    }
    else{
        a = new MixtureOperation();
        a->createOperation();
        while (equation.count(a->getOperation()) || !a->getLaw()) {
            a->createOperation();
        }
    }
    equation[a->getOperation()] = a->value;
    delete a;
}

void Equation::createBracketEquation(int n)
{
    BinaryOperation* a = new MixedOperationWithBracket();
    a->createOperation(n);
    while (equation.count(a->getOperation()) || !a->getLaw()) {
        a->createOperation(n);
    }
    equation[a->getOperation()] = a->value;
    delete a;
}


/// <summary>
/// 一年级只生成二元加减法算式
/// 二年级可以生成二元乘除算式
/// 三年级最多可以生成4个运算数的算式
/// 四年级最多可以生成6个运算数的算式
/// 五年级最多可以生成8个运算数且可带括号的算式
/// 六年级则完全随机生成，最多为10个运算数
/// </summary>
/// <param 算式数量="n"></param>
/// <param 生成括号算式数量="m"></param>
/// <param 年级="mode"></param>
void Equation::createSumEquation(int n, int m, int mode)
{
    // 定义具有括号的算式位置
    equation.clear();
    vector<int> random(n);
    unordered_set<int> nums;
    if (m && mode >= 5) {
        for (int i = 0; i < n; i++) {
            random[i] = i;
        }
        random_shuffle(random.begin(), random.end());
        for (int i = 0; i < m; i++) {
            nums.insert(random[i]);
        }
    }

    if (mode == 1) {
        for (int i = 0; i < n; i++) {
            createEquation(1);
        }
    }
    else if (mode == 2) {
        for (int i = 0; i < n; i++) {
            createEquation(2);
        }
    }
    else if (mode == 3){
        for (int i = 0; i < n; i++) {
            createEquation(3);
        }
    }
    else if (mode == 4) {
        for (int i = 0; i < n; i++) {
            createEquation(4);
        }
    }
    else if (mode == 5) {
        for (int i = 0; i < n; i++) {
            if (nums.count(i))  {
                createBracketEquation(8);
            }
            else
                createEquation(5);
        }
    }
    else if (mode == 6) {
        for (int i = 0; i < n; i++) {
            if (nums.count(i))
                createBracketEquation();
            else
                createEquation(6);
        }
    }
}

void Equation::printEquation()
{
    int count = 0;
    for (auto it : equation) {
        count++;
        cout << it.first << endl;
    }
}

//void Equation::loadEquationToFile(const string& filename)
//{
//    ofstream file(filename);
//    if (!file.is_open()) {
//        cout << "文件打开失败" << endl;
//        return;
//    }
//    for (auto it = equation.begin(); it != equation.end(); ++it) {
//        file << it->first << "=" << it->second;
//        if (next(it) != equation.end()) {
//            file << ",";
//        }
//    }
//}
//
//void Equation::readEquationFromFile(const string& filename)
//{
//    ifstream file(filename);
//    if (!file.is_open()) {
//        cout << "文件不存在或无法打开" << endl;
//        return;
//    }
//    string s;
//    while (getline(file, s, ',')) {
//        int pos = s.find('=');
//        string e = s.substr(0, pos);
//        int ans = stoi(s.substr(pos + 1));
//        equation[e] = ans;
//    }
//    file.close();
//}
