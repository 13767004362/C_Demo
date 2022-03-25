/**
 * @author ： HeXinGen
 * @date ： 2021/6/15
 * @description ：
 */

#include "OverloadDemo.h"
#include <iostream>

using namespace std;
/**
 * =,+预算符重载
 */
void test() {
    Plus plus1, plus2(100);
    //执行运算重载
    plus1 = 10;
    //执行+运算重载
    Plus plus3 = plus1 + plus2;
    plus1.plus();
    plus2.plus();
    plus3.plus();
}

/**
 * 输入/输出运算符重载
 */
void test2() {
    string msg = " test ostream << ";
    Print print(msg);
    cout << print;
}


void test3(){
    SimplePointer<int> simplePointer(new int(100));
    int * iIpointer=*simplePointer;
    int value= **simplePointer;
    cout<< " SimplePointer :"<< iIpointer<<" value: "<<value;
}

int main() {
    // test();
   // test2();
    test3();
    return 0;
}