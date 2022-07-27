/**
 * @author ： HeXinGen
 * @date ： 2022/7/8
 * @description ：
 *
 * const 修饰引用
 */#ifndef DEMO_REFERENCEDEMO_H
#define DEMO_REFERENCEDEMO_H

#include <iostream>
using  namespace std;


namespace Reference {


    /**
     *  const 修饰引用，不可以修改
     */
    static void testConstReference() {

        int i = 1;
        const int i3 = 11;
        const int &i2 = 111;
        //i2=10; 报错,不可以将一个非常量的引用赋值给const 修饰的引用
        // i2=i; 报错,不可以将一个非常量的引用赋值给const 修饰的引用
        // i2=i3; 报错，const 修饰的引用不可修改
        //int & const i4=111; 报错,const 不可以在&符号后修饰
    }

    bool  global_reference_b;
    /**
     * 测试方法中引用参数的修改
     */
    class Change{

    public:
        void testChangeValue(){
            int i=1;
            int & i1=i;
            change1(i1);
            cout<<i<<" , "<<i1<<endl;
            int* i2=&i;
            change2(i2);
            cout<<i<<" , "<<*i2<<endl;

            change3(i2);
            cout<<i<<" , "<<*i2<<endl;

        }
        void change1(int & i){
            i=110;
        }
        /**
         * int *& p, 是正确的， &与p靠得最近，所以p是一个引用，这个引用的类型是int*，也就是一个指针变量的引用
         * @param i
         */
        void change2(int * &i){
            *i=120;
        }

        void change3(int * &i){
            int new_i=111;// 定义一个局部变量,离开该方法的范围会失效
            i=&new_i;//修改了新的地址 , 注意点： 因new_i 是局部变量,离开该方法的范围会失效,因此 i的值可能会是初始值0
        }
    };



}


#endif //DEMO_REFERENCEDEMO_H
