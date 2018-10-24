//Created by $HeXinGen on 2018/10/24.

//定义模板，方法
#include <iostream>
#include <string>
using namespace std;
//定义一个模板的比较大小的方法,typename用于引入模板，与class等同
template <typename T> inline T const & Max (T const& a,T const& b){
    return a<b?a:b;
}
int main(){
    //声明两个int类型的变量
    int a=1;
    int b=2;
    cout<<"调用定义的模板比较大小的方法Max(),对("<<a<<","<<b<<")两个者进行比较,最大值是："<<Max(a,b)<<endl;
    //声明两个string类型的变量
    string c="HXG";
    string d="HeXinGen";
    cout<<"调用定义的模板比较大小的方法Max(),对("<<c<<","<<d<<")两个者进行比较,最大值是："<<Max(c,d)<<endl;
    return 0;
}

