#include "main.h"

void showmain() {
    Equation a;
    int n, m = 0, mode;
    system("cls");
    cout<<"请输入年级:";
    cin >> mode;
    while (mode < 1 || mode > 6) {
        cout << "输入错误，请重新输入：";
        cin >> mode;
    }
    cout << "请输入想要生成的算式数量：";
    cin >> n;
    while (n < 1) {
        cout << "输入数量小于1，请重新输入：";
        cin >> n;
    }
    if (mode == 5 || mode == 6) {
        cout << "请输入想要生成的带有括号的算式数量：";
        cin >> m;
        while (m > n) {
            cout << "不能大于算式的总数量，请重新输入：";
            cin >> m;
        }
        if (m < 0) {
            m = 0;
        }
    }
    a.createSumEquation(n, m, mode);
    a.printEquation();
    cout << "是否返回主菜单(1):";
    int x;
    cin >> x;
    if (x == 1) {
        showmain();
    }
}
/// <summary>
/// 算式类为Equation
/// 算式抽象类BinaryOperation
/// 二元加法算式类AdditionOperation
/// 二元减法算式类SubtractOperation
/// 二元乘法算式类MutiplicationOperation
/// 二元除法算式类DivisionOperation
/// 多元混合算式类MixtureOperation
/// 多元混合带括号算式类MixedOperationWithBracket
/// </summary>
/// <returns></returns>
int main() {
    srand(time(0));
    showmain();
}
