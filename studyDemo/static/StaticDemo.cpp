/**
 * @author ： HeXinGen
 * @date ： 2021/10/28
 * @description ：
 */
#include "StaticDemo.h"
#include <iostream>
#include "StaticTest.h"
using namespace std;

int main(){
    while ((j--)>0){
        reduece();
    }
    return 0;
}
void reduece(){
    static  int temp=0;
    temp++;
    int s=j;
    cout<<"static Global variable: "<< s <<endl;
    //cout<<" memory address："<< &j ;
    cout<<" static local variable："<< temp <<" memory address：" << &temp <<endl;
}