/**
 * @author ： HeXinGen
 * @date ： 2021/6/8
 * @description ：
 *  测试lambda 表达式
 *  参考教程：https://www.cnblogs.com/DswCnblog/p/5629165.html
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include "LambdaDemo.h"

using namespace std;

bool cmp(int &a, int &b) {
    return a < b;
}

/**
 *使用 方法进行排序和 lambda表达式
 */
void testLambda() {

    vector<int> verList = {1, 9, 3, 6, 8};
    //拷贝一份
    vector<int> tempList(verList);
    //使用方法进行 进行排序
    sort(verList.begin(), verList.end(), cmp);
    cout << " method sort order: ";
    for (int i:verList) {
        cout << i << " ";
    }
    cout << endl;
    //声明一个lambda表达式： 进行排序
    auto compare = [](int a, int b) -> bool { return a < b; };
    sort(tempList.begin(), tempList.end(), compare);
    // 使用 lambda表达式排序
    cout << " lambda sort order: ";
    for (int i:tempList) {
        cout << i << " ";
    }
    cout << endl;

}

/**
 * lambda 捕获外部的值
 */
void testLambda2() {
    int a = 123;
    //在lambda表达式中使用外部变量a的值
    auto f = [a] { cout << "lambda pass values:" << a << endl; };
    //调用lambda表达式，即函数对象
    a = 12;
    f();
    int b = 10;
    //捕捉lambda表达式外的全部变量的值
    auto f2 = [&] { cout << "lambda pass values, a*b= " << a * b << endl; };
    b = 100;
    f2();
};

/**
 * lambda 捕获外部的变量的引用
 */
void testLambda3() {
    int a = 123;
    //在lambda表达式中使用外部变量a的引用
    auto f = [&a] { cout << "lambda pass reference : " << a << endl; };
    //修改变量的引用
    a = 12;
    //调用lambda表达式，即函数对象
    f();
    int b = 10;
    //捕捉lambda表达式外的全部变量的引用
    auto f2 = [&] { cout << "lambda pass reference, a*b= " << a * b << endl; };
    b = 100;
    f2();
};

/**
 * mutable 修改捕获变量
 */
void testLambda4() {
    int a = 123;
    //在lambda表达式中使用外部变量a的引用
    auto f = [a]() mutable { cout << "lambda mutable var value : " << ++a << endl; };
    f(); // 输出124
    cout << "a :" << a << endl;
    //在修改变量的引用的情况，mutable 修改的值会生效
    auto f2 = [&a]() mutable { cout << "lambda mutable var value : " << ++a << endl; };
    f2();// 输出124
    cout << "a :" << a << endl;
}
/**
 * 测试 lambda 表达式中this
 */
void testLambda5(){
    Product a(10);
    cout<<" 10*20="<< a.calculation(20)<<endl;
}

int main() {
    //testLambda();
    // testLambda2();
    // testLambda3();
    // testLambda4();
    testLambda5();
    return 0;
}