//Created by $HeXinGen on 2018/10/23.

//��������������Ϊ�����Ĳ����ͷ���ֵ
#include <iostream>

using namespace std;
//����һ��ȫ�ֵ�����
int array[3] = {10, 100, 1000};
//����һ�������ĺ���
int &inCrease(int &a);
int main() {
    //��������ֵ
    for (int i = 0; i < 3; ++i) {
        cout << "���� ��" << i << "�Ǳ��ֵ��" << array[i] << endl;
    }
    cout << "����ִ����������..................." << endl;
    for (int i = 0; i < 3; ++i) {
        cout << inCrease(array[i]) << "  , �����е�" << i << "�Ǳ��ֵ��" << array[i] << endl;
    }
    return 0;
}
int &inCrease(int &a) {
    ++a;
    static int result =a;
    cout << "�������صĽ��:" << result;
    return result;
};

