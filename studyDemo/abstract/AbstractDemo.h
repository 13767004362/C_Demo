/**
 * @author ： HeXinGen
 * @date ： 2021/6/15
 * @description ：
 */

#ifndef DEMO_ABSTRACTDEMO_H
#define DEMO_ABSTRACTDEMO_H

#include "string"
#include <iostream>
using namespace std;

/**
 * 在c++中，接口是通过抽象类来实现的，
 * 抽象类中必须至少有一个纯虚函数。
 * 不能实例化的基类被称为抽象基类，用于派生其他类。
 */
class Worker {

protected:
    string name;
public:
    /**
     * 声明一个纯虚函数，格式为： virtual void funtion1()=0
     * @param n
     */
     virtual  void setName(string & n)=0;
      void work(){
          cout<<this->name<<" is Work"<<endl;
      };
};

class WorkerImpl: public Worker{

public:
    /**
     * override 可用于
     * 检查基类函数是否是虚函数；
     * 派生类函数与基类的函数是否相同(例如是否添加const 修饰)
     * @param n
     */
   void setName(string & n) override {
       this->name=n;
    }
};


#endif //DEMO_ABSTRACTDEMO_H
