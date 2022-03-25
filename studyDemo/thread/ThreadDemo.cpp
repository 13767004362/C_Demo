/**
 * @author ： HeXinGen
 * @date ： 2021/12/29
 * @description ：
 *
 *
 * 参考文档：
 * 线程的传参：https://blog.csdn.net/weixin_45074185/article/details/104373940
 * 线程锁的使用：https://zhuanlan.zhihu.com/p/91062516
 */

#include "ThreadDemo.h"
#include <iostream>

void takeTicket(const string & action){
    while (true){
        // std::lock_guard对象构造时，自动调用mtx.lock()进行上锁
        // std::lock_guard对象析构时，自动调用mtx.unlock()释放锁
        lock_guard<mutex> lockGuard(locks);
        if (ticket>0){
            cout<<"thread id : "<<this_thread::get_id()<< action << ticket <<endl;
            ticket--;
            //沉睡1毫秒
            this_thread::sleep_for(chrono::milliseconds(1));
            continue;
        }else {
            break;
        }
    }
}

int main(){
    const char * action1=" take ticket ";
    thread  t1(takeTicket,action1);
    thread  t2(takeTicket,action1);
    t1.join();
    t2.join();
    return 0;
}


