//Created by $HeXinGen on 2018/10/23.
// 本案例：C++的引用
#include <iostream>
using  namespace std;
int main(){
    int a=100;
    int b=110;
    //声明引用，添加对变量a的引用，且初始化
    int& c=a;
    cout<<"输出引用 ："<<c<<" ,     输出a,b值：" <<a<<","<<b<<endl;
    //修改引用对应的变量（这里，即变量a）的值
    c=b;
    cout<<"输出引用 ："<<c<<" ,     输出a,b值：" <<a<<","<<b<<endl;
    return 0;
}
