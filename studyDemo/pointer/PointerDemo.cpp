/**
 * @author ： HeXinGen
 * @date ： 2021/6/1
 * @description ：
 */

#include <iostream>

using namespace std;

//声明一些指针的方法，对应着使用案例
void testCustomPointer();

void testNullPointer();

void testPointerCalculation();

void testPointerArray();

void testPointerAndPointer();

void testMethodParamsPointer();
void getAverage(int *array, int * size);
void testMethodReturnPointer();
int* doubleMultiply(int * a);


void testPointer();

void testConstPointer();

int main() {
    //testCustomPointer();
    testNullPointer();
     //testPointerCalculation();
    //testPointerArray();
  // testPointerAndPointer();
 // testPointer();
 //testConstPointer();

  // testMethodReturnPointer();
    return 0;
}
/**
 *  指针赋值；
 *  指针指向内存块进行赋值；
 */
void testPointer(){
    int i=10;
    int * i_p=&i;//通过&引用运算符将i变量的地址赋值给指针

    *i_p=12;//通过*解除引用运算符,将新值设置给指针指向的内存。
    cout<<" i "<<i <<" , "<<*i_p <<", "<<i_p<<endl;
    int c=100;
    i_p=&c;// 将新的内存地址设置给指针变量
    cout<<" i "<<i <<" , "<<*i_p <<", "<<i_p<<endl;

};
/**
 * const 关键字用于指针：
 * 1.指针指向的内存地址是常量，可修改指向地址的数据值。 例如： int * const pointer=&a;
 * 2.指针指向地址的值是常量，可修改指向的地址；例如： const int * pointer=&a;
 * 3.指针指向的地址和指向地址的数据值都是常量；：例如 const int* const pointer=&a;
 *
 */
void testConstPointer(){
    int a=1,b=2,c=3;
    int * const  a_pointer=&a;
    *a_pointer=11;//只能修改指针指向内存的数据值
    cout<<"int * const "<<*a_pointer<<endl;
    const int * b_pointer=&b;
    b_pointer=&a; //只能修改指针指向的内存地址值；
    cout<<"const int * "<<*b_pointer<<endl;
    const  int  * const  c_pointer=&c;//啥也不能修改
    cout<<"const int * const "<<*c_pointer<<endl;



}
/**
 * 自定义指针：
 * 1.声明指针
 * 2.赋值指针
 * 3.获取指针指向的值
 */
void testCustomPointer() {
    int i = 100;// 声明一个int 类型的变量
    int *iPointer;// 声明一个int * 类型的指针
    iPointer = &i;// 将变量的内存地址赋值给指针
    int i_new = *iPointer;// 获取指针指向的值，赋值给一个变量
    cout << "i value: " << i << endl;
    cout << "pointer :" << iPointer << " value: " << i_new << endl;
    // 将指针重新赋值一个新的内存地址
    int a=1000;
    iPointer=&a;
    cout << "pointer :" << iPointer << " value: " << i <<" , " <<i_new << endl;
}

/**
 * NULL 指针是一个定义在标准库中的值为零的常量
 *
 * 注意点：不可以通过 * pointer 方式去访问NUll指向的值
 */
void testNullPointer() {
    int *iPointer;
    if (iPointer) { //未赋值的指针，if
        cout << "unknown pointer, if(ptr) is true ,pointer  : " << iPointer << endl;
    }
    iPointer = NULL;// 赋值未一个null 指针
    if (!iPointer) { // 当指针 pointer 是Null， if(！pointer) 是成立的
        cout << "null pointer, if(!ptr) is true,pointer  : " << iPointer << endl;
    }
    int i = 1;
    iPointer = &i; // 赋值一个非null 的指针
    if (iPointer) {
        cout << "no null pointer, if(ptr)  is true ,pointer : " << iPointer << endl;
    }
}

/**
 * 变量指针可以递增，而数组不能递增，因为数组是一个常量指针
 * 指针可以递增，可以递减，可以比较
 *
 * 一个数组名对应一个指针常量，不能改变数组的值，可以修改数组元素
 */
const int size = 3;

void testPointerCalculation() {
    int array[size] = {10, 100, 100};
    int *i_pointer = array;// 将数组第一个元素的内存地址，赋值给指针
    for (int i = 0; i < size; ++i) {
        // 打印 指针 和 指针所指向的值
        cout << " array[ " << i << "] , pointer: " << i_pointer << " value: " << *i_pointer << endl;
        i_pointer++;// 指针递增，可以顺序访问数组元素
    }
    //获取到数组中最后一个元素的内存地址
    int *last_pointer = &array[size - 1];
    i_pointer = array;
    int i = 0;
    while (i_pointer <= last_pointer) {
        cout << " array[ " << i << "] , pointer: " << i_pointer << " value: " << *i_pointer << endl;
        i_pointer++;// 指针递增
        i++;
    }
    //通过指针访问数组中的元素
    i_pointer=array;
    for (int j = 0; j <size ; ++j) {
        cout << " array[ " << j << "] , pointer: " << &i_pointer[j] << " value: " << i_pointer[j] << endl;
    }

    i_pointer = array;
    //通过指针来修改数组中元素
    for (int j = 0; j < size; ++j) {
        *i_pointer = j; // 将新值 , 赋值给指针所指向的内存地址。
        cout << " array[ " << j << "] , pointer: " << i_pointer << " value: " << *i_pointer << endl;
        i_pointer++;// 指针递增
    }
}

/**
 * 测试指针数组
 */
void testPointerArray() {
    int array[size] = {10, 100, 1000};
    int *pointer[size];
    for (int i = 0; i < size; ++i) {
        // 数组中元素的内存地址赋值给指针
        pointer[i] = &array[i];
        cout << "pointerArray[ " << i <<"]"<<", pointer: "<< pointer[i]<< " , value: " << *pointer[i] << endl;
    }
    // 一个指向字符的指针数组来存储一个字符串列表
   char *strPointer[size] ={"10Str","100Str","1000Str"};
    for (int i = 0; i < size ; ++i) {
        char * charPointer=strPointer[i];
        cout << "pointerArray[ " << i <<"]"<<", pointer: "<< charPointer<< " , value: " << &strPointer[i] << endl;
    }
}
/**
 * 指向指针的指针是一种多级间接寻址的形式，或者说是一个指针链。
 * 指针的指针就是将指针的地址存放在另一个指针里面
 *
 * 一个指向指针的指针变量必须如下声明，即在变量名前放置两个星号
 */
void testPointerAndPointer(){
       int i=10;
       int *iPointer=&i;
       int **iPPointer=&iPointer;
       cout<<"var :"<<i<<endl;
       cout<<"pointer var: "<<iPointer<< " value: "<<*iPointer<<endl;
       cout<<"double pointer var:"<<iPPointer<<" front pointer: "<<*iPPointer<<" value: "<<**iPPointer<<endl;
}
/**
 * 顶层指针和https://blog.csdn.net/qq_19528953/article/details/50922303
 *
 */
int s=3;
void testMethodParamsPointer(){
       int arr[size]={10,100,1000};
       getAverage(arr,&s);
}

void getAverage(int * array,  int * size){
    int sum;
    for (int i = 0; i < *size ; ++i) {
        sum+=array[i];
    }
    double  result=double(sum)/ *size;
    cout<< " result "<<result<<endl;

}

void testMethodReturnPointer(){
    int i=10;
    int * result=doubleMultiply(&i);
    cout<< "  "<<i <<" multiply:"<< *result<< endl;
}
/**
 * C++ 不支持在函数外返回局部变量的地址，除非定义局部变量为 static变量。
 * @param a
 * @return
 */
int* doubleMultiply(int * a){
     static  int i;// 声明一个静态变量
     i=*a * *a;
    return &i;
}