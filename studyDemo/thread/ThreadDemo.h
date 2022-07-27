/**
 * @author ： HeXinGen
 * @date ： 2021/12/29
 * @description ：
 */
#ifndef DEMO_THREADDEMO_H
#define DEMO_THREADDEMO_H
//线程
#include <thread>

#include <string>
//mutex 互斥量 用来 线程同步
#include <mutex>

using namespace std;
//定义一个全局的lock变量,即互斥量
mutex locks;

//定义一个计数
int ticket = 1000;



#endif //DEMO_THREADDEMO_H
