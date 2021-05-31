/**
 * @author ： HeXinGen
 * @date ： 2021/5/31
 * @description ：
 */

// 引入头文件
#include "NamespaceDemo.h"
//引入iostream 库
#include <iostream>
//使用std的命名空间
using namespace std;

//声明方法，接下来会使用到
void testNameSpaces1();

void testNameSpaces2();

int main() {
    testNameSpaces1();
    testNameSpaces2();
    return 0;
}
/**
 * 使用using 命名空间名称::成员, 方式
 */
void testNameSpaces1() {
    //指定最大的区域范围
    area::maxWidth = area::maxHeight = 100;
    //指定
    area::Area area1(200, 50);
    int multiply = area1.multiply();
    cout << "testNameSpaces1() "<<"\n"<<"multiply: " << multiply<<endl;
}
/**
 * using namespace 命名空间名称 方式
 */
void testNameSpaces2() {
    using namespace area;
    cout << "testNameSpaces2(): "<<endl ;
    // 检查 命名空间中area中的变量值是否存在于全局中
    cout<< "origin width and height :"<<maxWidth<<" , "<<maxHeight<<endl;
    cout << "multiply:"<<calculation(100, 100, 50, 500)<<endl;
}