//Created by $HeXinGen on 2018/11/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
   vector<int> ver_int{3,1,5,6,4,2};
    // STL��sort��������������Lambda���ʽ������������
   sort( ver_int.begin(),ver_int.end(),[](int a,int b)-> bool{ return a<b;});
     int size=ver_int.size();
    for (int i=0;i<size;i++) {
        int it=ver_int.at(i);
        if (i==0){
            cout<<"ͨ��sort()��������{"<<it;
        }else if (i==(size-1)){
            cout<<","<<it<<"}"<<endl;
        }else{
            cout<<","<<it;
        }
    }
    return 0;
}