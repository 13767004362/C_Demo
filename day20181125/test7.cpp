//Created by $HeXinGen on 2018/11/26.
//
#include <iostream>
using  namespace std;
/**
 *  inline�ؼ��� ��������������max()�Ƚ����ֵ
 */
inline int  max(int a,int b){
    return a>b?a:b;
}
class  Worker{
     int age;// Ĭ�ϱ�private����
public:
    //����һ������
    void setAge(int age);
    //friend�ؼ�������һ����������
    friend void printAge(Worker worker);
};
/**
 * ����Worker���г�Ա����setAge()
 * ����������::��������ʽ
 */
void Worker::setAge(int age) {
    this->age=age;
}
/**
 *  printAge()��Worker����������������û��thisָ�룬
 *  �����Է���private����protected���ε�����
 */
void  printAge(Worker worker) {
    cout<<"Worker��age:"<<worker.age<<endl;
}
int main(){
    //������������
    cout<<" 1��2���� , ���ֵ��:"<<max(1,2)<<endl;
    //������������
     Worker worker;
     worker.setAge(24);
     printAge(worker);
    return 0;
}
