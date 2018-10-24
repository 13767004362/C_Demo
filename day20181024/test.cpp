//Created by $HeXinGen on 2018/10/24.
//本案例：声明数组，初始化，角标获取值
#include <iostream>
using  namespace std;
#include <iomanip>
using  std::setw;
const  int  size=3;
int main(){
    int array[size];
    for (int i = 0; i < size; ++i) {
        array[i]=10+i;
    }
    //使用setw()函数空格输出
    cout<<"角标"<<setw(13)<<"值"<<endl;
    for (int j = 0; j < size; ++j) {
        cout<<setw(2)<<j<<setw(15)<<array[j]<<endl;
    }
    return 0;
}


