理解：

> 在C++中，数组存储相同类型的数据。也可以通过struct声明一种数据结构，用于存储不同类型的数据。

声明方式：

```c++
struct type_name {
member_type1 member_name1;
member_type2 member_name2;
member_type3 member_name3;
.
.
} object_names;
```

type_name ：结构名； object_names：该结构的对象名；



## Typedef 关键字

typedef 可以为c++ 的类型声明一个别名，可以通过别名来进行访问该类型的变量。

typedef 使用在数据结构上时，在方法参数或者返回值，可省略struct。



**与Java 中语法比较**

C++中struct 声明的数据结构，与Java中实体类很相似。

