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
        //thisָ�룬ָ���������
        this->name = name;
    }
    void toString(){
        //thisָ�룬ָ����ĺ���
        cout<<"Worker�е�name��"<<this->getName()<<endl;
    }
};
int main() {
    string name="HeXinGen";
     Worker  worker(name);
     //������ڴ��ַ��ֵ��ָ�����
     Worker * worker_pointer=&worker;
    //ָ�����ָ��
     worker_pointer->toString();
    return 0;
}