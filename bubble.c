#include <stdio.h>

void bubble (int *data, int size) {
    int tmp=0;
    for (int i=0; i<size; i++) {
        for (int j=0; j<size-1-i; j++) {
            if (data[j] > data[j+1]) {
                tmp = data[j];
                data[j] = data[j+1];
                data[j+1] = tmp;
            }
        }
    }
}

int main () {
    int data[10] = {10,2,1,4,9,212,4,2,5,134};
    bubble(data, 10);
    for (int i=0; i<10; i++) {
        printf("%d, ", data[i]);
    }

    return 0;
}
