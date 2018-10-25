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
 * ������ת��ѡ���е���ģ��ĺ���
 */
void guideInput();
void viewData(int selPage);
void deleteBookFromFile();
void mainLoop();
void viewData(int iSelPage=1);

/**
 * ������ʾ��Ϣ������,
 * ����ͨ��mode������
 */
void setScreenGrid() {
    char systemSetBuffer[Cols];

    sprintf(systemSetBuffer, "mode con cols=%d lines=%d", Cols, Lines);
}

/**
 * ���ñ���������ʾsample ��Ϣ
 * ִ��title ������
 */
void setSysCaption() {
    system("title simple");
}

/**
 * �����Ļ��Ϣ
 * ִ��cls������
 */
void clearScreen() {
    system("cls");
}

/**
 * ���ñ�����,��ʾָ���ַ���
 * @param text
 */
void setSysCaption(const char *text) {
    char systemSetBuffer[Cols];
    sprintf(systemSetBuffer, "title %s", text);
    system(systemSetBuffer);
}

/**
 * ��ʾ��Ļ����Ϣ
 */
void showWelcome() {
    for (int i = 0; i < 7; ++i) {
        cout << endl;
    }
    cout << setw(40);
    cout << "**************" << endl;
    cout << setw(40);
    cout << "ͼ�����ϵͳ" << endl;
    cout << setw(40);
    cout << "**************" << endl;
}

/**
 * ��ʾ���˵�
 */
void showRootMenu() {
    cout << setw(40);
    cout << "��ѡ����" << endl;
    cout << endl;
    cout << setw(38);
    cout << "1 �������" << endl;
    cout << endl;
    cout << setw(38);
    cout << "2 ���ȫ��" << endl;
    cout << endl;
    cout << setw(38);
    cout << "3 ɾ��ͼ��" << endl;
}

/**
 * ���ڵȴ��û�ִ�в���
 */
void waitUser() {
    cout << "enter�������˵� q�˳�" << endl;
    char buffer[256];
    // gets() ��cin���ƣ���ǰ�߽������������룬�����ո�TAB��
    gets(buffer);
    if (buffer[0] == 'q') {
        system("exit");//ִ���˳�������
    }
}

/**
 * ������ݵ�ʱ��ȴ��û�����
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
 * ��ȡ�û�����ѡ��
 * @return
 */
int getSelect() {
    char buffer[256];
    gets(buffer);
    //atoi()���ַ���ת��������
    return atoi(buffer);
}
/**
 * ���߳�Loop()
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
    setSysCaption("ͼ��ݹ���ϵͳ");
    mainLoop();
    return 0;
}

/**
 * ���ͼ��ģ��
 */
void guideInput() {
    //����Book��Ӧ������
    char cName[length_128];
    char cIsbn[length_128];
    char cPrice[length_50];
    char cAuthor[length_50];
    cout << "��������" << endl;
    cin >> cName;
    cout << "����ISBN" << endl;
    cin >> cIsbn;
    cout << "����۸�" << endl;
    cin >> cPrice;
    cout << "��������" << endl;
    cin >> cAuthor;
    Book book(cName, cIsbn, cPrice, cAuthor);
    book.writeData();
    cout << " �����鱾��Ϣ�Ĳ������" << endl;
    waitUser();
}

/**
 * ��ȡ�ļ��ĳ���
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
 * �鿴ͼ��ģ��
 */
void viewData(int selPage ) {
    //����Book��Ӧ������
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
    //�����鼮
    if (dataCount >= 1) {
        existIndex = true;
    }
    page = dataCount / 20 + 1;
    clearScreen();
    cout << "���м�¼" << dataCount << "";
    cout << "����ҳ��" << page << "";
    cout << "��ǰҳ��" << currentPage << "";
    cout << "n ��ʾ��һҳ m ����" << endl;
    cout << setw(5) << "Index";
    cout << setw(22) << "Name" << setw(22) << "Isbn";
    cout << setw(15) << "Price" << setw(15) << "Author" << endl;
    try {
        //�����鼮�ı�����ļ��в��ҡ�
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
 * ɾ��ͼ��ģ��
 */
void deleteBookFromFile() {
    int deleteIndex;
    cout << "����ɾ���鱾�ĽǱ�" << endl;
    cin >> deleteIndex;
    Book book;
    book.deleteData(deleteIndex);
    cout << "ɾ���������" << endl;
    waitUser();
}



