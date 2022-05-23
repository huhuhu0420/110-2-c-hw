#include <stdio.h>
#define SIZE 3

int eval_f (int *iptr[], int n, int *index) {
    int i, outcome=0, max=-1;
    for (i=0; i<SIZE; i++) {
        printf("%d %d\n", (*iptr[i]), *(iptr[i]+1));
        outcome = (4 * iptr[i][0]) - (6 * iptr[i][1]);
        printf("out = %d\n", outcome);
        if (outcome >= max) {
            max = outcome;
            (*index) = i;
        }
    }
    return max;
}

int main () {
    int data[SIZE][2] = {
        {2,1}, {3,3}, {8,5}
    }, index=0;
    int *iptr[SIZE];
    for (int i=0; i<SIZE; i++) {
        iptr[i] = data[i];
    }
    printf("%d ", eval_f(iptr, SIZE, &index));
    printf("%d", index);

    return 0;
}
