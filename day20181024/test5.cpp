//Created by $HeXinGen on 2018/10/24.

//������ģ�壬�ͺ���ģ��
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

using namespace std;

/**
 * ����һ����ģ�壬ģ��ջ�Ĺ���
 * @tparam T
 */
template<class T>
class Stack {
private:
    vector<T> queue;
public:
    void push(T const &element);//��ջ
    void pop(); //��ջ���Ƴ����һ��Ԫ��
    T top() const;//��ȡջ����Ԫ��
    bool isEmpty() {  // ���Ϊ���򷵻��档
        return queue.empty();
    }
};

/**
 * ���庯��ģ��
 * @tparam T
 */
template<class T>
void Stack<T>::push(const T &element) {
    queue.push_back(element);
}

template<class T>
void Stack<T>::pop() {
    if (queue.empty()) {
        throw "ջ��û��Ԫ�أ��޷������Ƴ�����";
    }
    // ɾ�����һ��Ԫ��
    queue.pop_back();
}

template<class T>
T Stack<T>::top() const {
    if (queue.empty()) {
        throw "ջ��ûӴԪ�أ��޷�����";
    }
    // �������һ��Ԫ�صĸ���
    return queue.back();
}
int main() {
    try {
        Stack<int> intStack;
        Stack<string> stringStack;
        intStack.push(7);
        cout << "��ȡ��int���͵�ջ����Ϣ��" << intStack.top() << endl;
        stringStack.push("hello C++");
        cout << "��ȡ��string���͵�ջ����Ϣ��" << stringStack.top() << endl;
        //�Ƴ����Σ���ջΪ�գ��׳��쳣��
        stringStack.pop();
        stringStack.pop();
    } catch (const char *e) {
        cout << "��׽�����쳣��Ϣ�ǣ�" << e << endl;
    }
    return 0;
}