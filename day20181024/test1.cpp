//Created by $HeXinGen on 2018/10/24.
//理解多维数组，这里以二维数组为例子
#include <iostream>
using  namespace std;

#include <iomanip>
using std::setw;
int main(){
    /**
     *  初始化一个二维数组，内嵌括号可以省略，
     *  等同于 ：  int array[2][2]={1,11,111,1111};
     */
    int array[2][2]={{1,11},{111,1111}};
    cout<<"打印一个二维数组"<<endl;
    for (int i = 0; i <2 ; ++i) {
        for (int j = 0; j <2 ; ++j) {
            cout<<"array["<<i<<"]"<<"["<<j<<"]"<<setw(8)<<array[i][j]<<endl;
        }
    }
    return 0;
}
