//Created by $HeXinGen on 2018/10/23.

//��������ָ���뺯����ָ��������
#include <iostream>
using namespace std;
//����һ������,ָ����Ϊ����������ֵΪָ��
int *calculation(int *pointer, int size);
int main() {
    int array[3] = {1, 2, 3};
    int *a1;
    int *a2;
    // ָ���е������ַ
    a1 = array;
    //ִ���߼�����
    a2 = calculation(a1, 3);
    cout << "�����ִ�м�����ָ��:" << a2 << endl;
    cout << "�����ִ�м�����ָ��ָ���ֵ:" << *a2 << endl;
}
int *calculation(int *pointer, int size) {
     int *result;
    for (int i = 0; i < size; ++i) {
        cout << "���,ָ�룺" << pointer << " ָ��ָ���ֵ��" << *pointer << endl;
        //��ȡ���������һ��Ԫ�ص��ڴ��ַ
        if (i == size - 1) {
            result = pointer;
        }
        pointer++;
    }
    return result;
}

