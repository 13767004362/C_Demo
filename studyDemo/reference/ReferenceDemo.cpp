/**
 * @author ： HeXinGen
 * @date ： 2021/6/2
 * @description ：
 */
#include <iostream>
#include "ReferenceDemo.h"
using namespace Reference;

using namespace std;

void testReference();

void testMethodReference();

bool &compareMax(int &i);

void testPointerReference();

void pointerReference(int *&p);
void testReference(int & change);


/**
 * const 修饰引用，禁止改动对应的数据值
 * @param w
 * @param h
 * @param area
 */
void testConstRefrence(const int & w,const  int & h,int & area){
     area=w*h;
}


int main() {
    // testReference();
    // testMethodReference();
   // testPointerReference();

/*    int area;
    testConstRefrence(1,2,area);
    cout<<"area "<<area<<endl;*/

   Change change;
   change.testChangeValue();

    return 0;
}

/**
 *  通过&符号，声明引用，必须初始化
 */
void testReference() {
    int i = 10;
    int &reference = i;
    cout << " reference: " << reference << "  " << &i << " memory value: " << &reference << endl;
    reference = 1;
    cout << " change reference :" << i << "  " << &i << " memory value: " << &reference << endl;
    int a = 1000;
    int &reference1 = a;
    reference = reference1;
    cout << " reference: " << reference << "  " << i << " memory value: " << &reference << endl;

}

void testMethodReference() {
    int i = 1000;
    bool b = compareMax(i);
    //cout在显示布尔值之前将它转化为int, 可以使用boolalpha
    cout << " compare max: " << boolalpha << b << " i : " << i << endl;
}

bool result;

/**
 *  返回引用，不可以是局部变量，要么顶部变量，要么静态变量
 * @param i
 * @return
 */
bool &compareMax(int &i) {
    const int maxValue = 100;
    if (i > maxValue) {
        i = maxValue;
        result = false;
    } else {
        result = true;
    }
    return result;
}

/**
 *
 * int *& p, 是正确的， &与p靠得最近，所以p是一个引用，这个引用的类型是int*，也就是一个指针变量的引用
 * @param p
 */
void pointerReference(int *&p) {
    int temp = 100;
    cout << " method param: " << p << endl;
    p = &temp;
}

void testPointerReference() {
    int i = 1;
    cout << " i " << i << endl;
    int *p = &i;
    cout << p << endl;
    pointerReference(p);
    cout << " i " << i << endl;
}
void testReference(int & change){
    change=110;
}