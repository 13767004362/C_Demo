/**
 * @author ： HeXinGen
 * @date ： 2022/6/24
 * @description ：
 */#ifndef DEMO_WAITTIMELOCK_H
#define DEMO_WAITTIMELOCK_H

#include <mutex>
#include <condition_variable>
#include <chrono>
#include <iostream>
#include <ctime>

using namespace std;

class WaitTimeLock {
private:
    mutex lock;
    condition_variable wait;
    bool stop;
public:
    WaitTimeLock() :stop(false){

    }

public:
    /**
     *  循环等待多少秒
     * @param secondTime
     */
    void loopTime(const int &secondTime) {
        unique_lock<mutex> uniqueLock(lock);
        while (!stop) {
            cout<<" wait start ,second time: "<<secondTime<<endl;
            wait.wait_for(uniqueLock, chrono::seconds(secondTime));
        }
        cout<<" loop break"<<endl;
        stop = false;
        uniqueLock.unlock();
    }
    /**
     * 定义一个可取消的沉睡时间，单位秒
     * @param secondTime
     */
    void sleepTime(const int &secondTime){
        unique_lock<mutex> uniqueLock(lock);
        int t=secondTime;
        while (!stop) {
            cout<<" wait start ,second time: "<<secondTime<<endl;
            //time():该函数返回系统的当前日历时间，自 1970 年 1 月 1 日以来经过的秒数
            time_t  s_time=time(0);
            wait.wait_for(uniqueLock, chrono::seconds(t));
            time_t  e_time=time(0);
            int interval=e_time-s_time;// 计算出沉睡的间隔秒数;
            if(e_time-s_time>=t){
                break;
            }else{
                t-=interval;
                continue;
            }
        }
        cout<<" sleep  break"<<endl;
        stop = false;
        uniqueLock.unlock();
    }
    /**
     * 取消
     */
    void stopAll() {
        unique_lock<mutex> uniqueLock(lock);
        cout<<" change stop mark"<<endl;
        stop = true;
        uniqueLock.unlock();
        cout<<" notify wait"<<endl;
        wait.notify_all();
    }
};


#endif //DEMO_WAITTIMELOCK_H
