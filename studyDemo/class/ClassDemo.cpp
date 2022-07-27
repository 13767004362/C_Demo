/**
 * @author ： HeXinGen
 * @date ： 2021/6/9
 * @description ：
 */

#include "ClassDemo.h"

#include "SafeCopy.h"
#include "SingleObject.h"
#include <iostream>
#include "string"

using namespace std;
/**
 * 句点运算符(.)来访问类的成员和方法
 *
 * 类包含原始指针成员(char * 等)，必须编写复制构造函数和复制赋值运算符，进行深度拷贝。
 *
 * this 包含当前对象的地址，换句话说，其&object
 */

void testClass() {
    string name = "HeXinGen";
    int age = 28;
    //使用动态内存
    Worker *worker1 = new Worker;
    worker1->setAge(age);
    worker1->setName(name);
    worker1->toString();

   string&  n= worker1->getName();
    //手动释放内存
    delete worker1;

    //测试构建函数，执行初始化列表
    Worker(age, name);
}

void testFriend(){
    Persion persion;
    string name="HeXinGen";
    persion.setName(name);
    Man man;
    man.updateGender(persion);
    printPersonMsg(persion);
}


void testCopyClassPointer() {
    //测试深度拷贝，
    Copy copy;
    copy = "djlfsjdjfls";
    Copy copy1(&copy);
    cout << "copy pointer:" << copy.getName() << " ," << copy1.getName() << endl;
    //测试静态 ，通过 类名::方法/变量
    cout<< " static var: "<<Copy::getTotal()<<endl;
}



int main() {
    //testClass();
    //testCopyClassPointer();
    //testFriend();
    //testPerson();
    testSingleObject();

    return 0;
}