//Created by $HeXinGen on 2018/10/25.
//定义常量
const int length_128 = 128;
const int length_50 = 50;

class Book {
public://构造方法
    Book() {};

    Book(char *cName, char *cIsbn, char *cPrice, char *cAuthor);

    ~Book() {};
protected://四个属性
    char name[length_128];
    char isbn[length_128];
    char price[length_50];
    char author[length_50];

public://定义需要使用的函数
    //属性的set()方法
    void setName(char *cName);

    void setIsbn(char *cIsbn);

    void setPrice(char *cPrice);

    void setAuthor(char *cAuthor);

    //属性的get()方法
    char *getName();

    char *getIsbn();

    char *getPrice();

    char *getAuthor();


    void writeData(); //写入数据到文件中
    void deleteData(int count);//删除数据
    void getBookFromFile(int count);//从文件获取数据
};

