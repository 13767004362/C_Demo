//Created by $HeXinGen on 2018/11/25.
//
#include <iostream>
using namespace std;
int main() {
    int i = 1, j = 2;
    // if  ...else ���
    if (i > j) {
        cout << " 1 ����2 ������Ϊ��" << endl;
    } else {
        cout << " 1����2 �� ����Ϊ��" << endl;
    }
    //Ƕ��switch ���
    switch (i) {
        case 1: {
            cout << " i��ֵ����" << i << endl;
            switch (j) {
                case 2:
                    cout << " j��ֵ����" << j << endl;
                    break;
                default:
                    break;
            }
        }
            break;
        default:
            break;

    }
    // ��Ԫ�����
    cout<< " i > j "<<(i>j? true:false)<<endl;
    return 0;
}
