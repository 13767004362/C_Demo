//Created by $HeXinGen on 2018/11/26.
//
#include <iostream>
using namespace std;
class Worker {
   public :
       void work();//声明一个work()函数
};
/**
 * 范围解析运算符 ::  ,在类外部定义函数
 */
void Worker::work() {
    cout << "C++开发者";
}
int main() {
    //定义类对象
    Worker worker;
    worker.work();
    return 0;
}
