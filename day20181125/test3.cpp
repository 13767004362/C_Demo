//Created by $HeXinGen on 2018/11/26.
//
#include <iostream>

using namespace std;

class Worker {
    char tag[50] = {"c++ 类中成员属性默认是private修饰"};//private只能被该类中访问
protected: //子类可以访问
    int age = 24;
};
class C_Worker : public Worker {
public :
    void work();//声明一个work()函数
};
void C_Worker::work() {
    //访问父类中protected修饰的age属性
    cout << "本人是一名C++开发者，年龄" << age << endl;
}
int main() {
    //定义类对象
    C_Worker cWorker;
    cWorker.work();
    return 0;
}
