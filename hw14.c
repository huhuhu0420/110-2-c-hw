#include <stdio.h>

int isA(char *ans, char *guess, int index){
    if(ans[index] == guess[index])  return 1;
    return 0;
}

int isB(char *ans, char *guess, int index){
    int i;
    for(i=0; i<4; i++){
        if(guess[index] == ans[i] && index != i)  return 1;
    }
    return 0;
}

void getABcount(char *ans, char*guess, int *countA, int *countB){
    int i;
    for(i=0; i<4; i++){
        if(isA(ans, guess, i) == 1)  (*countA)++;
        else if(isB(ans, guess, i) == 1)  (*countB)++;
    }
}

int main(){
    char ans[5], guess[5];
    int i=0, countA=0, countB=0;
    
    scanf("%s", ans);
    getchar();
    while(i < 6){
        countA = 0;
        countB = 0;
        scanf("%s", guess);
        getchar();
        getABcount(ans, guess, &countA, &countB);
        if(countA == 4){
            printf("win");
            break;
        }
        printf("%dA%dB", countA, countB);
        if(i != 5)  printf("\n");
        i++;
    } 

    return 0;
}
