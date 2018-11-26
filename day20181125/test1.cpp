//Created by $HeXinGen on 2018/11/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
   vector<int> ver_int{3,1,5,6,4,2};
    // STL的sort函数排序吗，利用Lambda表达式传递匿名函数
   sort( ver_int.begin(),ver_int.end(),[](int a,int b)-> bool{ return a<b;});
     int size=ver_int.size();
    for (int i=0;i<size;i++) {
        int it=ver_int.at(i);
        if (i==0){
            cout<<"通过sort()进行排序，{"<<it;
        }else if (i==(size-1)){
            cout<<","<<it<<"}"<<endl;
        }else{
            cout<<","<<it;
        }
    }
    return 0;
}