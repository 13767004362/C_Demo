//Created by $HeXinGen on 2018/11/25.
//

#include <iostream>

using namespace std;

//���Դ��ݲ���
void swap_test1(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}
//���� ָ�����
void swap_test2(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
//���� ���ò���
void swap_test3(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int main() {
    int a = 1, b = 2;
    swap_test1(a, b);
    cout << "��ֵ�Σ�����swap()�� a=" << a << " , b=" << b << endl;
    int c = 3, d = 4;
    swap_test2(&c, &d);
    cout << "ָ�봫�Σ�����swap()�� c=" << c << " , d=" << d << endl;
    int e = 5, f = 6;
    swap_test3(e, f);
    cout << "���ô��Σ�����swap()�� e=" << e << " , f=" << f << endl;
    return 0;
}