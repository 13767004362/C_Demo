//Created by $HeXinGen on 2018/10/24.
//���������������飬��ʼ�����Ǳ��ȡֵ
#include <iostream>
using  namespace std;
#include <iomanip>
using  std::setw;
const  int  size=3;
int main(){
    int array[size];
    for (int i = 0; i < size; ++i) {
        array[i]=10+i;
    }
    //ʹ��setw()�����ո����
    cout<<"�Ǳ�"<<setw(13)<<"ֵ"<<endl;
    for (int j = 0; j < size; ++j) {
        cout<<setw(2)<<j<<setw(15)<<array[j]<<endl;
    }
    return 0;
}


