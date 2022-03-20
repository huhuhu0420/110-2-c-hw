#include <stdio.h>
#include <stdlib.h>

void f(){
    const char* str1 = "test";
    const char* str2 = "test";
    printf("%d %p\n", str1, str2);
    printf("%c\n", *(str1+1));    
}

void test01(){
    int *num = (int*)malloc(sizeof(int)*5);
    if(num == NULL)  printf("-----\n");
}

int main(){
    char* str = "test";
    void *ptr;
    float a = 100.0;
    ptr = &a;
    printf("%f\n", *(float*)ptr);
    f();
    printf("%d\n", str);
    return 0;
}
