//Created by $HeXinGen on 2018/10/24.

//C++异常处理，try、catch、throw, 自定义异常

#include <iostream>
#include <exception>

using namespace std;

//声明一个跑出异常的函数
void testThrowException(int number);

/**
 * 继承和重载一个异常,exception是一切异常的超类
 */
struct CustomException : public exception {
public:
    //what() 是异常类提供的一个公共方法，它已被所有子异常类重载
    const char *what() const throw() {
        return "C++ 自定义的exception";
    }
};

int main() {
    try {
        testThrowException(0);
    } catch (const char *e) {
        cout << "捕捉到一个异常信息是: " << e << endl;
    }
    try {
        throw CustomException();
    } catch (CustomException &e) {
        cout << "捕捉到一个异常，获取到what()返回的异常信息：" << e.what() << endl;
    } catch (exception &e2) {
        //其他的错误
    }
}

void testThrowException(int number) {
    if (number == 0) {
        //一个类型为 const char* 的异常
        throw "测试，手动抛出一个异常";
    }
}
