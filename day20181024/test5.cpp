//Created by $HeXinGen on 2018/10/24.

//定义类模板，和函数模板
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

using namespace std;

/**
 * 定义一个类模板，模拟栈的功能
 * @tparam T
 */
template<class T>
class Stack {
private:
    vector<T> queue;
public:
    void push(T const &element);//进栈
    void pop(); //出栈，移除最后一个元素
    T top() const;//获取栈顶的元素
    bool isEmpty() {  // 如果为空则返回真。
        return queue.empty();
    }
};

/**
 * 定义函数模板
 * @tparam T
 */
template<class T>
void Stack<T>::push(const T &element) {
    queue.push_back(element);
}

template<class T>
void Stack<T>::pop() {
    if (queue.empty()) {
        throw "栈中没有元素，无法进行移除操作";
    }
    // 删除最后一个元素
    queue.pop_back();
}

template<class T>
T Stack<T>::top() const {
    if (queue.empty()) {
        throw "栈中没哟元素，无法返回";
    }
    // 返回最后一个元素的副本
    return queue.back();
}
int main() {
    try {
        Stack<int> intStack;
        Stack<string> stringStack;
        intStack.push(7);
        cout << "获取到int类型的栈中信息：" << intStack.top() << endl;
        stringStack.push("hello C++");
        cout << "获取到string类型的栈中信息：" << stringStack.top() << endl;
        //移除两次，当栈为空，抛出异常。
        stringStack.pop();
        stringStack.pop();
    } catch (const char *e) {
        cout << "捕捉到的异常信息是：" << e << endl;
    }
    return 0;
}