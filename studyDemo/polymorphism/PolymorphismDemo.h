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
     * 声明为virtual 虚函数,编译器调用的是覆盖重写的方法。
     * 用于解决子类重写方法的，实现动态链接/后期绑定。
     */
   virtual void work(){
        cout<<"person is work "<<endl;
   }
   /**
    * 当子类中重写了析构函数时,为了防止 new子类对象作为父类指针，通过delete 删除父类的指针的操作，
    * 未调用子类的析构函数，造成内存泄漏。
    */
   virtual ~Person(){
       cout<<"person  destroy method  "<<endl;
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
    ~Man(){
         cout<<"man  destroy method  "<<endl;
    }
};


#endif //DEMO_POLYMORPHISMDEMO_H
