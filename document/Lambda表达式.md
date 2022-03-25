**理解**：

> C++11 提供了对匿名函数的支持,称为 Lambda 函数(也叫 Lambda 表达式)。Lambda 表达式把函数看作对象。Lambda 表达式可以像对象一样使用，比如可以将它们赋给变量和作为参数传递，还可以像函数一样对其求值。

**格式**：

```c++
[capture list] (params list) mutable exception-> return type { function body }
```

**capture list 捕捉列表**：

- []：默认不捕获任何变量；
- [=]：默认以值捕获所有变量；
- [&]：默认以引用捕获所有变量；
- [x]：仅以值捕获x，其它变量不捕获；
- [&x]：仅以引用捕获x，其它变量不捕获；
- [=, &x]：默认以值捕获所有变量，但是x是例外，通过引用捕获；
- [&, x]：默认以引用捕获所有变量，但是x是例外，通过值捕获；
- [this]：通过引用捕获当前对象（其实是复制指针）；
- [*this]：通过传值方式捕获当前对象；

**mutable**： 可以修改捕捉的变量。



当fuction body 只有一个返回值时，return type 可省略。



**与Java 中Lambda表达式相比较**：

- 在java Lambda 中没有存在捕获列表
- 在Java Lambda中可以访问外部变量，但不可以修改外部变量的值，即外部变量的引用值不变，即final修饰。
- 在Java Lambda中，this 是指向外部类的对象引用，并不是匿名对象本身。



