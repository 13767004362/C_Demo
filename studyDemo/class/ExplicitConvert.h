/**
 * @author ： HeXinGen
 * @date ： 2022/7/6
 * @description ：
 *
 *
 *
 *
 * 带有一个或者多个参数的重载构造函数，可进行"="类型转换。
 *
 *
 * Explict 修饰构造函数，可禁止隐式转换。
 *
 * explict 并非必须的，但这是一种良好的编程风格
 *
 *
 */#ifndef DEMO_EXPLICITCONVERT_H
#define DEMO_EXPLICITCONVERT_H

#include <iostream>
using  namespace std;

class Test1{
private:
    int age=18;
    int id=1;
public:
    Test1(int age):age(age){

    }
    int getAge(){
        return age;
    }
};
void print1(Test1  test1){
    cout<<test1.getAge()<<endl;
}

class Test2{
private:
    int id=1;
public:
    //禁止隐式转换
    explicit Test2(int id):id(id){

    }
    int getId(){
        return id;
    }
};
void print2(Test2  test2){
    cout<<test2.getId()<<endl;
}
static void testTest1(){
     Test1 test1=14; //将int 转成Test1对象
     print1(15);// 系统会进行隐式转换，先将int 转Test1对象，在传入print（）函数中

     // explicit 修饰的构造方法，是禁止隐式转换的。

     Test2 test2(18);//不可以用= 赋值;
     print2(test2);// 不可以直接传入数字;
}

#endif //DEMO_EXPLICITCONVERT_H
