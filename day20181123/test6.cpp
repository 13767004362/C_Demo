//Created by $HeXinGen on 2018/11/25.
//

#include <iostream>
using  namespace std;

int main(){
    for (int i = 0; i <4 ; ++i) {
        if (i==2){
            cout<<"for循环 ，i的值："<<i<<" , break 结束循环"<<endl;
            break;
        }else{
            cout<<"for循环 ，i的值："<<i<<" , continue 继续循环"<<endl;
            continue;
        }
    }
    int j=10;
    do{
        cout<<"do ...while 循环，j的值:"<<j<<endl;
        j++;
    }while (j<13);

    return 0;
}