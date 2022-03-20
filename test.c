#include <stdio.h>
#include <stdarg.h>

void foo(int len, ...){
    va_list args;
    va_start(args, len);
    //int i=0;
    //for(i=0; i<len; i++){
    //    printf("%f\n", va_arg(args, double));
    //}
    printf("%f\n", va_arg(args, double));
    printf("%f\n", va_arg(args, double));
    
    va_end(args);
}

int oddSum(int x, int y){
    int sum = 0;
    for(int i=x; i<=y; i++){
        if(i%2==1){
            sum += i;
        }
    }
    return sum;
}

void test02(){
    int x=1, y=100;
    printf("%d\n", oddSum(x, y));
}

void test01(){
    double x=1.1, y=3.2, z=1;
    foo(2, x, y, z);
}

void test03(){
    int x=4, y=3;
    double d;
    d = x / y;
    printf("%lf\n", d);
}

int main(){
    test03();
}
