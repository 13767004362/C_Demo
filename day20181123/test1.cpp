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

    cout<<"通过引用,实现值的平方："<<square_test1(i)<<endl;
    cout<<"通过volatile关键字，实现值的平方："<<square_test2(&i)<<endl;
    return 0;
}