#include <stdio.h>

int f(int n, int *data){
    if(data[n] > 0){
        return data[n];
    } 
    else{
        data[n] = f(n-1, data) + f(n-2, data);
        return data[n];
    }
}

int main(){
    int n, i;
    int data[11] = {0};
    data[1] = 1;
    data[2] = 1;
    scanf("%d", &n);
    f(n, data);
    for(i=0; i<11; i++){
        printf("%d, ", data[i]);
    }

    return 0;
}
