//Created by $HeXinGen on 2018/10/25.
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include "Book.h"


using namespace std;


const int Cols = 80;
const int Lines = 25;

/**
 * 声明，转跳选项中的子模块的函数
 */
void guideInput();
void viewData(int selPage);
void deleteBookFromFile();
void mainLoop();
void viewData(int iSelPage=1);

/**
 * 控制显示信息的行数,
 * 这里通过mode命令行
 */
void setScreenGrid() {
    char systemSetBuffer[Cols];

    sprintf(systemSetBuffer, "mode con cols=%d lines=%d", Cols, Lines);
}

/**
 * 设置标题栏上显示sample 信息
 * 执行title 命令行
 */
void setSysCaption() {
    system("title simple");
}

/**
 * 清除屏幕信息
 * 执行cls命令行
 */
void clearScreen() {
    system("cls");
}

/**
 * 设置标题栏,显示指定字符串
 * @param text
 */
void setSysCaption(const char *text) {
    char systemSetBuffer[Cols];
    sprintf(systemSetBuffer, "title %s", text);
    system(systemSetBuffer);
}

/**
 * 显示屏幕中信息
 */
void showWelcome() {
    for (int i = 0; i < 7; ++i) {
        cout << endl;
    }
    cout << setw(40);
    cout << "**************" << endl;
    cout << setw(40);
    cout << "图书管理系统" << endl;
    cout << setw(40);
    cout << "**************" << endl;
}

/**
 * 显示主菜单
 */
void showRootMenu() {
    cout << setw(40);
    cout << "请选择功能" << endl;
    cout << endl;
    cout << setw(38);
    cout << "1 添加新书" << endl;
    cout << endl;
    cout << setw(38);
    cout << "2 浏览全部" << endl;
    cout << endl;
    cout << setw(38);
    cout << "3 删除图书" << endl;
}

/**
 * 用于等待用户执行操作
 */
void waitUser() {
    cout << "enter返回主菜单 q退出" << endl;
    char buffer[256];
    // gets() 与cin类似，但前者接受连续的输入，包括空格，TAB。
    gets(buffer);
    if (buffer[0] == 'q') {
        system("exit");//执行退出命令行
    }
}

/**
 * 浏览数据的时候等待用户操作
 * @param currentPage
 */
void waitUser(int currentPage) {
    string buffer;
    cin >> buffer;
    if (buffer[0] == 'q') {
        system("exit");
    } else if (buffer[0] == 'm') {
        mainLoop();
    } else if (buffer[0] == 'n') {
        viewData(currentPage);
    }
}

/**
 * 获取用户输入选项
 * @return
 */
int getSelect() {
    char buffer[256];
    gets(buffer);
    //atoi()将字符串转成整形数
    return atoi(buffer);
}
/**
 * 主线程Loop()
 */
void mainLoop() {
    showWelcome();
    while (1) {
        clearScreen();
        showWelcome();
        showRootMenu();
        switch (getSelect()) {
            case 1:
                clearScreen();
                guideInput();
                break;
            case 2:
                clearScreen();
                viewData();
                break;
            case 3:
                clearScreen();
                deleteBookFromFile();
                break;
        }
    }
}

int main() {
    setScreenGrid();
    setSysCaption("图书馆管理系统");
    mainLoop();
    return 0;
}

/**
 * 添加图书模块
 */
void guideInput() {
    //定义Book对应的属性
    char cName[length_128];
    char cIsbn[length_128];
    char cPrice[length_50];
    char cAuthor[length_50];
    cout << "输入书名" << endl;
    cin >> cName;
    cout << "输入ISBN" << endl;
    cin >> cIsbn;
    cout << "输入价格" << endl;
    cin >> cPrice;
    cout << "输入作者" << endl;
    cin >> cAuthor;
    Book book(cName, cIsbn, cPrice, cAuthor);
    book.writeData();
    cout << " 输入书本信息的操作完成" << endl;
    waitUser();
}

/**
 * 获取文件的长度
 * @param in
 * @return
 */
long getFileLength(ifstream &in) {
    long currentIndex;
    long fileLength;
    currentIndex = in.tellg();
    in.seekg(0, ios::end);
    fileLength = in.tellg();
    in.seekg(currentIndex, ios::beg);
    return fileLength;
}

/**
 * 查看图书模块
 */
void viewData(int selPage ) {
    //定义Book对应的属性
    char cName[length_128];
    char cIsbn[length_128];
    char cPrice[length_50];
    char cAuthor[length_50];
    const int bookSize = (length_128 + length_128 + length_50 + length_50);
    int page = 0;
    int currentPage = 0;
    int dataCount = 0;
    bool existIndex = false;
    int fileLength;
    currentPage = selPage;
    ifstream in;
    const string fileName = "Book.dat";
    in.open(fileName, ios::binary);
    fileLength = getFileLength(in);
    dataCount = fileLength / bookSize;
    //存在书籍
    if (dataCount >= 1) {
        existIndex = true;
    }
    page = dataCount / 20 + 1;
    clearScreen();
    cout << "共有记录" << dataCount << "";
    cout << "共有页数" << page << "";
    cout << "当前页数" << currentPage << "";
    cout << "n 显示下一页 m 返回" << endl;
    cout << setw(5) << "Index";
    cout << setw(22) << "Name" << setw(22) << "Isbn";
    cout << setw(15) << "Price" << setw(15) << "Author" << endl;
    try {
        //根据书籍的编号在文件中查找。
        in.seekg(((currentPage - 1) * 20) * bookSize, ios::beg);
        if (!in.fail()) {
            for (int i = 1; i < 21; ++i) {
                memset(cName, 0, length_128);
                memset(cIsbn, 0, length_128);
                memset(cPrice, 0, length_50);
                memset(cAuthor, 0, length_50);
                if (existIndex) {
                    cout << setw(3) << (currentPage - 1) * 20 + i;
                    in.read(cName, length_128);
                    cout << setw(24) << cName;
                    in.read(cIsbn, length_128);
                    cout << setw(24) << cIsbn;
                    in.read(cPrice, length_50);
                    cout << setw(12) << cPrice;
                    in.read(cAuthor, length_50);
                    cout << setw(12) << cAuthor;
                    cout << endl;
                    if (in.tellg() < 0) {
                        existIndex = false;
                    } else {
                        existIndex = true;
                    }
                }
            }
        }
    } catch (...) {
        cout << "throw file exception" << endl;
        in.close();
        throw " file error occurred";
    }
    if (currentPage < page) {
        currentPage = (currentPage + 1);
        waitUser(currentPage);
    } else {
        waitUser(currentPage);
    }
    in.close();
}

/**
 * 删除图书模块
 */
void deleteBookFromFile() {
    int deleteIndex;
    cout << "输入删除书本的角标" << endl;
    cin >> deleteIndex;
    Book book;
    book.deleteData(deleteIndex);
    cout << "删除操作完成" << endl;
    waitUser();
}



