/**
 * @author ： HeXinGen
 * @date ： 2021/6/8
 * @description ：
 */

#ifndef DEMO_STRUCTUREDEMO_H
#define DEMO_STRUCTUREDEMO_H

#include "string"
using namespace  std;
/**
 *
 * 数组允许定义可存储相同类型数据项的变量。
 *
 * 定义一个数据结构，自定义的可用的数据类型，它允许您存储不同类型的数据项。
 *
 * structure 和class 类大体类似，class 的修饰符默认是private, structure 是public.还有继承的修饰符也是差不多
 *
 */
struct  Author{
    // 名称
    string name;
    //年龄
    int age;
    Author(){

    }
    Author(const string & n, int age){
        this->age=age;
        this->name=n;
    }
} author;

/**
 * typedef 关键字 ,声明一个别名,
 *  可以方便访问，省略struct
 */
typedef struct Book{
    //书籍id
    int bookId;
    //作者
    Author author;
    // 书名
    string  name;
    //描述
    string  description;
} Books;

#endif //DEMO_STRUCTUREDEMO_H
