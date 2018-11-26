//Created by $HeXinGen on 2018/11/25.
//

#include <iostream>

using namespace std;

//测试传递参数
void swap_test1(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}
//测试 指针参数
void swap_test2(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
//测试 引用参数
void swap_test3(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int main() {
    int a = 1, b = 2;
    swap_test1(a, b);
    cout << "传值参，调用swap()后， a=" << a << " , b=" << b << endl;
    int c = 3, d = 4;
    swap_test2(&c, &d);
    cout << "指针传参，调用swap()后， c=" << c << " , d=" << d << endl;
    int e = 5, f = 6;
    swap_test3(e, f);
    cout << "引用传参，调用swap()后， e=" << e << " , f=" << f << endl;
    return 0;
}