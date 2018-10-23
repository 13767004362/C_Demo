//Created by $HeXinGen on 2018/10/23.

//本案例：指针与函数，指针与数组
#include <iostream>
using namespace std;
//声明一个函数,指针作为参数，返回值为指针
int *calculation(int *pointer, int size);
int main() {
    int array[3] = {1, 2, 3};
    int *a1;
    int *a2;
    // 指针中的数组地址
    a1 = array;
    //执行逻辑计算
    a2 = calculation(a1, 3);
    cout << "输出，执行计算后的指针:" << a2 << endl;
    cout << "输出，执行计算后的指针指向的值:" << *a2 << endl;
}
int *calculation(int *pointer, int size) {
     int *result;
    for (int i = 0; i < size; ++i) {
        cout << "输出,指针：" << pointer << " 指针指向的值：" << *pointer << endl;
        //获取到数组最后一个元素的内存地址
        if (i == size - 1) {
            result = pointer;
        }
        pointer++;
    }
    return result;
}

