#include <stdio.h>
#include <string.h>

int biTransDec(char *binary){
    int i=0, temp=1, decCode=0, l=strlen(binary);
    for(i=l-1; i>=0; i--){
        decCode += (binary[i] - '0') * temp;
        temp *= 2;
    }

    return decCode;
}

int decTransSeven(int decCode){
    int sevenCode=0, temp=1;
    while(decCode != 0){
        sevenCode += (decCode % 7) *temp;
        temp *= 10;
        decCode /= 7;
    }
    return sevenCode;
}

int isError(char *binary){
    int i, l=strlen(binary);
    for(i=0; i<l; i++){
        //printf("%c\n", binary[i]);
        if(binary[i] != '0' && binary[i] != '1'){
            return 1;
        }
    }
    return 0;
}

int main(){
    char binary[16];
    int decCode=0, sevenCode=0;

    scanf("%s", binary);
    //printf("%s\n", binary);
    decCode = biTransDec(binary);
    // printf("%d\n", decCode);
    if(isError(binary) == 1){
        printf("ERROR");
        return 0;
    }
    sevenCode = decTransSeven(decCode);
    printf("%d\n", sevenCode);

    return 0;
}
