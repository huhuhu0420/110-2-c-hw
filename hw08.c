#include <stdio.h>

void printSign(int n, char sign){
    int i;
    for(i=0; i<n; i++){
        printf("%c", sign);
    }
}

void typeThree(int line){
    int i;
    for(i=line/2; i>=1; i--){
        printSign(i, '.');
        printSign(((line/2)+1-i)*2-1, '*');
        printf("\n");
    }
    for(i=0; i<(line/2)+1; i++){
        printSign(i, '.');
        printSign(((line/2)+1-i)*2-1 ,'*');
        printf("\n");
    }
   
}

void typeTwo(int line){
    int i;
    for(i=line/2; i>=1; i--){
        printSign(i, '.');
        printSign((line/2)+1-i, '*');
        printf("\n");
    }
    for(i=0; i<(line/2)+1; i++){
        printSign(i, '.');
        printSign((line/2)+1-i ,'*');
        printf("\n");
    }
}

void typeOne(int line){
    int i;
    for(i=0; i<(line/2)+1; i++){
        printSign(i+1, '*');
        printf("\n");
    }
    for(i=line/2; i>=1; i--){
        printSign(i, '*');
        printf("\n");
    }
}

int main(){
    int type, line;
    scanf("%d", &type);
    scanf("%d", &line);
    if(type == 1){
        typeOne(line);
    }
    else if(type == 2){
        typeTwo(line);
    }
    if(type == 3){
        typeThree(line);
    }

    return 0;
}
