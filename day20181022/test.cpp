//Created by $HeXinGen on 2018/10/22.

//���������Զ��������ռ䣬�������ռ��ʹ��
#include <iostream>
using  namespace std;

//�Զ����һ�������ռ�
namespace FirstNameSpace{
    void firstTest(){
        cout<< "�Զ����һ�������ռ�:FirstNameSpace"<<endl;
    }
}
//�Զ���ڶ��������ռ�
namespace  SecondNameSpace{
    void secondTest(){
        cout<< "�Զ���ڶ��������ռ�:SecondNameSpace"<<endl;
    }
}
//�����Զ���������ռ� FirstNameSpace
using  namespace FirstNameSpace;

int main (){
    //ʹ��using namespace xxx�ķ�ʽ����ֱ�ӿ���ʹ�������ռ��µ��࣬������������
    firstTest();
    //�ڶ������÷�ʽ�� name::code;  code �����Ǳ�������
    SecondNameSpace::secondTest();
    return 0;
}

