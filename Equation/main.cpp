#include "main.h"

void showmain() {
    Equation a;
    int n, m = 0, mode;
    system("cls");
    cout<<"�������꼶:";
    cin >> mode;
    while (mode < 1 || mode > 6) {
        cout << "����������������룺";
        cin >> mode;
    }
    cout << "��������Ҫ���ɵ���ʽ������";
    cin >> n;
    while (n < 1) {
        cout << "��������С��1�����������룺";
        cin >> n;
    }
    if (mode == 5 || mode == 6) {
        cout << "��������Ҫ���ɵĴ������ŵ���ʽ������";
        cin >> m;
        while (m > n) {
            cout << "���ܴ�����ʽ�������������������룺";
            cin >> m;
        }
        if (m < 0) {
            m = 0;
        }
    }
    a.createSumEquation(n, m, mode);
    a.printEquation();
    cout << "�Ƿ񷵻����˵�(1):";
    int x;
    cin >> x;
    if (x == 1) {
        showmain();
    }
}
/// <summary>
/// ��ʽ��ΪEquation
/// ��ʽ������BinaryOperation
/// ��Ԫ�ӷ���ʽ��AdditionOperation
/// ��Ԫ������ʽ��SubtractOperation
/// ��Ԫ�˷���ʽ��MutiplicationOperation
/// ��Ԫ������ʽ��DivisionOperation
/// ��Ԫ�����ʽ��MixtureOperation
/// ��Ԫ��ϴ�������ʽ��MixedOperationWithBracket
/// </summary>
/// <returns></returns>
int main() {
    srand(time(0));
    showmain();
}
