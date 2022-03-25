/**
 * @author ： HeXinGen
 * @date ： 2021/10/28
 * @description ：
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