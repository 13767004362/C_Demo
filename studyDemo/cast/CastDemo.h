/**
 * @author ： HeXinGen
 * @date ： 2022/6/6
 * @description ：
 */#ifndef DEMO_CASTDEMO_H
#define DEMO_CASTDEMO_H

#include <iostream>
using  namespace std;

void testStaticCast();
void testConstCase();

void testDynamicCast();

class Base{
public:
    virtual void print(){
        cout<<" this is base class print method "<<endl;
    }
};
class  Impl :public  Base{
public:
    void print(){
        cout<<" this is impl class print method "<<endl;
    }
};


#endif //DEMO_CASTDEMO_H
