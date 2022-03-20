#include <stdio.h>
#include <stdlib.h>

void transGray(int num, int len, int *grayCode){
    int now, last, i = len - 1;
    while(num != 0 && num != 1){
        now = num & 1;
        num = num >> 1;
        last = num & 1;
        grayCode[i] = now ^ last;
        i--;
    }
    grayCode[i] = num;
}

void getGrayCode(int len, int num){
    int *grayCode = calloc(len, sizeof(int));
    int i;
    transGray(num, len, grayCode);
    for(i=0; i<len; i++){
        printf("%d", grayCode[i]);
    }
    free(grayCode);
}

int main(){
    int len, num, flag=0;
    while(flag != -1){
        scanf("%d %d", &len, &num);
        scanf("%d", &flag);
        getGrayCode(len, num);
        if(flag != -1)  printf("\n");
    }

    return 0;
}
