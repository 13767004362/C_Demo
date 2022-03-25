/**
 * @author ： HeXinGen
 * @date ： 2021/6/15
 * @description ：
 */

#include "PolymorphismDemo.h"


void test() {
    Man man;
    Person *person = &man;
// 测试早期绑定
    person->sayHello();
    //测试后期绑定
    person->work();
}

int main() {
    test();
    return 0;
}

