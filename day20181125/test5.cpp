//Created by $HeXinGen on 2018/11/26.
//
#include <iostream>
#include <string>
using  namespace std;

class  Worker{
  public :
    static int total;//定义一个static修饰的静态属性
    Worker(string name){
        this->name=name;
        cout<<"Worker的name:"<<this->name<<endl;
        total++;
    }
   //定义一个静态方法
    static  int getTotal(){
        return total;
    }
protected:
    string name;
};
//初始化Worker类中静态成员
int Worker:: total=0;

int main(){
     cout<<"Worker中静态属性total："<<Worker::getTotal()<<endl;
     Worker worker1("C++开发者");
    Worker worker2("Java开发者");
    cout<<"Worker中静态属性total："<<Worker::getTotal()<<endl;
    return 0;
}