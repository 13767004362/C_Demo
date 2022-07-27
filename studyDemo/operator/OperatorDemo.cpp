/**
 * @author ： HeXinGen
 * @date ： 2022/5/25
 * @description ：
 */
#include "OperatorDemo.h"
#include <iostream>
using  namespace std;



int main(){
    test2Operator();
    testIncrementOperator();
    testComplexOpt();
    testSizeOfOpt();
    return 0;
}

/**
 * << 左移预算符号，乘以2的倍数
 * >> 右移运算符，除以2的倍数
 */
void test2Operator(){
    int i_1=10<<2;
    cout<<"<<2= "<<i_1<<endl;
    int i_2=10>>2;
    cout<<">>2= "<<i_2<<endl;
}
/**
 * ++1 自增在前，先自增后赋值；
 */
void testIncrementOperator(){
    int a=1,b=1;
    int c=++a;
    int d=b++;
    cout<<"++1  "<<c<<endl;
    cout<<"1++  "<<d<<endl;
}
/**
 * 复合赋值运算符， 先进行运算后赋值
 */
void testComplexOpt(){
    int a=1,b=4;
    //加法赋值运算法
    b+=a;
    cout<<"+=  "<<b<<endl;

    int c=1;
    int d=3;
    //右移赋值运算符
    d>>=c;
    cout<<">>=  "<<d<<endl;
}
/**
 * sizeOf 测试 数据类型/变量占用内存的字节数
 * sizeOf(type) 或者sizeOf(variable)
 */
void testSizeOfOpt(){
    int i= sizeof(int);// 一个int 类型是4个字节
    int  is_array [5]={0};
    int i1= sizeof(is_array);// 5个int 类型是 5*4=20
    int i2= sizeof(is_array[0]);
    cout<<"sizeOf   "<<i<<" , "<<i1<<", "<<i2<<endl;

}