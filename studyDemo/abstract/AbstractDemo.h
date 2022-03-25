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
   void setName(string & n){
       this->name=n;
    }
};


#endif //DEMO_ABSTRACTDEMO_H
