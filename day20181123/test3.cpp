//Created by $HeXingGen on 2018/11/25.
//

#include <iostream>
using  namespace std;

int main(){
    int a=5,b=10;
    int result;
    result=a+b;
    cout<< "a+b ,其值是："<<result<<endl;
    result=a%b;
    cout<< "a%b ,其值是："<<result<<endl;
    result=(a++);
    cout<< "a++ ,其值是："<<result<<endl;
    result=(++b);
    cout<< "++b ,其值是："<<result<<endl;
    return 0;
}