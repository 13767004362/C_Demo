/**
 * @author ： HeXinGen
 * @date ： 2021/8/26
 * @description ：
 */
#include <exception>
#include <string>
using namespace std;
#ifndef DEMO_EXCEPTIONDEMO_H
#define DEMO_EXCEPTIONDEMO_H

/**
 * exception 是一个抽象类，自定义exception 子类，需复写what（）
 */
struct CalculationException:  exception{

public:
    string msg;
    CalculationException(const string &msg) {
        this->msg=(char *)msg.data();
    }

    const char * what() const noexcept override{
        return msg.c_str();

     }
};


#endif //DEMO_EXCEPTIONDEMO_H
