//Created by $HeXingGen on 2018/11/25.
//

#include <iostream>
using namespace std;

int square_test1(int & p){
    return  p*p;
}

int square_test2(volatile  int * p){
    int i=*p;
    return i*i;
}

int main(){
    int i=5;

    cout<<"ͨ������,ʵ��ֵ��ƽ����"<<square_test1(i)<<endl;
    cout<<"ͨ��volatile�ؼ��֣�ʵ��ֵ��ƽ����"<<square_test2(&i)<<endl;
    return 0;
}