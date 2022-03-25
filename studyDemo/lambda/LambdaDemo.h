/**
 * @author ： HeXinGen
 * @date ： 2021/6/8
 * @description ：
 */

#ifndef DEMO_LAMBDADEMO_H
#define DEMO_LAMBDADEMO_H

/**
 * Lambda 表达式： [capture list] (params list) mutable exception-> return type { function body }
 *
 *
 * 其中capture list 捕捉列表详细介绍如下：
 * []：默认不捕获任何变量；
 * [=]：默认以值捕获所有变量；
 * [&]：默认以引用捕获所有变量；
 * [x]：仅以值捕获x，其它变量不捕获；
 * [&x]：仅以引用捕获x，其它变量不捕获；
 * [=, &x]：默认以值捕获所有变量，但是x是例外，通过引用捕获；
 * [&, x]：默认以引用捕获所有变量，但是x是例外，通过值捕获；
 * [this]：通过引用捕获当前对象（其实是复制指针）；
 * [*this]：通过传值方式捕获当前对象；
 */
class Product {
private:
    int a;
public:
    Product(int a) {
        this->a = a;
    }

    int calculation(int c) {
        //捕捉this
        return [this](int b) { return a * b; }(c);
    }
};

#endif //DEMO_LAMBDADEMO_H
