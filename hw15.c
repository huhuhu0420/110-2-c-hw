#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int getStartIndex(int *num, int maxLen){
    int i = maxLen-1, start = 0;
    while(i > 0){
        if(num[i] != 0){
            start = i;
            break;
        }
        i--;
    }

    return start;
}

void printAns(int *ans){
    int i=0, start=0;
    
    start = getStartIndex(ans, 82);
    if(start == 0){
        printf("%d", ans[0]);
        return;
    }
    for(i=start; i>=0; i--){
        printf("%d", ans[i]);
    }
}


void addNum(int *num1, int *num2, int *ans, int maxLen){
    int i=0, carry=0, temp=0;
    for(i=0; i<=maxLen; i++){
        temp = num1[i] + num2[i] + carry;
        ans[i] = temp % 10;
        carry = temp /10;
    }
    if(carry != 0){
        ans[i] = carry;
    }
}

void swapNum(int *num1, int *num2){
    int i, *temp = calloc(40, sizeof(int));
    for(i=0; i<41; i++){
        temp[i] = num1[i];
        num1[i] = num2[i];
        num2[i] = temp[i];
    }
}

void subNum(int *num1, int *num2, int *ans){
    int i=0; 
    for(i=0; i<41; i++){
        if(num1[i] >= num2[i]){
            ans[i] = num1[i] - num2[i];
        }
        else{
            num1[i] += 10;
            num1[i+1] -= 1;
            ans[i] = num1[i] - num2[i];
        }
    }
}

void single_mulNum(int *num1, int n, int *temp){
    int i, carry=0;
    for(i=0; i<41; i++){
        temp[i] = (num1[i] * n + carry) % 10;
        carry = (num1[i] * n + carry) / 10;
    }
    if(carry != 0){
        temp[i] = carry;
    }
}

void shiftRight(int *temp, int n){
    int i, start = getStartIndex(temp, 41);
    for(i=start; i>=0; i--){
        temp[i+n] = temp[i];
    }
    for(i=0; i<n; i++){
        temp[i] = 0;
    }
}

void mulNum(int *num1, int *num2, int *ans){
    int i ,start2 = getStartIndex(num2, 40);
    int *temp1 = calloc(82, sizeof(int));
    for(i=0; i<=start2; i++){
        temp1 = calloc(82, sizeof(int));
        single_mulNum(num1, num2[i], temp1);
        //printAns(temp1);
        //printf(" = temp1\n"); 
        shiftRight(temp1, i);
        //printAns(temp1);
        //printf(" = temp1\n");
        addNum(ans, temp1, ans, 82);
        //printAns(ans);
        //printf(" = ans\n");
        free(temp1);
    }
}

void transInt(char *cnum1, int *num1, int len){
    int i;
    for(i=len-1; i>=0; i--){
        num1[i] = cnum1[len-i-1] - '0';
    }
}


int isSmallerThan(int *num1, int *num2){
    int i;
    for(i=39; i>=0; i--){
        if(num1[i] < num2[i]){
            return 1;            
        }
        else if(num1[i] > num2[i]){
            return 0;
        }
    }
    return 0;
}

void test01(){
    int num1[40]={0}, num2[40]={0}, ans[82]={0};
    int len1=0, len2=0, flag=0;
    char cnum1[41], cnum2[41];

    scanf("%d", &flag);
    scanf("%s", cnum1);
    scanf("%s", cnum2);
    len1 = strlen(cnum1);
    len2 = strlen(cnum2);
    transInt(cnum1, num1, len1);
    transInt(cnum2, num2, len2);

    if(flag == 1)  addNum(num1, num2, ans, 40);
    else if(flag == 2){
        if(isSmallerThan(num1, num2) == 1){
            swapNum(num1, num2);
            printf("-");
        } 
        subNum(num1, num2, ans);
    }
    else if(flag == 3){
        mulNum(num1, num2, ans);
    }

    printAns(ans);
    printf("\n");
}

int main(){
    test01();
    return 0;
}
