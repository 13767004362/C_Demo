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
    Person(string name, int age);//�������캯��
    ~Person();//������������
    void toString(){
        cout<<"Person����Ϣ��name��:"<< name<<" , age:"<<age<<endl;
    }
};
/**
 *  ʹ�ó�ʼ���б�����ʼ���ֶ�
 * @param name
 */
Person::Person(string name, int age) : name(name), age(age) {
    cout << "Person��Ĺ��췽���������Գ�ʼ����ֵ" << endl;
}

Person::~Person() {
    cout << "Person�����������,�ͷ���Դ" << endl;
}

int main() {
     Person person("HeXinGen",24);
     person.toString();
    return 0;
}