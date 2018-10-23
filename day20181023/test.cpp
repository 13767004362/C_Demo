//Created by $HeXinGen on 2018/10/23.

//本案例：理解指针,指向指针的指针
#include <iostream>

using namespace std;

int main() {
    //声明变量
    int c = 10;
    //输出变量的内存地址
    cout << "输出，变量c的内存地址：" << &c << endl;
    //声明指针
    int *pointer_c;
    //声明，指向指针的指针
    int  **pointer_pointer_c;
    //赋值：将变量的内存地址赋值给指针变量。
    pointer_c = &c;
    //赋值：将指针的内存地址，赋值给指向指针的指针变量
    pointer_pointer_c=&pointer_c;
    //输出指针变量对应的内存地址
    cout << "输出，指针变量pointer_c：" << pointer_c << endl;
    cout << "输出，指向指针的指针变量pointer_pointer_c：" << pointer_pointer_c << endl;
    //输出指针（即对应内存地址）指向的值。
    cout << "输出，指针变量pointer_c指向的值：" << *pointer_c << endl;
    cout << "输出，指向指针的指针变量pointer_pointer_c 指向的值：" << **pointer_pointer_c << endl;
    return 0;
}

