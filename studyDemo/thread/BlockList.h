/**
 * @author ： HeXinGen
 * @date ： 2022/6/24
 * @description ：
 */

#ifndef DEMO_BLOCKLIST_H
#define DEMO_BLOCKLIST_H

#include <list>
#include <mutex>
#include <condition_variable>
#include <iostream>
using  namespace std;


/**
 * 采用条件变量和互斥锁，构建一个阻塞队列
 *
 * unique_lock 是通用互斥包装器，允许延迟锁定、锁定的有时限尝试、递归锁定、所有权转移和与条件变量一同使用。
 * condition_variable唯一接受unique_lock。
 * @tparam k
 */
template <class  K> class  BlockList{

private:
   std::list<K> queue;
   condition_variable  takeWait;
   condition_variable  addWait;
   mutex lock;
   int maxSize;
   /**
    * 是否为空
    * @return
    */
   bool  isEmpty() const {
       return this->queue.size()==0;
   }
   /**
    * 是否添加满了
    * @return
    */
   bool  isFull() const {
       return this->queue.size()==maxSize;
   }

public:
    BlockList(int size){
        this->maxSize=size;
    }
    virtual  ~BlockList();

    void push(const K& k){
        unique_lock<mutex> uniqueLock(lock);// 先获取到锁
        while (isFull()){// 循环判断,这里也等价于    addWait.wait(lock,[&]{ return !isFull(); });
            cout<<" queue is full , wait take"<<endl;
            addWait.wait(uniqueLock); //等待消费者处理
        }

        queue.push_back(k);
        takeWait.notify_all();//唤醒消费者
    }

    const K& take(){
        unique_lock<mutex> uniqueLock(lock);
        while (isEmpty()){
            cout<<" queue is empty , wait add"<<endl;
            takeWait.wait(uniqueLock);
        }
        const K& k= queue.front();
        queue.pop_front();
        addWait.notify_all();
        return k;
    }


};


#endif //DEMO_BLOCKLIST_H
