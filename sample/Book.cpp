//Created by $HeXinGen on 2018/10/25.

//图书类Book.h的函数实现都存储在实现文件Book.cpp中

#include <iostream>
#include <cstring> //字符串操作
#include <fstream>//文件读写流
#include <iomanip>
#include <string>
//引入Book.h
#include "Book.h"

using namespace std;

//定义文件名
const  string fileName="Book.dat";
const  string tempFileName="temp.dat";

Book::Book(char *cName, char *cIsbn, char *cPrice, char *cAuthor) {
    //属性赋值，拷贝数据
    strncpy(name, cName, length_128);
    strncpy(isbn, cIsbn, length_128);
    strncpy(price, cPrice, length_50);
    strncpy(author, cAuthor, length_50);
}

void Book::setName(char *cName) {
    strncpy(name, cName, length_128);
}

void Book::setIsbn(char *cIsbn) {
    strncpy(isbn, cIsbn, length_128);
}

void Book::setPrice(char *cPrice) {
    strncpy(price, cPrice, length_50);
}

void Book::setAuthor(char *cAuthor) {
    strncpy(author, cAuthor, length_50);
}

char *Book::getName() {
    return name;
}

char *Book::getIsbn() {
    return isbn;
}

char *Book::getPrice() {
    return price;
}

char *Book::getAuthor() {
    return author;
}
/**
 *  将Book中信息写入文件中。
 */
void Book::writeData() {
    ofstream  out;
    //打开文件,ios::binary 以二进制方式打开,追加方式写入
    out.open(fileName,ios::binary|ios::app);
    try {
        out.write(name,length_128);
        out.write(isbn,length_128);
        out.write(price,length_50);
        out.write(author,length_50);
    }catch (...){
        out.close();
        throw "write file happen error";
    }
    out.close();
}
/**
 * 从文件中，获取第几本书籍信息
 *
 * @param count 角标，例如：获取第2本书籍信息，count应该为1,。
 */
void Book::getBookFromFile(int count) {
    ifstream in;
    //以二进制打开文件
    in.open(fileName,ios::binary);
    //定义Book对应的属性
    char cName[length_128];
    char cIsbn[length_128];
    char  cPrice[length_50];
    char  cAuthor[length_50];
    try {
        //从指定位置，开始读取数据
        in.seekg(count*(length_128+length_128+length_50+length_50),ios::beg);
        in.read(cName,length_128);
        //tellg（）函数不需要带参数，它返回当前定位指针的位置，也代表着输入流的大小
        if (in.tellg()>0){
           setName(cName);
        }
        in.read(cIsbn,length_128);
        if( in.tellg()){
            setIsbn(cIsbn);
        }
        in.read(cPrice,length_50);
        if (in.tellg()>0){
            setPrice(cPrice);
        }
        in.read(cAuthor,length_50);
        if (in.tellg()>0){
            setAuthor(cAuthor);
        }
        in.close();
    }catch (...){
        in.close();
        throw "read file happen error";
    }
}
/**
 * 删除指定第几本书籍
 *
 * 创建一个临时文件，将需要删除角标的后面的数据拷贝到临时文件，然后在删除角标的位置进行覆盖。
 *
 * @param count  例如： 删除第2本，传入count应该为2
 */
void Book::deleteData(int count) {
    long  fileLength;
    int dataCount=0;
    fstream file;
    fstream tmpFile;
    ofstream out;
    int bookSize=length_128+length_128+length_50+length_50;
    char buffer[bookSize];//缓存区
    //打开一个文件用于读写
    file.open(fileName,ios::binary|ios::in|ios::out);
    tmpFile.open(tempFileName,ios::binary|ios::in|ios::out);
    //获取到文件长度
    file.seekg(0,ios::end);
    fileLength=file.tellg();
    //计算出有多少本书籍
    dataCount=fileLength/bookSize;
    if (count<0&&count>dataCount){
        file.close();
        throw " 指定删除的角标错误";
    }else{
        file.seekg(count*bookSize,ios::beg);
        for (int i = 0; i <(dataCount-count ); ++i) {
            //memset(void *buffer, int c, int count):把buffer所指内存区域的前count个字节设置成字符c
            memset(buffer,0,bookSize);//清空数组
            file.read(buffer,bookSize);
            tmpFile.write(buffer,bookSize);
        }
        file.close();
        tmpFile.seekg(0,ios::beg);
        out.open(fileName);
        out.seekp((count-1)*bookSize,ios::beg);
        for (int j = 0; j <(dataCount-count ) ; ++j) {
             memset(buffer,0,bookSize);
             tmpFile.read(buffer,bookSize);
             out.write(buffer,bookSize);
        }
    }
    out.close();
    tmpFile.close();
    //删除临时文件
    remove("temp.dat");

}








