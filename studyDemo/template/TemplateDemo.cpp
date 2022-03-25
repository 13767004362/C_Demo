/**
 * @author ： HeXinGen
 * @date ： 2021/6/9
 * @description ：
 */

#include "TemplateDemo.h"
#include <iostream>
#include "string"
using namespace  std;

int main(){

    int a=10,b=100;
    cout<<" max() :"<<maxValue(a,b)<<endl;

    string  const  str_policemen_number="this is policemen phone number ";
    const int key1=110;
    //定义一个int-string的数据容器
    TemplateQueue<int ,string> int_str_queue;
    int_str_queue.add(key1,str_policemen_number);
    string  s=int_str_queue.get(key1);
    cout<<" map <int,string> ,key: "<<key1<<" value: "<<s<<endl;
    //定义一个string-string的数据容器
    TemplateQueue<string,string> str_str_queue;
    string const  key2=to_string(key1);
    str_str_queue.add(key2,str_policemen_number);
    cout<<" map <string,string> ,key: "<<key2<<" value: "<<str_str_queue.get(key2)<<endl;
    // 测试查询不存在的key
    string no_str=str_str_queue.get("1");
    cout<< (no_str.empty()?" key -> null value ":no_str);
    cout<< endl;
    return 0;
}