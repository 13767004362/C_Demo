//Created by $HeXinGen on 2018/11/26.
//
#include <iostream>

using namespace std;

class Worker {
    char tag[50] = {"c++ ���г�Ա����Ĭ����private����"};//privateֻ�ܱ������з���
protected: //������Է���
    int age = 24;
};
class C_Worker : public Worker {
public :
    void work();//����һ��work()����
};
void C_Worker::work() {
    //���ʸ�����protected���ε�age����
    cout << "������һ��C++�����ߣ�����" << age << endl;
}
int main() {
    //���������
    C_Worker cWorker;
    cWorker.work();
    return 0;
}
