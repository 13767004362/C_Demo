/**
 * @author ： HeXinGen
 * @date ： 2021/6/15
 * @description ：
 */

#include "AbstractDemo.h"
int main(){
    WorkerImpl workerImpl;
    Worker * worker=&workerImpl;
    string name="WorkImpl";
    worker->setName(name);
    worker->work();
    return 0;
}