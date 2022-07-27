/**
 * @author ： HeXinGen
 * @date ： 2021/6/15
 * @description ：
 */

#ifndef DEMO_EXTENDDEMO_H
#define DEMO_EXTENDDEMO_H

#include <iostream>
#include "string"

using namespace std;

class Person {
protected:
    string name;
public:
    Person(string  &n) {
        this->name = n;
    }

    string &getName() {
        return name;
    }
    void print(){
        cout<<" this is person print method "<<endl;
    }
};
/**
 * 在C++中是可以多继承，可以有多个父类
 * class <派生类名>:<继承方式1><基类名1>,<继承方式2><基类名2>,…
 * {
 *   <派生类类体>
 * };
 *
 * 当多个父类中，有重合父类时候，使用virtual 虚拟继承方式解决。
 *
 * 修饰符 ：private(默认)、protected,修饰父类，不能对象多态,外部不可以通过派生类对象访问父类中公开方法和属性。
 * 使用public修饰父类，才可以父类=子类的引用/指针。
 */
class Man : public Person {
public:
    Man(string  & name):Person(name){

    }

    void print(){
        cout<<" this is Man print method "<<endl;
    }
};

#endif //DEMO_EXTENDDEMO_H
