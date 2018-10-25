//Created by $HeXinGen on 2018/10/25.

//ͼ����Book.h�ĺ���ʵ�ֶ��洢��ʵ���ļ�Book.cpp��

#include <iostream>
#include <cstring> //�ַ�������
#include <fstream>//�ļ���д��
#include <iomanip>
#include <string>
//����Book.h
#include "Book.h"

using namespace std;

//�����ļ���
const  string fileName="Book.dat";
const  string tempFileName="temp.dat";

Book::Book(char *cName, char *cIsbn, char *cPrice, char *cAuthor) {
    //���Ը�ֵ����������
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
 *  ��Book����Ϣд���ļ��С�
 */
void Book::writeData() {
    ofstream  out;
    //���ļ�,ios::binary �Զ����Ʒ�ʽ��,׷�ӷ�ʽд��
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
 * ���ļ��У���ȡ�ڼ����鼮��Ϣ
 *
 * @param count �Ǳ꣬���磺��ȡ��2���鼮��Ϣ��countӦ��Ϊ1,��
 */
void Book::getBookFromFile(int count) {
    ifstream in;
    //�Զ����ƴ��ļ�
    in.open(fileName,ios::binary);
    //����Book��Ӧ������
    char cName[length_128];
    char cIsbn[length_128];
    char  cPrice[length_50];
    char  cAuthor[length_50];
    try {
        //��ָ��λ�ã���ʼ��ȡ����
        in.seekg(count*(length_128+length_128+length_50+length_50),ios::beg);
        in.read(cName,length_128);
        //tellg������������Ҫ�������������ص�ǰ��λָ���λ�ã�Ҳ�������������Ĵ�С
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
 * ɾ��ָ���ڼ����鼮
 *
 * ����һ����ʱ�ļ�������Ҫɾ���Ǳ�ĺ�������ݿ�������ʱ�ļ���Ȼ����ɾ���Ǳ��λ�ý��и��ǡ�
 *
 * @param count  ���磺 ɾ����2��������countӦ��Ϊ2
 */
void Book::deleteData(int count) {
    long  fileLength;
    int dataCount=0;
    fstream file;
    fstream tmpFile;
    ofstream out;
    int bookSize=length_128+length_128+length_50+length_50;
    char buffer[bookSize];//������
    //��һ���ļ����ڶ�д
    file.open(fileName,ios::binary|ios::in|ios::out);
    tmpFile.open(tempFileName,ios::binary|ios::in|ios::out);
    //��ȡ���ļ�����
    file.seekg(0,ios::end);
    fileLength=file.tellg();
    //������ж��ٱ��鼮
    dataCount=fileLength/bookSize;
    if (count<0&&count>dataCount){
        file.close();
        throw " ָ��ɾ���ĽǱ����";
    }else{
        file.seekg(count*bookSize,ios::beg);
        for (int i = 0; i <(dataCount-count ); ++i) {
            //memset(void *buffer, int c, int count):��buffer��ָ�ڴ������ǰcount���ֽ����ó��ַ�c
            memset(buffer,0,bookSize);//�������
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
    //ɾ����ʱ�ļ�
    remove("temp.dat");

}








