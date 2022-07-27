/**
 * @author ： HeXinGen
 * @date ： 2022/5/25
 * @description ： 控制程序流向
 */
#include "ConditionDemo.h"
#include <iostream>

using namespace std;

int main() {
    //testIfOrElse();
    // testSwitch();
    //testGoto();
    testDoWhile();
    return 0;
}

/**
 *  if(condition) else()  当condition不为0(正数或者负数)时，条件为true
 */
void testIfOrElse() {
    char c = '\0';// 初始化 字节
    cin >> c;//控制台输出
    char test_c = 'c';
    if (c == test_c) {
        cout << "input value  equal 'c'" << endl;
    } else if (c == 'a') {
        cout << "input value  equal 'a'" << endl;
    } else {
        cout << "input value not equal 'c' or 'a'" << endl;
    }
}

/**
 * switch 语句和枚举结合使用
 *
 */
void testSwitch() {
    enum Cond { //定义一个枚举
        one = 1,
        two, //默认自增
        three,
    };
    int i = 0;
    cin >> i;
    switch (i) {
        case Cond::one:
            cout << "input value  equal 1" << endl;
            break;
        case Cond::two:
            cout << "input value  equal 2" << endl;
            break;
        case Cond::three:
            cout << "input value  equal " << three << endl;
            break;
        default:
            cout << "input value  is  " << i << endl;
            break;
    }
}
/**
 *  start:
 *      repeat code //重复执行的代码
 *     goto  start;
 *
 *  goto 会跳转回到 start开始位置，不推荐使用。
 */
void testGoto() {
    start :
    char c = '\0';
    cin >> c;// 控制台输入
    if (c == 'c') {
        cout << " do  goto    condition  " << endl;
        goto start;
    } else {
        cout << " break goto     " << endl;
    }
}
/**
 *  do{  } while()  至少执行一次
 */
void testDoWhile(){
    char c ='1';
    do{
        cout << "input value  equals  "<<c << endl;
        cin>>c;
    }while (c=='c');
    cout << "input value  is "<<c << endl;
}
