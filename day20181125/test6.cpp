//Created by $HeXinGen on 2018/11/26.
//

#include <iostream>
#include <string>
using namespace std;

class Worker {
private:
    string name;
protected:
    string getName() {
        return name;
    }
public :
    Worker(string & name) {
        //this指针，指向类的属性
        this->name = name;
    }
    void toString(){
        //this指针，指向类的函数
        cout<<"Worker中的name："<<this->getName()<<endl;
    }
};
int main() {
    string name="HeXinGen";
     Worker  worker(name);
     //将类的内存地址赋值给指针变量
     Worker * worker_pointer=&worker;
    //指向类的指针
     worker_pointer->toString();
    return 0;
}