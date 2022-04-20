#include <stdio.h>

int main () {
    int a[]={4,5,6,7,8};
    int *p = a + 1;
    int *q = a + 1;
    printf("%d\n", *(++p));
    printf("%d\n", *(q++));
    printf("%d\n", *p);
    printf("%d\n", *q);

    return 0;
}
