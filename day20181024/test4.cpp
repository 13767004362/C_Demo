//Created by $HeXinGen on 2018/10/24.

//����ģ�壬����
#include <iostream>
#include <string>
using namespace std;
//����һ��ģ��ıȽϴ�С�ķ���,typename��������ģ�壬��class��ͬ
template <typename T> inline T const & Max (T const& a,T const& b){
    return a<b?a:b;
}
int main(){
    //��������int���͵ı���
    int a=1;
    int b=2;
    cout<<"���ö����ģ��Ƚϴ�С�ķ���Max(),��("<<a<<","<<b<<")�����߽��бȽ�,���ֵ�ǣ�"<<Max(a,b)<<endl;
    //��������string���͵ı���
    string c="HXG";
    string d="HeXinGen";
    cout<<"���ö����ģ��Ƚϴ�С�ķ���Max(),��("<<c<<","<<d<<")�����߽��бȽ�,���ֵ�ǣ�"<<Max(c,d)<<endl;
    return 0;
}

