#include <stdio.h>
#include <string.h>
#define MAX 100

void transInt(char cnum1[MAX], int num1[MAX], int len){
    int i;
    for(i=len-1; i>=0; i--){
        num1[i] = cnum1[len-i-1] - '0';
    }
}

void printAns (int ans[MAX]) {
    int flag = 0;
    for (int i=MAX-1; i>=0; i--) {
        if (ans[i] != 0)  flag = 1;  // 陣列後面沒有用到的地方都是 0, 
                                    // 判斷直到不是 0 的時候才開始印
        if (flag == 1) {
            printf("%d", ans[i]);
        }
    }
}

int main () {
    int flag = 1;
    while (flag == 1) {
        int num1[MAX]={0}, num2[MAX]={0}, ans[MAX]={0};
        int len1=0, len2=0, carry=0;
        char cnum1[MAX], cnum2[MAX], instuction;

        scanf("%s", cnum1);
        scanf("%s", cnum2);
        len1 = strlen(cnum1);
        len2 = strlen(cnum2);
        transInt(cnum1, num1, len1);
        transInt(cnum2, num2, len2);
        getchar();  // 吸收換行符號
        scanf("%c", &instuction);  // '+' or '-'

        // calculate add
        if (instuction == '+') {
            for (int i=0; i<MAX; i++) {
                ans[i] = num1[i] + num2[i] + carry;
                carry = ans[i] / 10;
                ans[i] = ans[i] % 10; 
            }
            if (carry > 0)  printf("overflow\n");
            // 當到最後一位（最大位）相加還是有進位,表示數字超過所能容納的長度
            else  printAns(ans);
        }

        // calculate minus
        else if (instuction == '-') {
            for(int i=0; i<MAX; i++){
                if(num1[i] >= num2[i]){
                    ans[i] = num1[i] - num2[i];
                }
                else{
                    num1[i] += 10;
                    num1[i+1] -= 1;
                    ans[i] = num1[i] - num2[i];
                }
            }
            printAns(ans);
            printf("\n");
        }
        
        scanf("%d", &flag);  // whether need next calculate
    }

    return 0; 
}
