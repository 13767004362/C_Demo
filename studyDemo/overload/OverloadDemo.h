/**
 * @author ： HeXinGen
 * @date ： 2021/6/15
 * @description ：
 */

#ifndef DEMO_OVERLOADDEMO_H
#define DEMO_OVERLOADDEMO_H

#include <iostream>
#include "string"

using namespace std;

/**
 * 运算符重载是一种基本运算符和用户定义的函数形式的运算符扩展共存的机制。
 * 重载的运算符是为类对象服务的，其形式可以表现为类的成员函数，也可以表现为类的友元函数。
 */
class Plus {
private:
    int i;
public:
    Plus() {

    }

    Plus(int i) {
        this->i = i;
    }

    /**
     * 定义一个=运算符的重载函数
     * @param i
     * @return
     */
    Plus *operator=(int i) {
        this->i = i;
        return this;
    }

    /**
     * 声明一个+运算法的重载函数
     * @param p
     * @return
     */
    Plus operator+(Plus &p);

    void plus() {
        cout << " i: " << i << endl;
    }
};

/**
 * 定义类中+运算符的重载方法
 * @param p
 * @return
 */
Plus Plus::operator+(Plus &p) {
    return Plus(this->i + p.i);
}

class Print {
private:
    string msg;
public:
    Print(string &m) {
        this->msg = m;
    }

    /**
     * 声明一个友元的<<运算符
     * @param output
     * @param print
     */
    friend void operator<<(ostream &output, Print &print);
};

void operator<<(ostream &output, Print &print) {
    output << " print msg: " << print.msg << endl;
}


/**
 * 定义一个*与->
 */
template<class T>
class SimplePointer {
protected:
    T *t;
public:
    SimplePointer(T *t) {
        this->t = t;
    }

    ~SimplePointer() {
        delete t;
    }

    const SimplePointer<T> *operator->() {
        return this;
    };
    /**
     * 声明一个* 符号的友元函数
     * @tparam K
     * @param simplePointer
     * @return
     */
    template<class K>
    friend K *operator*(SimplePointer<K> &simplePointer);
};

template<class K>
K *operator*(SimplePointer<K> &simplePointer) {
    return simplePointer.t;
}

#endif //DEMO_OVERLOADDEMO_H
