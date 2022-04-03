#include <stdio.h>

int search(int d[], int size, int key) {
    int i=0;
    int front = 0, back = size - 1, mid = (front + back) / 2;

    while(1){
        mid = (front + back) /2;
        if(front == back){
            return -1;
        }
        if(d[mid] == key){
            return mid;
        }
        else if(d[mid] < key){
            front = mid;
        }
        else if(d[mid] > key){
            back = mid;
        }
    }

    return -1;
}

int main() {
    int data[]={5,12,18,21,27,29,34,43,46};
    printf("---\n");
    printf("%d, %d\n", search(data, 21, 1), 1);
    return 0;
}
