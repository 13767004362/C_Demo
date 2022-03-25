/**
 * @author ： HeXinGen
 * @date ： 2021/11/10
 * @description ：
 */
/**
 * 以#开头的预处理指令，用于导入头文件。
 * #include "" 是导入自己创建的头文件
 * #include <> 是c++中标准头文件
 */
#include <iostream>
#include <string>
/**
 * using namespace 使用命令空间
 *
 * namespace： 用于指定的名字，防止多个相同类冲突
 */
using namespace std;

/**
 * 程序的入口/主体 main()函数 ，返回值为int
 * @return
 */
int main(){
    string name;
    cin  >>name;//将控制台输入的字符串,存储到name变量中
    cout << name;
    cout <<" say :hello world"<<endl;

    return 0;
}