/**
 * @author ： HeXinGen
 * @date ： 2021/6/8
 * @description ：
 */

#include "StructureDemo.h"
#include <iostream>
using namespace  std;
/**
 *  声明一个Book 数据结构的指针参数
 * @param books
 */
void printBookDetail(Books * books){
    auto  author=books->author;
    // -> 是用于类/结构的指针，访问其变量
    cout<<" bookId: "<<books->bookId;
    cout<<" bookName: "<<books->name;
    cout<<" ,author.name: "<<author.name;
    cout<<" ,author.age: "<<author.age;
    cout<<" ,description: "<<books->description;
    cout<<endl;
}


void testBookStructure(){
    Books book;
    book.bookId=10086;
    book.name="learn c++";
    Author author;
    //通过.运算符号，访问结构，类的变量
    author.age=26;
    author.name="HeXinGen";
    book.author=author;
    book.description=" this is chinese document ";
    printBookDetail(&book);
}

void testStructure2(){
    // 调用结构的传参构造函数
    Author author1("HeXinGen",18);
    cout<<author1.name<<" , "<<author1.age<<endl;
}

int main(){
    //testBookStructure();
    testStructure2();
    return 0;
}