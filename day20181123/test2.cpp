//Created by $HeXingGen on 2018/11/25.
//
#include <iostream>
using  namespace std;

void reduce();

static int i=5;

int main(){
    while ((i--)>0){
        reduce();
    }
    return 0;
}

void reduce(){
    int z=0;
    static int j=0;
    j++;
    z++;
    cout<<" �ֲ����� z,��ֵ�ǣ�"<<z<<" ,�ڴ��ַ�ǣ�"<<&z<<endl;
    cout<<" static ���εľֲ����� j,��ֵ�ǣ�"<<j<<" ,�ڴ��ַ�ǣ�"<<&j<<" �� ";
    cout<<" static ���ε�ȫ�ֱ��� i,��ֵ�ǣ�"<<i<<" ,�ڴ��ַ�ǣ�"<<&i<<" �� "<<endl;
}

