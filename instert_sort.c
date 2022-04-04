#include <stdio.h>
#define size 7

void insertSort(int *data){
    int i, j, temp;
    for(i=1; i<size; i++){
        temp = data[i];
        j = i - 1;
        while(1){
            if(temp > data[j] || j<0){
                break;
            }
            data[j+1] = data[j];
            j -= 1;
        }
        data[j+1] = temp;
    }
}

int main(){
    int i, data[size] = {9,11,4,5,7,1,3};
    insertSort(data);
    for(i=0; i<size; i++){
        printf("%d,", data[i]);
    }

    return 0;
}