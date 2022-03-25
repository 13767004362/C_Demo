/**
 * @author ： HeXinGen
 * @date ： 2021/6/9
 * @description ：
 */

#ifndef DEMO_TEMPLATEDEMO_H
#define DEMO_TEMPLATEDEMO_H

#include <string>
#include <map>

using namespace std;


/**
 * 使用模板，定义一个泛型T 的比较方法，适合全部类型进行，大小比较
 * @tparam T
 * @param a
 * @param b
 * @return
 */
template<typename T>
T const& maxValue(const T &a, const T &b) {
    return a < b ? b : a;
}

/**
 * 使用模板，声明多个泛型参数的类
 * @tparam K
 * @tparam V
 */
template<class K, class V>
class TemplateQueue {
private:
    map<K, V> queue;
public:
    void add(K const &key, V const &value);
    V&  get(K const& key);
};

/**
 * 使用模板，声明一个类方法的定义。
 * @tparam K
 * @tparam V
 * @param key
 * @param value
 */
template<class K, class V>
void TemplateQueue<K, V>::add(K const &key, V const &value) {
    queue.insert(pair<K, V>(key, value));
}
template<class K, class V>
V& TemplateQueue<K,V>::get(K const& key) {
    return queue[key];
}

#endif //DEMO_TEMPLATEDEMO_H
