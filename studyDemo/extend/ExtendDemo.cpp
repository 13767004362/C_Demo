/**
 * @author ： HeXinGen
 * @date ： 2021/6/15
 * @description ：
 */

#include "ExtendDemo.h"
#include <iostream>
#include "string"
using namespace std;

int main(){
    string name="man";
    Man man(name);
    Person& person=man;
    cout<<" Person current Name:"<<person.getName()<<endl;
    man.print();
    //调用基类中被覆盖的方法： 使用区域符号 基类::方法
    man.Person::print();
    return 0;
}