**前言**：
>在C++中每个变量都有对应一个内存地址，可以通过&符号去访问该变量的内存地址。

**指针的含义**：

>指针是一个变量，其值是另外一个变量的内存地址。

**声明形式**:
`type *var-name`,type 是指针的基类型，它必须是一个有效的 C++ 数据类型，var-name 是指针变量的名称。

若是指针指向一个内存块，这种指针被称为void 指针。



**解除引用运算符**

*是解除引用运算符，也叫取值运算符。用于获取/更新某块内存地址的值。

**访问指针所指向的值**：一元运算符 * 来返回指针(即内存地址)指向的值.



通过一个案例来理解一下：
```c++
/**
 * 自定义指针：
 * 1.声明指针
 * 2.赋值指针
 * 3.获取指针指向的值
 */
void  testCustomPointer(){
    int  i=100;// 声明一个int 类型的变量
    int *iPointer;// 声明一个int * 类型的指针
    iPointer=&i;// 将变量的内存地址赋值给指针
    int i_new=*iPointer;// 获取指针指向的值，赋值给一个变量
    cout<< "i value: "<<i<<endl;
    cout<<"pointer :"<< iPointer<<" value: "<<i_new<<endl;

}
```
输出的结果：
```c++
 i value: 100
 pointer :0x61fde4 value: 100
```



--------------

#### **与Java 引用做对比**

先来了解一下，维基百科上**指针的含义**：

![](https://user-gold-cdn.xitu.io/2018/5/27/163a06043e9efb17?imageView2/0/w/1280/h/960/format/webp/ignore-error/1)

>指针是一个值，这个值是模块内存的地址。通过这个值，就可以找到这块内存。

**在C++中指针具备以下特点**：

- 可以指向内存的任何地方
- 指针可以参与数值运算，加法、减法。
- 指正还可以指向指针，即指针的指针（因为指针就是一个值，也要存在内存中，所以它也有一个内存地址)

在c++中，指针只关心内存的地址，不关心内存存储的值。如果该内存块的地址中对象被搬走了，指针不会自动改变指向。

**在Java 中引用**

在Java 中，没有指针，只有引用。

在Java 中引用：

> Java 引用也是一个值，但这个值不是某块内存的地址。而是某个值所在的内存的地址。当引用所指向的值搬家后，引用也会跟着变换。

Java中引用的特点：

- 引用在声明时，若没有赋值，则不占空间。
- 引用不可以进行数值运算

来理解一下，在Java 中by pass value :

在 Java 只有值传递，所谓的引用传递，传递的是引用的值。

在方法中传递参数，若是参数是基本数据类型，则参数是将基本数据类型的值传递过来；

若是参数是引用类型。则参数是将引用的值copy一份传递过过来。



资料参考：

- [java中的引用与c中的指针](https://juejin.cn/post/6844903613253287943)