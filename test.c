#include <stdio.h>

void f1(int **pp, int **qq, int a[], int *p){
    int **rr = qq;
    a[0] = (**rr) + (*(a+2));
    printf("%d\n", a[0]);
    *pp = p + 1;
    *rr = *pp + 1;
    printf("%d\n", *(*rr + 2));
    *(a+1) = (**pp) + a[*p + 2];
    printf("%d\n", a[1]);
    *qq = p;
    *((*qq) + 1) = (**rr) + (**pp);
    printf("%d\n", **qq);
}

void test10(){
    int a[] = {0,1,2,3,4,5,6};
    int *p = a, *q = a + 2;
    int **pp = &p;
    f1(pp, &q, a+2, p);
    printf("%d\n", a[1]);
    printf("%d\n", a[3]);
}

void test06(){
    int i=1, sum=0, a[]={6,7,8,7,6,5,4,3,2,1,0};
    int *p=&i, *q=a+3;
    printf("%d, %d\n", (*p)++, *(++q));
    printf("%d, %d\n", *p, *q);
    for(sum=0, p=a+4; p>a; p--){
        sum += *(p+1);
    }
    printf("%d, %d\n", sum, *p);
    for(i=0; i<10; i++){
        a[i] = i;
    }
    p = q = a;
    i = *(p++);
    i += (*q)++;
    printf("%d, %d\n", a[0], a[3]);
}

void test01(){
    int a[4]={1,1,1,1}, *p=a;
    printf("%d\n", *p+2);
}

int main(){
    test10();

    return 0;
}
