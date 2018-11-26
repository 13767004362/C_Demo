//Created by $HeXingGen on 2018/11/25.
//

#include <iostream>
#include <string>

using namespace std;

//#define 预处理器

#define  constant_str "#define预处理器定义常量";

// extern 声明一个const修饰的常量
extern  const  int three;

int main() {
    //const 定义常量
    const int second = 2;
    // const 定义 常量，与extern修饰的常量是同一个。
    const  int three=3;
    cout << constant_str;
    cout << "\n" << "const 关键字定义常量 ，其值是：" << second << endl;
    cout<<"extern 声明，const修饰的常量，其值是: "<<three<<endl;
    return 0;
}