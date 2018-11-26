//Created by $HeXingGen on 2018/11/23.
//
#include <iostream>
#include <string>
using namespace std;
//声明 函数func()
string func();

int main() {
    //函数 func() 的调用
    string result=func();
    cout <<result<<endl;
    return 0;
}
//定义 函数func()
string func(){
    return " 函数func()的返回值";
}
