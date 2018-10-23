//Created by $HeXinGen on 2018/10/22.

//本案例：自定义命名空间，和命名空间的使用
#include <iostream>
using  namespace std;

//自定义第一个命名空间
namespace FirstNameSpace{
    void firstTest(){
        cout<< "自定义第一个命名空间:FirstNameSpace"<<endl;
    }
}
//自定义第二个命名空间
namespace  SecondNameSpace{
    void secondTest(){
        cout<< "自定义第二个命名空间:SecondNameSpace"<<endl;
    }
}
//引用自定义的命名空间 FirstNameSpace
using  namespace FirstNameSpace;

int main (){
    //使用using namespace xxx的方式，则直接可以使用命名空间下的类，函数，变量等
    firstTest();
    //第二种引用方式： name::code;  code 可以是变量或函数
    SecondNameSpace::secondTest();
    return 0;
}

