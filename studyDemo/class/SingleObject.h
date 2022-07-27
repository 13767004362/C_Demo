/**
 * @author ： HeXinGen
 * @date ： 2022/7/6
 * @description ：
 *
 * 单例对象
 *
 */#ifndef DEMO_SINGLEOBJECT_H
#define DEMO_SINGLEOBJECT_H

#include <iostream>
using  namespace std;
class  SingleObject{
private:
    int id;
    //私有的构造函数
    SingleObject(){

    }
    //私有的复制构造函数
    SingleObject(const SingleObject & singleObject);
    //私有的复制 赋值预算福
    SingleObject & operator=(const SingleObject &singleObject);

public:
    static  SingleObject& getInstance(){
        //该静态局部变量，只会创建一次
        static  SingleObject singleObject;
        cout<<" singleObject address: "<< &singleObject<<endl;
        return singleObject;
    }

    int  getId ()const {
        return id;
    }
    void setId(int id){
        this->id=id;
    }
};
/**
 * 测试单例对象
 */
static  void testSingleObject(){
   SingleObject & obj1=  SingleObject::getInstance();
   obj1.setId(110);
   SingleObject & obj2= SingleObject::getInstance();
   cout<<obj2.getId()<<endl;
}

#endif //DEMO_SINGLEOBJECT_H
