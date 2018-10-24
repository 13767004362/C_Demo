//Created by $HeXinGen on 2018/10/24.

//C++�쳣����try��catch��throw, �Զ����쳣

#include <iostream>
#include <exception>

using namespace std;

//����һ���ܳ��쳣�ĺ���
void testThrowException(int number);

/**
 * �̳к�����һ���쳣,exception��һ���쳣�ĳ���
 */
struct CustomException : public exception {
public:
    //what() ���쳣���ṩ��һ���������������ѱ��������쳣������
    const char *what() const throw() {
        return "C++ �Զ����exception";
    }
};

int main() {
    try {
        testThrowException(0);
    } catch (const char *e) {
        cout << "��׽��һ���쳣��Ϣ��: " << e << endl;
    }
    try {
        throw CustomException();
    } catch (CustomException &e) {
        cout << "��׽��һ���쳣����ȡ��what()���ص��쳣��Ϣ��" << e.what() << endl;
    } catch (exception &e2) {
        //�����Ĵ���
    }
}

void testThrowException(int number) {
    if (number == 0) {
        //һ������Ϊ const char* ���쳣
        throw "���ԣ��ֶ��׳�һ���쳣";
    }
}
