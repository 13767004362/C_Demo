//Created by HeXingGen on 2018/11/19.
#include <iostream>
//引入线程库
#include <thread>
//mutex用来确保线程同步
#include <mutex>
using  namespace std;

unsigned int length=1000;
mutex locks;

void  test1(){
    while (true){
        //使用lock_guard同步，基于作用域，能够自动解锁。
        lock_guard<mutex> lockGuard(locks);
        if (length>0){
            --length;
            cout<<"test1(),输出值："<<length<<endl;
        }else{
            break;
        }
    }
}
void  test2(){
    while (true){
        lock_guard<mutex> lockGuard(locks);
        if (length>0){
            --length;
            cout<<"test2(),输出值："<<length<<endl;
        }else{
            break;
        }
    }
}
int main(){
    thread th1(test1);
    thread th2(test2);
    //　需要注意的是线程对象执行了join后就不再join able了，所以只能调用join一次。
    th1.join();
    th2.join();
    cout << "main运行在MainThraed \n\n";
    return 0;
}
