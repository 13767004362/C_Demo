//Created by $HeXinGen on 2018/10/24.

//��̬�ڴ棬new�����������̬�ڴ棬delete�����ɾ��new�����Ķ�̬�ڴ档
#include <iostream>
using  namespace std;
/**
 * ����һ����
 */
class Demo{
public:
    Demo(){
        cout<<"����Demo�Ĺ��캯��"<<endl;
    }
    ~Demo(){
        cout<<"����Demo����������"<<endl;
    }
};
//����һ����̬���������ĺ���
void  dynamicCreateClass();
//����һ����̬����һά����ĺ���
void  dynamicCreateOneDimensionalArray();
//����һ����̬����ά����ĺ���
void  dynamicCreateTwoDimensionalArray();

int  main(){
    dynamicCreateOneDimensionalArray();
    dynamicCreateTwoDimensionalArray();
    dynamicCreateClass();
    return 0;
}
void  dynamicCreateOneDimensionalArray(){
    //ͨ��new �ؼ��֣�����һ������Ϊ5��int ���͵�����,���䶯̬�ڴ�
    const  int length=2;
    int * pointer =new int [length];
    cout<<"new�������̬������һά����,������ڴ��ַ��: "<<pointer<<endl;
    //�����ֵ
    for (int i = 0; i <length; ++i) {
        pointer[i]=10+i;
    }
    //�����ӡ
    for (int j = 0; j < length; ++j) {
        cout<<"һά������,��"<<j<<"�Ǳ��ֵ��:"<<pointer[j]<<endl;
    }
    // delete �������ɾ��֮ǰ�� new �����������ڴ�
    delete  [] pointer;
    cout<<"delete�����ɾ��,��̬������һά������ڴ�......."<<endl;
}
void  dynamicCreateTwoDimensionalArray(){
    const  int length=2;
    const  int length2=3;
    //����һ��2��3�еĶ�ά����
    int **pointer=new int *[length];
    for (int i = 0; i <length; ++i) {
        //����һά�����е�����
        pointer[i]=new int[length2];
    }
    cout<<"new�������̬�����Ķ�ά����,������ڴ��ַ��: "<<pointer<<endl;
    //��ֵ
    for (int k = 0; k <length ; ++k) {
        for (int i = 0; i <length2 ; ++i) {
            if (k==0){
                pointer[k][i]=100+i;
            }else{
                int add=length2+i;
                pointer[k][i]=100+add;
            }
        }
    }
    //�����ӡ
    for (int j = 0; j < length; ++j) {
        for (int i = 0; i < length2; ++i) {
            cout<<"��ά����["<<j<<"]["<<i<<"]"<<"ֵ:"<<pointer[j][i]<<endl;
        }
    }
    //ɾ����ά�����еڶ�ά��
    for (int l = 0; l <length ; ++l) {
        delete [] pointer[l];
    }
    // delete �������ɾ��֮ǰ�� new �����������ڴ�
    delete  [] pointer;
    cout<<"delete�����ɾ��,��̬�����Ķ�ά������ڴ�......."<<endl;
}
void  dynamicCreateClass(){
    cout<<"new�������̬�����������ڴ� "<<endl;
    Demo* pointer=new Demo[2];
    delete [] pointer;
    cout<<"delete�����ɾ��,��̬�������������ڴ�......."<<endl;
}