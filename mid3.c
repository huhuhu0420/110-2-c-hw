#include <stdio.h>
#include <string.h>

void transInt (char *cnum, int *num, int *neg) {
    int i=0, j=0, decimal[40]={0}, integer[40]={0}, index=0;

    if (cnum[0] == '-') {
        *neg = -1;
        i = 1;
    }
    for (; i<strlen(cnum); i++) {
        if (cnum[i] == '.')  break;
        integer[index++] = cnum[i] - '0';
    }
    for (j=39; j>=1; j--) {
        num[j] = integer[--index];
    }
    index = 40;
    i += 1;
    for (; i<strlen(cnum); i++) {
        num[index++] = cnum[i] - '0';
    }
}

int main () {
    char cnum1[82], cnum2[82]; 
    int num1[80]={0}, num2[80]={0}, neg1=1, neg2=1;
    memset(cnum1, 82, '0');
    memset(cnum2, 82, '0');

    scanf("%s", cnum1);
    scanf("%s", cnum2);
    
    transInt(cnum1, num1, &neg1);
    transInt(cnum2, num2, &neg2);
    for (int i=0; i<40; i++){
        printf("%d", num1[i]);
    }
    printf(".");
    for (int i=40; i<80; i++){
        printf("%d", num1[i]);
    }

    return 0;
}
