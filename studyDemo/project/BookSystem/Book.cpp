/**
 * @author ： HeXinGen
 * @date ： 2021/6/16
 * @description ：
 */

#include "Book.h"
#include "cstring"

using namespace ComBook;


/**
 * 定义友元函数
 * @param book
 * @return
 */


Book *Book::operator=(string &content) {
    vector<string> list;
    split(content, list, delimiter);
    if (list.size() > 0) {
        this->name = list[0];
        this->description = list[1];
    } else {
        // 解析失败，则抛出异常
        throw BookException(" Book content split error ");
    }
    return this;
}

void  ComBook::transform(Book & book, Block& block) {
    block.body  = tranform(book);
    //获取字节的长度
    block.head = block.body.size();
}

Book ComBook::transform(Block &block) {
    string& content=block.body;

    //delete block.body;
    Book book;
    book = content;
    return book;
}

void ComBook::writeBlock( const string fileName, Block block) {
    //打开文件,ios::binary 以二进制方式打开,追加方式写入
    ofstream out(fileName, ios::binary | ios::app);
    try {
        // 获取到int 的字节数
        int i_size=sizeof(block.head);
        char * i_char=(char *)&block.head;
        //reinterpret_cast<char *> 可以将int double[] 等非char* 类型数据进行转换
        out.write(i_char,i_size);
        out.write(const_cast<char *>(block.body.c_str()), block.head);
    } catch (...) {
        out.close();
        throw BookException("write block happen error ");
    }
    out.close();
}

Block ComBook::queryBlockByPosition(const string fileName, int &bookPosition) {
    ifstream in(fileName, ios::binary);
    Block block;
    try {
        int i = 1, blockPosition=0;
        while (true) {
            //从当前位置，继续移动
            if (blockPosition!=0){
                //将读指针（或写指针）从当前位置朝文件尾部移动 offset字节
                in.seekg((blockPosition),ios::cur);
            }
            // 读取头部
            char * i_char=(char *)&blockPosition;
             in.read(i_char,Block::int_size);
            if (i == bookPosition) {
                int currentIndex=in.gcount();// 获取当前的位置
                block.head = blockPosition;
                char buffer[block.head];
                in.read(buffer, blockPosition);
                block.body=buffer;
                break;
            } else {
                i++;
                continue;
            }
        }
    } catch (...) {
        in.close();
        throw BookException("");
    }
    in.close();
    return block;
}