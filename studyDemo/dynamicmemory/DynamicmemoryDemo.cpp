/**
 * @author ： HeXinGen
 * @date ： 2021/6/15
 * @description ：
 */
#include <iostream>
using namespace  std;
/**
 * 测试，普通变量，动态内存
 */
void test(){
    //初始化为 null的指针
    int* i=NULL;
    //动态分配内存
    i=new int ;
    //在分配的内存中赋值
    *i=100;
    cout<<i <<", "<< *i<<endl;
    //释放内存
    delete  i;
}
/**
 * 测试，数组分配内存
 */
void test1(){
    const  int size_1=2,size_2=3;
    //测试一唯数组
    int * array_i=NULL;
    array_i=new int [size_1];
    cout<<"[ ";
    for (int i = 0; i < size_1; ++i) {
        array_i[i]=(i+1);
        cout << array_i[i];
        if (i<size_1-1){
            cout<<"," ;
        }
    }
    cout<<" ] "<<endl;
    delete [] array_i;
    //测试二维数组
    int** array_i_2=NULL;
    array_i_2=new int *[size_1];
    for (int i = 0; i <size_1; ++i) {
         array_i_2[i]=new int[size_2];
    }
    for (int i = 0; i < size_1; ++i) {
        for (int j = 0; j <size_2 ; ++j) {
            int value=(i+1)*(j+1);
            array_i_2[i][j]=value;
        }
    }
    //打印二维数组
    cout<<"[ ";
    for (int i = 0; i <size_1; ++i) {
        cout<<"[";
        for (int j = 0; j <size_2 ; ++j) {
           cout<< array_i_2[i][j];
           if (j<size_2-1){
               cout<<",";
           }
        }
        cout<<"]";
        if (i<size_1-1){
            cout<<"," ;
        }
    }
    cout<<" ] "<<endl;
    //开始释放二唯数组
    for (int i = 0; i < size_1; ++i) {
        delete [] array_i_2[i];
    }
    delete [] array_i_2;


}

class Box{
public:
    Box(){
    }
    ~Box(){
        cout<<" Box is destroy "<<this<<endl;
    }
    void printSelf(){
        cout<<" Current Box is  "<<this<<endl;
    }
};
/**
 * 测试，对象分配内存
 */
void test2(){
    const  int size=3;
    //对象动态分配内存
    Box* box=new Box[size];
    //打印对象数组的信息
    for (int i=0;i<size;++i){
        box[i].printSelf();
    }
    //释放内存
    delete [] box;
}

int main(){
   // test();
   test1();
   //test2();
    return 0;
}