//Created by $HeXinGen on 2018/10/24.

//动态内存，new运算符创建动态内存，delete运算符删除new创建的动态内存。
#include <iostream>
using  namespace std;
/**
 * 定义一个类
 */
class Demo{
public:
    Demo(){
        cout<<"调用Demo的构造函数"<<endl;
    }
    ~Demo(){
        cout<<"调用Demo的析构函数"<<endl;
    }
};
//声明一个动态创建类对象的函数
void  dynamicCreateClass();
//声明一个动态创建一维数组的函数
void  dynamicCreateOneDimensionalArray();
//声明一个动态创二维数组的函数
void  dynamicCreateTwoDimensionalArray();

int  main(){
    dynamicCreateOneDimensionalArray();
    dynamicCreateTwoDimensionalArray();
    dynamicCreateClass();
    return 0;
}
void  dynamicCreateOneDimensionalArray(){
    //通过new 关键字，创建一个长度为5，int 类型的数组,分配动态内存
    const  int length=2;
    int * pointer =new int [length];
    cout<<"new运算符动态创建的一维数组,分配的内存地址是: "<<pointer<<endl;
    //逐个赋值
    for (int i = 0; i <length; ++i) {
        pointer[i]=10+i;
    }
    //逐个打印
    for (int j = 0; j < length; ++j) {
        cout<<"一维数组中,第"<<j<<"角标的值是:"<<pointer[j]<<endl;
    }
    // delete 运算符，删除之前由 new 运算符分配的内存
    delete  [] pointer;
    cout<<"delete运算符删除,动态创建的一维数组的内存......."<<endl;
}
void  dynamicCreateTwoDimensionalArray(){
    const  int length=2;
    const  int length2=3;
    //创建一个2行3列的二维数组
    int **pointer=new int *[length];
    for (int i = 0; i <length; ++i) {
        //创建一维有三列的数组
        pointer[i]=new int[length2];
    }
    cout<<"new运算符动态创建的二维数组,分配的内存地址是: "<<pointer<<endl;
    //赋值
    for (int k = 0; k <length ; ++k) {
        for (int i = 0; i <length2 ; ++i) {
            if (k==0){
                pointer[k][i]=100+i;
            }else{
                int add=length2+i;
                pointer[k][i]=100+add;
            }
        }
    }
    //逐个打印
    for (int j = 0; j < length; ++j) {
        for (int i = 0; i < length2; ++i) {
            cout<<"二维数组["<<j<<"]["<<i<<"]"<<"值:"<<pointer[j][i]<<endl;
        }
    }
    //删除二维数组中第二维度
    for (int l = 0; l <length ; ++l) {
        delete [] pointer[l];
    }
    // delete 运算符，删除之前由 new 运算符分配的内存
    delete  [] pointer;
    cout<<"delete运算符删除,动态创建的二维数组的内存......."<<endl;
}
void  dynamicCreateClass(){
    cout<<"new运算符动态创建类对象的内存 "<<endl;
    Demo* pointer=new Demo[2];
    delete [] pointer;
    cout<<"delete运算符删除,动态创建的类对象的内存......."<<endl;
}