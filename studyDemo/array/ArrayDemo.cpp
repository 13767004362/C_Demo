/**
 * @author ： HeXinGen
 * @date ： 2021/6/18
 * @description ：
 */

#include "ArrayDemo.h"
#include <iostream>
#include "cstring"
using  namespace  std;

/**
 * 一个固定大小的相同类型元素的顺序集合。数组是用来存储一系列数据
 * 声明格式： type arrayName [ arraySize ]
 *
 * 注意点：[]省略掉了数组的大小，数组的大小则为初始化时元素的个数.
 */
void testArray(){
    //声明一个数量为3的char数组，且使用一个初始化语句。
    char array[size]{'h','x','g'};
    cout<< " array[ ";
    for (int i = 0; i < size; ++i) {
        cout<< array[i];
        if (i<size-1) {
            cout << ",";
        }
    }
    cout<<"]"<<endl;

    //.......................案例2

    // 声明 一个数量为3的char数组
    char array1[size];
    for (int i = 0; i <size ; ++i) {
        array1[i]=i+'0';
    }
    cout<< " array1[ ";
    for (int i = 0; i < size; ++i) {
        cout<< array1[i];
        if (i<size-1) {
            cout << ",";
        }
    }
    cout<<"]"<<endl;
    //.......................案例3
    // 声明一个数量为1的数组
    char  array2[]={'h'};
    //sizeOf 计算 数组的长度，不受内容多少的影响
    int s=sizeof(array2);
    cout<< " array2[ ";
    for (int i = 0; i < s; ++i) {
      cout<< array2[i];
      if (i<s-1) {
          cout << ",";
      }
    }
    cout<<"]"<<endl;
    //.......................案例4
    //将字符串给char 数组赋值时，长度需多加1。
    char  array3[size+1]="hxg";
    // strlen 计算真实的字符串的长度
    s=strlen(array3);
    cout<< " array3[ ";
    for (int i = 0; i < s; ++i) {
        cout<< array3[i];
        if (i<s-1) {
            cout << ",";
        }
    }
    cout<<"]"<<endl;

}

void testArray2(){
    //数组名是指向第一个元素的常量指针，即 array 是指向 &array[0]的指针。
    char array[size]={'h','x','g'};
    cout<<&array<<" value:"<<*array;

}

int main(){
   // testArray();
   testArray2();
    return 0;
}