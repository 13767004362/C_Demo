//Created by $HeXinGen on 2018/11/25.
//

#include <iostream>
#include <string>
#include <cstring>
using  namespace std;

/**
 * 定义一个数据结构，结构对象为data
 */
struct  Data{
    char name[16];
    int age;
} data;

int main(){
    // sizeOf() 获取变量的字节大小
    cout<<" int 类型的字节大小 ："<< sizeof(int)<< ", int类型的变量的字节大小 ："<< sizeof(100)<<endl;

    //条件运算符 ?  :
    int result_bool=(1>0)? true:false;
    cout<<" 1>0?true:false三元运算符 ："<<result_bool<<endl;

    // ,逗号运算符,按顺序执行，获取最后一个结果
    int i=9,j;
    j=(i++,i*i);//先i++,后执行j=i*i;
    cout<<" 逗号运算符，最后计算出的结果是："<<j<<endl;

    //强制转换运算符
    double  d=20.111;
    int result_int=(int)d;
    cout<<"double强制转int，20.111对应的int类型的值是："<<result_int<<endl;

    //.点号运算符
    strcpy(data.name,"c++开发者");
    cout<<" 点号运算符,进行赋值操作，name为; "<<data.name<<endl;

    //->箭头运算符，&运算符 *指针运算符
    struct  Data * data_pointer=&data;
    data_pointer->age=24;
    cout<<" ->箭头运算符 ,进行赋值操作，age为; "<<data_pointer->age<<endl;
    return  0;
}

