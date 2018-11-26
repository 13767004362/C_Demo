//Created by $HeXinGen on 2018/11/26.
//
#include <iostream>
using  namespace std;
/**
 *  inline关键字 定义内联函数，max()比较最大值
 */
inline int  max(int a,int b){
    return a>b?a:b;
}
class  Worker{
     int age;// 默认被private修饰
public:
    //声明一个函数
    void setAge(int age);
    //friend关键字声明一个友联函数
    friend void printAge(Worker worker);
};
/**
 * 定义Worker类中成员函数setAge()
 * 必须是类名::方法名形式
 */
void Worker::setAge(int age) {
    this->age=age;
}
/**
 *  printAge()是Worker中友联函数函数，没有this指针，
 *  但可以访问private或者protected修饰的属性
 */
void  printAge(Worker worker) {
    cout<<"Worker的age:"<<worker.age<<endl;
}
int main(){
    //测试内联函数
    cout<<" 1和2两者 , 最大值是:"<<max(1,2)<<endl;
    //测试友联函数
     Worker worker;
     worker.setAge(24);
     printAge(worker);
    return 0;
}
