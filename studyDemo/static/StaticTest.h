/**
 * @author ： HeXinGen
 * @date ： 2021/10/28
 * @description ：
 *
 * static 修饰类的属性时，该属性在所有该类对象中共享；
 * static 修饰函数中局部变量时，该变量的值将在多次调用中保持不变；
 * static 修饰成员函数时，该方法在所有成员之间共享
 *
 */
 class  StaticTest{
 public:
     //声明一个静态的常量
     static  const int i=0;
     //声明一个静态方法
     static const int&  queryI(){

         return i;
     }

 };
//声明一个静态全局变量
static int j=5;