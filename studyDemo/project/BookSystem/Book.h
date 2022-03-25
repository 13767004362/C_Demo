/**
 * @author ： HeXinGen
 * @date ： 2021/6/16
 * @description ：
 */

#ifndef DEMO_BOOK_H
#define DEMO_BOOK_H

#include "Common.h"

namespace ComBook {
    /**
     * 声明一个
     */
    class Book {
    private:
        string name;
        string description;

    public:
        Book(){

        }
        Book(string name, string description) {
            this->description = description;
            this->name = name;
        }
        string getName(){
            return name;
        }
        string  getDescription(){
            return description;
        }

        /**
         * 声明=运算符重载方法
         * @param content
         * @return
         */
        Book *operator=(string &content);

        /**
         * 声明友元函数
         * @param book
         * @return
         */
        friend string tranform(Book &book);

    };


   inline string  tranform(Book &book) {
       string temp;
       temp+=book.name;
       temp+=delimiter;
       temp+=book.description;
        return temp;
    }

    /**
     * 定义一个用于存储的数据结构
     * 采用 定长头+body 的方式
     */
    struct Block {
        int head; //对应Book的字节长度
        string body;// 对应 Book的内容信息
        static const  int int_size=4; //int 默认的字节数
    };


    /**
     * 自定义异常
     */
    class BookException : public exception {
    private:
        const char *msg;
    public:
        BookException(const char *msg) {
            this->msg = msg;
        }

        const char *what() const noexcept override {
            return msg;
        }
    };

    /**
     * 将内容块写入文件中
     * @param fileName
     * @param block
     */
    void writeBlock(const string fileName, Block block);

    /**
     *  查询指定的位置的内容块
     * @param fileName
     * @param position
     * @return
     */
    Block  queryBlockByPosition(const string fileName, int &position);

    void   transform(Book& book,Block &block);
    Book   transform(Block& block);

};


#endif //DEMO_BOOK_H
