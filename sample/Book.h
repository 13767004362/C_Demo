//Created by $HeXinGen on 2018/10/25.
//���峣��
const int length_128 = 128;
const int length_50 = 50;

class Book {
public://���췽��
    Book() {};

    Book(char *cName, char *cIsbn, char *cPrice, char *cAuthor);

    ~Book() {};
protected://�ĸ�����
    char name[length_128];
    char isbn[length_128];
    char price[length_50];
    char author[length_50];

public://������Ҫʹ�õĺ���
    //���Ե�set()����
    void setName(char *cName);

    void setIsbn(char *cIsbn);

    void setPrice(char *cPrice);

    void setAuthor(char *cAuthor);

    //���Ե�get()����
    char *getName();

    char *getIsbn();

    char *getPrice();

    char *getAuthor();


    void writeData(); //д�����ݵ��ļ���
    void deleteData(int count);//ɾ������
    void getBookFromFile(int count);//���ļ���ȡ����
};

