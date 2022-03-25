/**
 * @author ： HeXinGen
 * @date ： 2021/6/15
 * @description ：
 */

#ifndef DEMO_POLYMORPHISMDEMO_H
#define DEMO_POLYMORPHISMDEMO_H

#include <iostream>
using namespace  std;

class Person {
public:
    void sayHello(){
        cout<<"person say hello "<<endl;
    }
    /**
     * 声明为virtual 虚函数，用于解决子类重写方法的，实现动态链接/后期绑定。
     */
   virtual void work(){
        cout<<"person is work "<<endl;
   }
};

class Man: public Person{
public:
    void sayHello(){
        cout<<"man say hello "<<endl;
    }

    void work(){
        cout<<"man is work "<<endl;
    }
};


#endif //DEMO_POLYMORPHISMDEMO_H
