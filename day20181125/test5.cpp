//Created by $HeXinGen on 2018/11/26.
//
#include <iostream>
#include <string>
using  namespace std;

class  Worker{
  public :
    static int total;//����һ��static���εľ�̬����
    Worker(string name){
        this->name=name;
        cout<<"Worker��name:"<<this->name<<endl;
        total++;
    }
   //����һ����̬����
    static  int getTotal(){
        return total;
    }
protected:
    string name;
};
//��ʼ��Worker���о�̬��Ա
int Worker:: total=0;

int main(){
     cout<<"Worker�о�̬����total��"<<Worker::getTotal()<<endl;
     Worker worker1("C++������");
    Worker worker2("Java������");
    cout<<"Worker�о�̬����total��"<<Worker::getTotal()<<endl;
    return 0;
}