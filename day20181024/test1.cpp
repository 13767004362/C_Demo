//Created by $HeXinGen on 2018/10/24.
//����ά���飬�����Զ�ά����Ϊ����
#include <iostream>
using  namespace std;

#include <iomanip>
using std::setw;
int main(){
    /**
     *  ��ʼ��һ����ά���飬��Ƕ���ſ���ʡ�ԣ�
     *  ��ͬ�� ��  int array[2][2]={1,11,111,1111};
     */
    int array[2][2]={{1,11},{111,1111}};
    cout<<"��ӡһ����ά����"<<endl;
    for (int i = 0; i <2 ; ++i) {
        for (int j = 0; j <2 ; ++j) {
            cout<<"array["<<i<<"]"<<"["<<j<<"]"<<setw(8)<<array[i][j]<<endl;
        }
    }
    return 0;
}
