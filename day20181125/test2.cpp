//Created by $HeXinGen on 2018/11/26.
//
#include <iostream>
using namespace std;
class Worker {
   public :
       void work();//����һ��work()����
};
/**
 * ��Χ��������� ::  ,�����ⲿ���庯��
 */
void Worker::work() {
    cout << "C++������";
}
int main() {
    //���������
    Worker worker;
    worker.work();
    return 0;
}
