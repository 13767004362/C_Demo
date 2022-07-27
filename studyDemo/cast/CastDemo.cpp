/**
 * @author ： HeXinGen
 * @date ： 2022/6/6
 * @description ：
 */
#include "CastDemo.h"
#include <string>



int main(){
    testStaticCast();
    //testDynamicCast();
   // testConstCase();
    return 0;
}

/**
 * const_case 用于关闭对象的访问修饰符const。
 */
void testConstCase(){
    string s="s";
    char * cP= const_cast<char *> (   s.c_str());

    cout<<" test const_cast : "<<*cP<<endl;
}

/**
 * static_cast 是用于相互类型(基类与派生类)的指针之间转换
 * 在编译期做检查
 */
void testStaticCast(){
    Impl impl;// 声明一个派生类对象

    Base * base=&impl;//向上转换, 用基类的指针去接收派生类对象

    Impl * implP= static_cast<Impl* >(base); //向下转换，用派生类的指针接收基类的指针。
    cout<<" use  static_cast  test "<<base<<" , "<<implP<<endl;
}
/**
 * dynamic_cast 用于运行时的类型转换，若是失败返回Null.可以用于判断是否转换成功。
 * 类似java 中 instanceOf
 */
void testDynamicCast(){
    Impl impl;
    Base * base=&impl;//向上转换, 用基类的指针去接收派生类对象
    Impl *  implP= dynamic_cast<Impl* >(base);
    if (implP){
        implP->print();
    }
    cout<<" use dynamic_cast  test "<<endl;
}
