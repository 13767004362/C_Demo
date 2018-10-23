//Created by $HeXinGen on 2018/10/23.

//本案例：引用作为函数的参数和返回值
#include <iostream>

using namespace std;
//声明一个全局的数组
int array[3] = {10, 100, 1000};
//声明一个自增的函数
int &inCrease(int &a);
int main() {
    //输出数组的值
    for (int i = 0; i < 3; ++i) {
        cout << "数组 第" << i << "角标的值：" << array[i] << endl;
    }
    cout << "数组执行自增操作..................." << endl;
    for (int i = 0; i < 3; ++i) {
        cout << inCrease(array[i]) << "  , 数组中第" << i << "角标的值：" << array[i] << endl;
    }
    return 0;
}
int &inCrease(int &a) {
    ++a;
    static int result =a;
    cout << "自增返回的结果:" << result;
    return result;
};

