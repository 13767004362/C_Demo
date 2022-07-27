/**
 * @author ： HeXinGen
 * @date ： 2022/5/25
 * @description ：
 */

#include <iostream>
#include <cstring>
#include <vector>
using  namespace std;

/**
 *  方法中的参数可以设置默认值，当调用方法时，没有传值会使用默认值
 * @param w
 * @param h
 */
void testArea(int w,int h=100){
    int area=w*h;
    cout<<" area :" <<area<<endl;
}
int getArrayLength(int *a ){
    int  length=0;
    while (*a){
        cout<<*a<<endl;
        a++;
        length++;
    }
    return  length;
}
int  testReference(int * array  ){
    int length=getArrayLength(array) ;
    array[length-1]=12;
    return  length;
}

void testReference(){
     int a [2]={1,2};
     int i=testReference(a);
     cout<<a[i-1]<<endl;
}


int  main(){
   // testArea(2);testArea(1,10);
    testReference();

    return 0;
}