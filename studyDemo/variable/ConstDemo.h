/**
 * @author ： HeXinGen
 * @date ： 2021/11/10
 * @description ：
 */
 #ifndef DEMO_CONSTDEMO_H
#define DEMO_CONSTDEMO_H


/**
 *  关键字 constexpr 声明的常量表达式
 */
constexpr int  area(){
    return 10*10;
}

const int  i=10;// 使用const 声明常量

/**
* enum 常量
*/

enum  Position{
    position_0=0,
    position_1000=1000
};

#define   i_10000 10000; //使用#define 定义常量的做法已被摒弃，因此不应采用这种做法。

#endif //DEMO_CONSTDEMO_H