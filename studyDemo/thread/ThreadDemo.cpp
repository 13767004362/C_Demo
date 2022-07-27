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
#include "BlockList.h"
#include "WaitTimeLock.h"
#include <iostream>

void takeTicket(const string &action) {
    while (true) {
        // std::lock_guard对象构造时，自动调用mtx.lock()进行上锁
        // std::lock_guard对象析构时，自动调用mtx.unlock()释放锁
        lock_guard<mutex> lockGuard(locks);
        if (ticket > 0) {
            cout << "thread id : " << this_thread::get_id() << action << ticket << endl;
            ticket--;
            //沉睡1毫秒
            this_thread::sleep_for(chrono::milliseconds(1));
            continue;
        } else {
            break;
        }
    }
}

void testTakePicket() {
    const char *action1 = " take ticket ";
    thread t1(takeTicket, action1);
    thread t2(takeTicket, action1);
    t1.join();
    t2.join();
}
/**
 * 测试一个循环 wait time
 */
void testWaitTime() {
     WaitTimeLock waitTimeLock;
    const int sleep_time = 10;//10秒
    auto fun = [&] { waitTimeLock.loopTime(sleep_time); };
    //启动一个异步线程
    thread sleepThread(fun);
    //主线程延迟2秒后调用结束
    this_thread::sleep_for(chrono::seconds(2));
    waitTimeLock.stopAll();
    sleepThread.join();
}
/**
 * 测试一个wait time 自动结束的
 */
void testSleepTime() {
    WaitTimeLock waitTimeLock;
    const int sleep_time = 3;//3秒
    auto fun = [&] { waitTimeLock.sleepTime(sleep_time); };
    //启动一个异步线程
    thread sleepThread(fun);
    sleepThread.join();
}

int main() {
    // testTakePicket();
    testWaitTime();
   // testSleepTime();
    return 0;
}


