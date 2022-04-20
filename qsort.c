#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp (const void *a, const void *b) {
    return *(int*)b - *(int*)a;
}

int main () {
    int data[10] = {9,10,2,4,24,245,7,0,12,4};
    qsort(data, 10, sizeof(int), cmp);
    for (int i=0; i<10; i++) {
        printf("%d, ", data[i]);
    }

    return 0;
}
