//Created by $HeXinGen on 2018/11/25.
//
#include <iostream>

using  namespace std;

int main(){
    int a=1,b=2;
    if (a&&b){
          cout<< " 当a=1,b=2时，a&&b 为 true,条件为真"<<endl;
    }
    if (a|| b){
        cout<< " 当a=1,b=2时，a||b 为 true,条件为真"<<endl;
    }
    //改变其中一个值为0
    a=0;
    if (a&&b){
        cout<< " 当a=0,b=2时，a&&b 为 true,条件为真"<<endl;
    }else{
        cout<< " 当a=0,b=2时，a&&b 为 false,条件为假"<<endl;
    }
    if (a|| b){
        cout<< " 当a=0,b=2时，a||b 为 true,条件为真"<<endl;
    }else{
        cout<< " 当a=0,b=2时，a||b 为 false,条件为假"<<endl;
    }
    return 0;
}

