//Created by $HeXinGen on 2018/11/25.
//

#include <iostream>
#include <string>
#include <cstring>
using  namespace std;

/**
 * ����һ�����ݽṹ���ṹ����Ϊdata
 */
struct  Data{
    char name[16];
    int age;
} data;

int main(){
    // sizeOf() ��ȡ�������ֽڴ�С
    cout<<" int ���͵��ֽڴ�С ��"<< sizeof(int)<< ", int���͵ı������ֽڴ�С ��"<< sizeof(100)<<endl;

    //��������� ?  :
    int result_bool=(1>0)? true:false;
    cout<<" 1>0?true:false��Ԫ����� ��"<<result_bool<<endl;

    // ,���������,��˳��ִ�У���ȡ���һ�����
    int i=9,j;
    j=(i++,i*i);//��i++,��ִ��j=i*i;
    cout<<" �������������������Ľ���ǣ�"<<j<<endl;

    //ǿ��ת�������
    double  d=20.111;
    int result_int=(int)d;
    cout<<"doubleǿ��תint��20.111��Ӧ��int���͵�ֵ�ǣ�"<<result_int<<endl;

    //.��������
    strcpy(data.name,"c++������");
    cout<<" ��������,���и�ֵ������nameΪ; "<<data.name<<endl;

    //->��ͷ�������&����� *ָ�������
    struct  Data * data_pointer=&data;
    data_pointer->age=24;
    cout<<" ->��ͷ����� ,���и�ֵ������ageΪ; "<<data_pointer->age<<endl;
    return  0;
}

