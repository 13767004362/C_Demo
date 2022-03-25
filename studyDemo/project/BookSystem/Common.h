/**
 * @author ： HeXinGen
 * @date ： 2021/6/16
 * @description ：
 */

#ifndef DEMO_COMMON_H
#define DEMO_COMMON_H

#include <fstream>
#include "vector"
#include "string"


using namespace std;

// *****************************定义一些通用的操作 *****************************



/**
 * 定义一个分隔符
 */
const string delimiter = " --> ";

//定义文件名,"../" 表示当前目录的上级目录,即当前的父目录
const string  fileName="../Book.txt";


/**
 * 分割字符串
 * @param content
 * @param list
 * @param delimiter
 */
static void split(const string & content,vector<string>& list,const string delimiter=""){
    list.clear();
    //获取到第一个分割符前面的位置

    int index=0;
    size_t t;
    while (true){
         t=content.find(delimiter,index);
        if (t!=string::npos){
            list.push_back(content.substr(index,t));
            index=t+delimiter.length();
            continue;
        }else{
            if(index!=0&&index!=(content.length()-1)){
                list.push_back(content.substr(index,content.length()-1));
            }
            break;
        }
    }
}

/**
 * 获取文件的长度
 * @param in
 * @return
 */
static long queryFileLength(ifstream &in) {
    long position, fileLength;
    // 记录当前流的位置
    position = in.tellg();
    //移到最后的位置
    in.seekg(0, ios::end);
    fileLength = in.tellg();
    // 恢复到原本的位置
    in.seekg(position, ios::beg);
    return fileLength;
}


#endif //DEMO_COMMON_H
