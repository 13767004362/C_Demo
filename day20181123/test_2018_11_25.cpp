//Created by $HeXingGen on 2018/11/25.
//

#include <iostream>
#include <string>

using namespace std;

//#define Ԥ������

#define  constant_str "#defineԤ���������峣��";

// extern ����һ��const���εĳ���
extern  const  int three;

int main() {
    //const ���峣��
    const int second = 2;
    // const ���� ��������extern���εĳ�����ͬһ����
    const  int three=3;
    cout << constant_str;
    cout << "\n" << "const �ؼ��ֶ��峣�� ����ֵ�ǣ�" << second << endl;
    cout<<"extern ������const���εĳ�������ֵ��: "<<three<<endl;
    return 0;
}