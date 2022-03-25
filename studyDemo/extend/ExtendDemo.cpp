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
    return 0;
}