//Created by $HeXingGen on 2018/11/25.
//
#include <iostream>
using  namespace std;

void reduce();

static int i=5;

int main(){
    while ((i--)>0){
        reduce();
    }
    return 0;
}

void reduce(){
    int z=0;
    static int j=0;
    j++;
    z++;
    cout<<" 局部变量 z,其值是："<<z<<" ,内存地址是："<<&z<<endl;
    cout<<" static 修饰的局部变量 j,其值是："<<j<<" ,内存地址是："<<&j<<" 。 ";
    cout<<" static 修饰的全局变量 i,其值是："<<i<<" ,内存地址是："<<&i<<" 。 "<<endl;
}

