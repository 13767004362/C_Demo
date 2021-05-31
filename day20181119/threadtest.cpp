//Created by HeXingGen on 2018/11/19.
#include <iostream>
//�����߳̿�
#include <thread>
//mutex����ȷ���߳�ͬ��
#include <mutex>
using  namespace std;

unsigned int length=1000;
mutex locks;

void  test1(){
    while (true){
        //ʹ��lock_guardͬ���������������ܹ��Զ�������
        lock_guard<mutex> lockGuard(locks);
        if (length>0){
            --length;
            cout<<"test1(),���ֵ��"<<length<<endl;
        }else{
            break;
        }
    }
}
void  test2(){
    while (true){
        lock_guard<mutex> lockGuard(locks);
        if (length>0){
            --length;
            cout<<"test2(),���ֵ��"<<length<<endl;
        }else{
            break;
        }
    }
}
int main(){
    thread th1(test1);
    thread th2(test2);
    //����Ҫע������̶߳���ִ����join��Ͳ���join able�ˣ�����ֻ�ܵ���joinһ�Ρ�
    th1.join();
    th2.join();
    cout << "main������MainThraed \n\n";
    return 0;
}
