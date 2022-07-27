/**
 * @author ： HeXinGen
 * @date ： 2021/6/15
 * @description ：
 */

#include "PolymorphismDemo.h"

/**
 *  多态问题
 */


void test() {
    Man man;
    Person *person = &man;
// 测试早期绑定
    person->sayHello();
    //测试后期绑定
    person->work();

}

void test1(){
    Person * person=new Man();
    delete person;
}


int main() {
    test();
    test1();
    return 0;
}

