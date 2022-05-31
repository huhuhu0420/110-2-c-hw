#include <stdio.h>

struct data_s {
    unsigned int a: 1;
    unsigned int b: 2;
} ;

int main () {
    int k=14;
    printf("%d\n", sizeof(k));
    printf("%d\n", sizeof(struct data_s));
    return 0;
}
