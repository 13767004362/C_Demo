//Created by $HeXinGen on 2018/10/23.

//�����������ָ��,ָ��ָ���ָ��
#include <iostream>

using namespace std;

int main() {
    //��������
    int c = 10;
    //����������ڴ��ַ
    cout << "���������c���ڴ��ַ��" << &c << endl;
    //����ָ��
    int *pointer_c;
    //������ָ��ָ���ָ��
    int  **pointer_pointer_c;
    //��ֵ�����������ڴ��ַ��ֵ��ָ�������
    pointer_c = &c;
    //��ֵ����ָ����ڴ��ַ����ֵ��ָ��ָ���ָ�����
    pointer_pointer_c=&pointer_c;
    //���ָ�������Ӧ���ڴ��ַ
    cout << "�����ָ�����pointer_c��" << pointer_c << endl;
    cout << "�����ָ��ָ���ָ�����pointer_pointer_c��" << pointer_pointer_c << endl;
    //���ָ�루����Ӧ�ڴ��ַ��ָ���ֵ��
    cout << "�����ָ�����pointer_cָ���ֵ��" << *pointer_c << endl;
    cout << "�����ָ��ָ���ָ�����pointer_pointer_c ָ���ֵ��" << **pointer_pointer_c << endl;
    return 0;
}

