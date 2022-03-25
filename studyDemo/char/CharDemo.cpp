/**
 * @author ： HeXinGen
 * @date ： 2021/10/28
 * @description ：
 */
#include <iostream>
#include "cstring"

using namespace std;


/**
 * c中字符串char[]  和C++中字符串string
 */
void test() {
    // 三种字符串声明，本质上是一致的。
    string helloWord_str = "Hello World";// c++中字符串
    char helloWorld_char2[] = "Hello World"; //在C中字符串末尾没有'\0',系统会自动补全
    char helloWorld_char[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd',
                              '\0'}; //c风格字符串是一种特殊的字符串数组。最后一个字符为空字符‘\0’。这也被称为字符串结束字符，因为它告诉编译器，字符串到此结束。
    cout << helloWord_str << " length: " << helloWord_str.size();
    cout << " , ";
    int len1 = strlen(helloWorld_char2);//返回字符串真实长度
    cout << helloWorld_char << " real length: " << len1;
    cout << " , ";
    int len2 = sizeof(helloWorld_char);//返回长度，会将'\0'算上会多+1
    cout << helloWorld_char2 << " include length: " << len2 << endl;
}


/**
 * 验证 终止空字符‘\0’标识末尾
 *
 * strlen() 是计算到第一个\0结束的长度
 *
 */
void test1() {
    char helloWorld[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0'};
    cout << helloWorld << " length: " << sizeof(helloWorld) << endl;
    helloWorld[5] = '\0'; //将角标5位置的字符替换成'\0'
    cout << helloWorld << " length: " << sizeof(helloWorld) << endl;
}

/**
 * 执行拷贝char 字符
 */
void test2() {
    char hello[] = "hello";
    int length = strlen(hello);
    char copy[length + 1];//多+1，\0
    strcpy(copy, hello); //通过strcpy()拷贝
    cout << "old data: " << hello;
    cout << " copy data: " << copy << endl;

}

int main() {
    //test();
    // test1();
    test2();
    return 0;
}