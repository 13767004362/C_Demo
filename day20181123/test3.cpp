//Created by $HeXingGen on 2018/11/25.
//

#include <iostream>
using  namespace std;

int main(){
    int a=5,b=10;
    int result;
    result=a+b;
    cout<< "a+b ,��ֵ�ǣ�"<<result<<endl;
    result=a%b;
    cout<< "a%b ,��ֵ�ǣ�"<<result<<endl;
    result=(a++);
    cout<< "a++ ,��ֵ�ǣ�"<<result<<endl;
    result=(++b);
    cout<< "++b ,��ֵ�ǣ�"<<result<<endl;
    return 0;
}