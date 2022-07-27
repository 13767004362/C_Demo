/**
 * @author ： HeXinGen
 * @date ： 2021/6/15
 * @description ：
 *
 * 为啥要使用动态内存分配：
 * 像数组的内存分配是静态和固定的，可能遇到超出容量或者使用部分容量的情况；
 * 为了更好的根据用户需求来分配内存，采用动态分配内存。
 *
 * new 关键字来分配内存块，若是成功new 将返回指向一个指针，指向分配的内存，否则会引发异常
 *
 * 对于使用new[...]分配的内存块，需要使用delete[]来释放；
 * 对于使用new为单个元素分配的内存，需要使用delete来释放；
 *
 *
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
/**
 * 当使用new 关键字时，失败了会抛出异常
 * 如何正确的使用new 关键字，
 * 一种是加
 * try {
 * }
 * catch(bad_alloc){
 * }
 *
 *另外一种：
 * new(nothrow) 它在分配内存失败时返回Null
 */
void testSafeNewMemory(){
    long long int large=1111111111111111;
    int * i=NULL;
    try {
        i=new int[large];
        delete[] i;
    }catch (bad_alloc){
        cout << "Memory allocation failed. Ending program" << endl;
    }
    i=new(nothrow)  int[large];//使用 new(nothrow)，它在分配内存失败时返回 NULL
    if (i){
        delete[] i;
    }else{
        cout << "Memory allocation failed. Ending program" << endl;
    }


}

int main(){
   // test();
  // test1();
   //test2();
   testSafeNewMemory();
    return 0;
}