//Created by $HeXinGen on 2018/11/25.
//
#include <iostream>

using  namespace std;

int main(){
    int a=1,b=2;
    if (a&&b){
          cout<< " ��a=1,b=2ʱ��a&&b Ϊ true,����Ϊ��"<<endl;
    }
    if (a|| b){
        cout<< " ��a=1,b=2ʱ��a||b Ϊ true,����Ϊ��"<<endl;
    }
    //�ı�����һ��ֵΪ0
    a=0;
    if (a&&b){
        cout<< " ��a=0,b=2ʱ��a&&b Ϊ true,����Ϊ��"<<endl;
    }else{
        cout<< " ��a=0,b=2ʱ��a&&b Ϊ false,����Ϊ��"<<endl;
    }
    if (a|| b){
        cout<< " ��a=0,b=2ʱ��a||b Ϊ true,����Ϊ��"<<endl;
    }else{
        cout<< " ��a=0,b=2ʱ��a||b Ϊ false,����Ϊ��"<<endl;
    }
    return 0;
}

