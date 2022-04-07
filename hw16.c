#include <stdio.h>
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

void printBig(int *ans, int len){
    int i=0, start=0;
    
    start = getStartIndex(ans, len);
    if(start == 0){
        printf("%d", ans[0]);
        return;
    }
    for(i=start; i>=0; i--){
        printf("%d", ans[i]);
    }
}

int isSmallerThan(int *num1, int *num2){
    int i;
    for(i=40; i>=0; i--){
        if(num1[i] < num2[i]){
            return 1;            
        }
        else if(num1[i] > num2[i]){
            return 0;
        }
    }
    return 1;
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

void shiftRight(int *temp, int n){
    int i, start = getStartIndex(temp, 41);
    for(i=start; i>=0; i--){
        temp[i+n] = temp[i];
    }
    for(i=0; i<n; i++){
        temp[i] = 0;
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

int getSingleNum(int *num1, int *num2, int len){
    int i, temp[41] = {0}, tempNext[41] = {0};
    for(i=0; i<=9; i++){
        single_mulNum(temp, 0, temp);
        single_mulNum(tempNext, 0, temp);

        single_mulNum(num2, i, temp);
        shiftRight(temp, len);
        if(isSmallerThan(temp, num1) == 1){
            single_mulNum(num2, i+1, tempNext);
            shiftRight(tempNext, len);
            if(isSmallerThan(tempNext, num1) == 0){
                return i;
            }
        }
        else{
            return 0;
        }
    }
    return 0;
}

void divideNum(int *num1, int *num2, int *ans){
    int singleNum, start1, start2, len;
    int temp[41]={0};
    start1 = getStartIndex(num1, 41);
    start2 = getStartIndex(num2, 41);

    for(len=start1-start2; len>=0; len--){
        singleNum = getSingleNum(num1, num2, len);
        shiftRight(ans, 1);
        ans[0] = singleNum;
        if(singleNum != 0){
            single_mulNum(num2, singleNum, temp);
            shiftRight(temp, len);
            subNum(num1, temp, num1);
        }
    }
}

void transInt(char *cnum, int *num, int len){
    int i;
    for(i=len-1; i>=0; i--){
        num[i] = cnum[len-i-1] - '0';
    }
}

int main(){
    int num1[41]={0}, num2[41]={0}, ans[41]={0}, len1, len2;
    char cnum1[41], cnum2[41];
    scanf("%s", cnum1);
    scanf("%s", cnum2);
    len1 = strlen(cnum1);
    len2 = strlen(cnum2);
    transInt(cnum1, num1, len1);
    transInt(cnum2, num2, len2);
    divideNum(num1, num2, ans);
    printBig(ans, 41);

    return 0;
}
