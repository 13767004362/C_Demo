//Created by $HeXinGen on 2018/11/26.
//

#include <iostream>
#include <string>
using namespace std;

class Person {
 protected:
    string name;
    int age;
 public :
    Person(string name, int age);//声明构造函数
    ~Person();//声明析构函数
    void toString(){
        cout<<"Person中信息，name是:"<< name<<" , age:"<<age<<endl;
    }
};
/**
 *  使用初始化列表来初始化字段
 * @param name
 */
Person::Person(string name, int age) : name(name), age(age) {
    cout << "Person类的构造方法，对属性初始化赋值" << endl;
}

Person::~Person() {
    cout << "Person类的析构函数,释放资源" << endl;
}

int main() {
     Person person("HeXinGen",24);
     person.toString();
    return 0;
}