//Created by $HeXinGen on 2018/10/23.
// ��������C++������
#include <iostream>
using  namespace std;
int main(){
    int a=100;
    int b=110;
    //�������ã���ӶԱ���a�����ã��ҳ�ʼ��
    int& c=a;
    cout<<"������� ��"<<c<<" ,     ���a,bֵ��" <<a<<","<<b<<endl;
    //�޸����ö�Ӧ�ı��������������a����ֵ
    c=b;
    cout<<"������� ��"<<c<<" ,     ���a,bֵ��" <<a<<","<<b<<endl;
    return 0;
}
