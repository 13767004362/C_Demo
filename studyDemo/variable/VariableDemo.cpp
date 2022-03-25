/**
 * @author ： HeXinGen
 * @date ： 2021/11/10
 * @description ：
 */
#include <iostream>
#include <string>
#include <typeinfo>
#include "ConstDemo.h"

using namespace std;

/**
 * 用sizeOf（） 获取变量的长度
 */
void testSizeOf() {
    cout << "bool length:" << sizeof(bool) << endl;
    cout << "int length:" << sizeof(int) << endl;
    cout << "unsigned int :" << sizeof(unsigned int) << endl;
    cout << "long length:" << sizeof(long) << endl;
    cout << "long long length:" << sizeof(long long) << endl;
}

/**
 * auto 定义自动类型，但必须初始化
 * typeid() 获取变量的信息
 */
void testAuto() {
    auto b = true;
    auto l = 10000000;
    long l2 = 0;
    //自定义自动类型,且输出相应的类型
    cout << b << " class is: " << typeid(b).name() << endl;
    cout << l << " class is: " << typeid(l).name() << endl;
    cout << l2 << " class is: " << typeid(l2).name() << endl;
}

/**
 * typedef:重新定义变量类型的名字 ，
 * 好处：一个更具描述性的名称
 */
void testTypedef() {
    typedef int I;//将int 类型 定义成 I
    I i = 100;
    cout << i << " class is: " << typeid(i).name() << endl;
    typedef string Str; //将string 类型定义成Str
    Str str = "string type rename String";
    cout << str << " class is: " << typeid(str).name() << endl;
}
/**
 * 测试常量
 *
 * 在 C++中，常量可以是：
 * 1.使用关键字 const 声明的常量；
 * 2.使用关键字 constexpr 声明的常量表达式（C++11 新增的）；
 * 3.使用关键字 enum 声明的枚举常量；
 * 4.使用#define 定义的常量（已摒弃，不推荐）。
 */

void testConstants(){

    cout<<"const define :"<<i<<endl;
    cout<<"constexpr define :"<<area()<<endl;
    cout<<"enum define :"<<position_1000<<endl;
    cout<<"#define :"<<i_10000;
}

int main() {
    testSizeOf();
    testAuto();
    testTypedef();
    testConstants();
    return 0;
}