/**
 * @author ： HeXinGen
 * @date ： 2022/7/4
 * @description ：
 */#ifndef DEMO_SAFECOPY_H
#define DEMO_SAFECOPY_H

#include <iostream>
#include <cstring>

using namespace std;

/**
 *  浅拷贝：当一个类中包含指针属性时，若这个指针是在构造函数中 new 出来,且在析构造函数中delete 该指针，若是同时存在多个该类对象，销毁其中一个，会造成其他类中指针不可用。
 *  当某个类中包含指针，应该重写： 复制构造函数和复制赋值运算符 operator=
 *
 *  当前案例：深度拷贝案例，适用于包含指针属性的类。
 *
 */

class Person {
private:
    int age;
    char *name = NULL;


public:
    Person(const char *c,int age=18) {
        this->age=age;
        copyName(c);
        cout << " person () "<<" , " <<age<<" , "<<age<< endl;
    }

    /**
     * 析构函数，释放资源
     */
    ~Person() {
        cout << " ~person ()" << endl;
        if (name != NULL) {
            delete[] name;
        }
    }

    /**
     * 复制构造函数是一个重载的构造函数，由编写类的程序员提供。
     * 每当对象被复制时，编译器都将调用复制构造函数
     * @param p
     */
    Person(const Person &p) {
        cout << " person copy ()" << endl;
        this->age = p.getAge();
        if (p.getName() != NULL) {
            copyName(p.getName());
        }
    }
    /**
     * 复制赋值运算符 operator=
     * 每当对象被赋值时，会调用。
     * @param p
     * @return
     */
    Person& operator=( const Person &p) {
        cout << " person copy operator= ()" << endl;
        this->age = p.getAge();
        if (p.getName() != NULL) {
            copyName(p.getName());
        }
        return *this;
    }
    /**
   * 用于拷贝数据
   * @param c
   */
    void  copyName(const char *c){
        //拷贝内容
        if (c != NULL) {
            int length = strlen(c) + 1;
            name = new char[length];
            strcpy(name, c);
        }
    }
    char *getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

};
/**
 * 测试 赋值构造函数和赋值赋值运算符
 */
static void testPerson(){
    const char *c ="xin gen";
    Person p1(c);
    Person p2=p1;// 验证复制构造函数
    Person p3(c);
    p3=p2; //验证operator=

}


#endif //DEMO_SAFECOPY_H
