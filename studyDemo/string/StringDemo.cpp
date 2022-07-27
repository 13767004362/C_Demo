/**
 * @author ： HeXinGen
 * @date ： 2021/6/9
 * @description ：
 */
#include <iostream>
#include "string"
#include "cstring"
using namespace  std;

/**
 * 参考：https://blog.csdn.net/m0_37592397/article/details/79701992
 */
void testString(){
    string  a="100";
    string  b="100";
    string  c(a);
    string  d=a;
    cout<< &a << " , "<<&b<< " , "<<&c<<" , "<<&d<<endl;
}
/**
 * 测试赋值
 */
void testStringAssignment(){
    //获取5个重复的字节
    string  repeatChars(5,'a');
    //获取前5位的字符
    string  partChars("hello world",5);
    string chars("hello World");
    cout<<chars<<" , "<<repeatChars<<" , "<<partChars<<endl;
}

void testStringContent(){
    string chars("helloWorld");
    /**
     * 采用下标运算符（[]）访问字符串的内容
     */
    //size_t 通用用于数组的下标访问，替代int
    for (size_t i=0;i<chars.length();++i){
        if(i==0){
            cout<<"[";
        }
        cout<<chars[i];
        if (i==chars.length()-1){
            cout<<"]"<<endl;
        }else{
            cout<<",";
        }
    }
  /**
   * 使用迭代器访问字符串
   */
    int i=0;
    for(auto charLocator=chars.begin();charLocator!=chars.end();++charLocator){
        if(i==0){
            cout<<"[";
        }
        cout<<*charLocator;
        if (i==chars.length()-1){
            cout<<"]"<<endl;
        }else{
            cout<<",";
        }
        i++;
    }



}

/**
 * 测试string 与char * 相互转换
 */
void testStringToChar(){
    const char  *c="hello";
    //直接赋值
    string  str1=c;
    cout<<"str: "<<str1<<endl;
    //构造函数转换
    string  str2(c,c+strlen(c));
    cout<<"str: "<<str2<<endl;
    //要赋值类型转换
    char *temp=const_cast<char* >(str1.c_str());
    cout<<"temp: "<<temp<<endl;


}

/**
 * 测试string 与char[] 相互转换
 */
void testStringToCharArray(){
    char c[]="hello";
    //直接赋值
    string  str1=c;
    cout<<"str: "<<str1<<endl;
    //构造函数转换
    string  str2(c,c+strlen(c));
    cout<<"str: "<<str2<<endl;
    //转成char[] 要拷贝实现
    char temp[str1.length()];
    strncpy(temp,str1.c_str(),str1.length()+1); // 注意，一定要加1，否则没有赋值'\0'
    cout<<"temp: "<<temp<<endl;


}
void test(){
    string s="helloWorld";
    char * b=(char* )s.c_str();
    string  temp=b;
    int size= strlen(b);
    cout<<" old "<<b<<" , "<<temp<<endl;
}

/**
 *   == 内存地址的比较，string 是可以直接比较的。
 *   但char[] 是需要 strcmp() 函数比较, 因数组本身是一个指针，*指针 是指向数组的首元素。
 * @return
 */

void testEqual(){
    char  a[] ="123", b[]="123";
    string c="123",d="123";
    cout<<" char[]  == result 1 is true: "<<(a==b)<<endl;
    cout<<" char[]  strcmp()  result 0 is true : "<<strcmp(a,b)<<endl;
    cout<<" string  == result 1 is true : "<<(c==d)<<endl;
    cout<<" string[]  compare()  result 0 is true: "<<c.compare(d) <<endl;

}


int main(){
    testEqual();
    return 0;
};