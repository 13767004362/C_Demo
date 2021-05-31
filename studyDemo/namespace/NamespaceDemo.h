/**
 * @author ： HeXinGen
 * @date ： 2021/5/31
 * @description ：
 *
 *  使用 namespace 的案例
 */

#ifndef DEMO_NAMESPACEDEMO_H
#define DEMO_NAMESPACEDEMO_H

/**
 * 自定义命名空间 进行 计算
 */
namespace area {
    /**
     * 声明一个变量
     */
    int maxWidth;
    int maxHeight;

    /**
     * 声明一个类
     */
    class Area {
    private:
        int width, height;
    public:
        Area(){

        }
        Area(int width, int height) {
            this->width = width;
            this->height = height;
        }

        int multiply() {
            width = width > maxWidth ? maxWidth : width;
            height = height > maxHeight ? maxHeight : height;
            return width * height;
        }

    };

    /**
     *  声明一个方法 ，计算
     * @param maxWidth
     * @param maxHeight
     * @param width
     * @param height
     * @return
     */
    int calculation(int maxWidth, int maxHeight, int width, int height) {
        area::maxWidth = maxWidth;
        area::maxHeight = maxHeight;
        Area area1(width, height);
        return area1.multiply();
    }
}

#endif //DEMO_NAMESPACEDEMO_H
