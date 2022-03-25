/**
 * @author ： HeXinGen
 * @date ： 2021/6/9
 * @description ：
 */

#ifndef DEMO_CLASSDEMO_H
#define DEMO_CLASSDEMO_H

#include "string"
#include <iostream>
#include <cstring>

using namespace std;

class Worker {
    // 设置私有访问符，默认是私有的
private:
    int age; // 年龄
    string name; // 名字

public:
    //声明一个无参数构造函数
    Worker() {};


    //声明一个有参数的构造函数
    Worker(int &age, string &name);


    // 声明一个析构函数
    ~Worker();

    //声明一个函数，但不定义
    void setAge(int const &age);

    /**
     * 在类中声明定义一个函数，等同于内联函数，即便没有使用 inline 标识符
     * @param name
     */
    void setName(string const &name) {
        this->name = name;
    }

    /**
     * 声明一个inLine函数。
     * 在类中的全部成员函数都是内联函数，哪怕没有inline修饰
     * 优点: 当函数体比较小的时候, 内联该函数可以令目标代码更加高效. 对于存取函数以及其它函数体比较短, 性能关键的函数, 鼓励使用内联.
     * 缺点: 滥用内联将导致程序变慢. 内联可能使目标代码量或增或减, 这取决于内联函数的大小. 内联非常短小的存取函数通常会减少代码大小, 但内联一个相当大的函数将戏剧性的增加代码大小. 现代处理器由于更好的利用了指令缓存, 小巧的代码往往执行更快。
     * 结论: 一个较为合理的经验准则是, 不要内联超过 10 行的函数. 谨慎对待析构函数, 析构函数往往比其表面看起来要更长, 因为有隐含的成员和基类析构函数被调用
     */
    inline void toString() {
        cout << " age :" << age << ", name: " << name << endl;
    }

    /**
     * 每个类中都有一个this指针，指向类对象。可以通过->访问类的成员变量和成员函数，但不能访问友元函数。
     * @return
     */
    Worker *obtain() {
        return this;
    }

    string&  getName(){
        return this->name;
    }

};

/**
 * 使用范围解析运算符 :: ，来定义类中的函数。
 * 同时也可以用来访问命名空间中的类、方法、属性
 * @param age
 */
void Worker::setAge(int const &age) {
    this->age = age;
}

/**
 * 使用初始化列表，初始化参数。
 * 在构造函数后面 ：一系列类的变量。
 * 这个等同于this->变量=赋值。
 * @param age
 * @param name
 */
Worker::Worker(int &age, string &name) : age(age), name(name) {
    //打印类的成员变量，验证是否初始化成功
    cout << " constructor method, init ";
    this->toString();
}

/**
 * 在构造函数钱添加~ ，是折构函数， 用于销毁类的时候，进行释放资源(io 或者文件)
 */
Worker::~Worker() {
    Worker *worker = obtain();
    cout << " worker class object is destroy " << worker << endl;
}

/**
 * 浅拷贝：只是增加了一个指针，指向已存在对象的内存。在多个对象指向一块空间的时候，释放一个空间会导致其他对象所使用的空间也被释放了，再次释放便会出现错误
 * 深度拷贝：是增加了一个指针，并新开辟了一块空间，让指针指向这块新开辟的空间。
 * https://blog.csdn.net/qq_29344757/article/details/76037255
 *
 * 在类的默认拷贝构造函数中，非指针类型是浅拷贝，
 *
 * 如果类带有指针变量，并有动态内存分配，则它必须有一个拷贝构造函数。
 */
class Copy {
private:
    char *name;
public:
    // 声明一个静态变量
    static  int total;
    /**
     * 默认初始化Null 指针
     */
    Copy() : name(NULL) {
        ++total;
    }

    Copy(const Copy *copy) : name(new char[strlen(copy->name) + 1]) {
        strcpy(name, copy->name);
        ++total;
    }

    /**
     * 声明重载函数
     * @param copy
     * @return
     */
    Copy &operator=(const char *n) {
        if (n != NULL) {
            if (name) {
                delete[] name;
            }
            name = new char[strlen(n) + 1];//加1,某位是'\0'
            strcpy(name, n);
        }
        return *this;
    }

    ~Copy() {
        if (name) {
            delete[] name;
        }
    }

    void setName(char const *n) {
        if (n == NULL) {
            name = new char[1];
            *name = '\0';
        } else {
            name = new char[strlen(n) + 1];//加1,某位是'\0'
            strcpy(name, n);
        }
    }
    /**
     * 声明一个静态函数，获取创建类对象的次数。
     * 通过 类名::方法/变量
     * @return
     */
    static int& getTotal(){
        return Copy::total;
    }
    inline char * getName() {
        return  name;
    }
};
/**
 * 静态成员的初始化，不能放到类的定义中，
 * 只能放到类外部，通过类::静态变量的名字=赋值，进行初始化。
 */
int Copy::total=0;

/**
 * 友元有权访问类的所有私有（private）成员和保护（protected）成员
 * 通常声明在类和函数上
 */
class Persion{
private:
    string  name;
    string gender;

public:
    /**
     * 声明友元函数
     * @param persion
     */
    friend void printPersonMsg(Persion & persion);
    /**
     * 声明友元类
     */
    friend class Man;
    void setName(string &n);
};
class Man{
public:
    Man(){}
    void updateGender(Persion &p){
          p.gender="man";
    }
};
/**
 *  定义友元函数，不需要使用:: 去声明所属类，因不是任何类的成员函数
 * @param persion
 */
void printPersonMsg(Persion & persion){
     cout<<"name: "<<persion.name<<" gender: "<<persion.gender<<endl;
}
void Persion::setName(string &n) {
     this->name=n;
}



#endif //DEMO_CLASSDEMO_H
