//Created by $HeXinGen on 2018/11/25.
//
#include <iostream>
using namespace std;
int main() {
    int i = 1, j = 2;
    // if  ...else 语句
    if (i > j) {
        cout << " 1 大于2 ，条件为真" << endl;
    } else {
        cout << " 1大于2 ， 条件为假" << endl;
    }
    //嵌套switch 语句
    switch (i) {
        case 1: {
            cout << " i的值等于" << i << endl;
            switch (j) {
                case 2:
                    cout << " j的值等于" << j << endl;
                    break;
                default:
                    break;
            }
        }
            break;
        default:
            break;

    }
    // 三元运算符
    cout<< " i > j "<<(i>j? true:false)<<endl;
    return 0;
}
