//Created by $HeXinGen on 2018/11/25.
//

#include <iostream>
using  namespace std;

int main(){
    for (int i = 0; i <4 ; ++i) {
        if (i==2){
            cout<<"forѭ�� ��i��ֵ��"<<i<<" , break ����ѭ��"<<endl;
            break;
        }else{
            cout<<"forѭ�� ��i��ֵ��"<<i<<" , continue ����ѭ��"<<endl;
            continue;
        }
    }
    int j=10;
    do{
        cout<<"do ...while ѭ����j��ֵ:"<<j<<endl;
        j++;
    }while (j<13);

    return 0;
}