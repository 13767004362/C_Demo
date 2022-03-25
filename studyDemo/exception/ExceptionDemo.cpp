/**
 * @author ： HeXinGen
 * @date ： 2021/8/26
 * @description ：
 */

#include "ExceptionDemo.h"
#include <iostream>
using  namespace  std;


int  testCalculationException(int  a,int divider);

int main(){
    try {
     testCalculationException(100,0);
    } catch (CalculationException e) {
      cout<< e.what()<<endl;
    }
    catch (exception& e1) {
      //捕捉全部异常
    }
    return 0;
}

int  testCalculationException(int  a,int divider ) {
   if (divider==0){
       throw  CalculationException(" divider must no is zero");
   }
    return a/divider;
}

