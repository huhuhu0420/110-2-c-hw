#include <stdio.h>
#include <stdlib.h>

typedef struct data_s {
    int len;
    int num[100];
} data_t;

int cmp (const void *a, const void *b) {
    int temp = 0;
    for (int i=0; i<(*(data_t*)a).len; i++) {
        temp = (*(data_t*)a).num[i] - (*(data_t*)b).num[i];
        if (temp != 0)  return temp;
    }
    return temp;
}

int main () {
    data_t data[100];
    int n, m, i, j;
    scanf("%d %d", &n, &m);
    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            data[i].len = m;
            scanf("%d", &data[i].num[j]);
        }
    }
    qsort(data, n, sizeof(data_t), cmp);
    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            printf("%d ", data[i].num[j]);
        }
        printf("\n");
    }

    return 0;
}
