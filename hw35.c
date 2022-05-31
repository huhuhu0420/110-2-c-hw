#include <stdio.h>
#include <string.h>
#define SIZE 120

void transInt (char *cnum, int *num, int *neg) {
    int i=0, j=0; 
    int integer[SIZE/2]={0}, index=0;
    if (cnum[0] == '-') {
        *neg = -1;
        i = 1;
    }
    for (; i<strlen(cnum); i++) {
        if (cnum[i] == '.')  break;
        integer[index] = cnum[i] - '0';
        index ++;
    }
    for (j=SIZE/2-1; j>=1; j--) {
        num[j] = integer[--index];
        if (index == 0)  break;
    }
    index = SIZE/2;
    i += 1;
    for (; i<strlen(cnum); i++) {
        num[index++] = cnum[i] - '0';
    }
}

int getIndex_f (int *num) {
    int i;
    for (i=0; i<=SIZE/2-1; i++) {
        if (num[i] != 0)  return i;
    }
    return i;
}

int getIndex_b (int *num) {
    int i;
    for (i=SIZE-1; i>=SIZE/2; i--) {
        if (num[i] != 0)  return i;
    }
    return i;
}

void prinBig2 (int *num) {
    int flag=0;
    for (int i=0; i<SIZE*2; i++) {
        if (num[i] != 0)  flag = 1;
        if (flag == 1) printf("%d", num[i]);
    }
    printf("\n");
}

void printBig_mul (int *num, int neg, int point) {
    int flag=0, i=0, back;
    for (i=SIZE*2-1; i>=0; i--) {
        if (num[i] != 0){
            back = i;
            break;
        }
    }
    i = 0;
    if (neg == -1){
        printf("-");
        i=1;
    }
    for (; i<=back; i++) {
        if (num[i] != 0)  flag = 1;
        if (i == SIZE * 2 - point)  printf(".");
        if (flag == 1)  printf("%d", num[i]);
    }
}

void printBig (int *num, int neg) {
    int front, back, i;
    front = getIndex_f(num);
    back = getIndex_b(num);
    if (front == SIZE/2 && back == SIZE/2-1) {
        printf("0");
        return;
    }
    if (neg == -1) {
        printf("-");
    }
    for (i=front; i<SIZE/2; i++) {
        printf("%d", num[i]);
    }
    printf(".");
    for (i=SIZE/2; i<=back; i++) {
        printf("%d", num[i]);
    }
}

void add (int *num1, int *num2, int *ans) {
    int carry=0, temp=0;
    for (int i=SIZE-1; i>=0; i--) {
        temp = num1[i] + num2[i] + carry;
        ans[i] = temp % 10;
        carry = temp / 10;
    }
}

void add2 (int *num1, int *num2, int *ans) {
    int carry=0, temp=0;
    for (int i=2*SIZE-1; i>=0; i--) {
        temp = num1[i] + num2[i] + carry;
        ans[i] = temp % 10;
        carry = temp / 10;
    }
}

void sub (int *num1, int *num2, int *ans) {
    int num1_cpy[SIZE]={0};
    for (int i=0; i<SIZE; i++) {
        num1_cpy[i] = num1[i];
    }
    for (int i=SIZE-1; i>=0; i--) {
        if (num1_cpy[i] >= num2[i]) {
            ans[i] = num1_cpy[i] - num2[i];
        }
        else {
            ans[i] = 10 + num1_cpy[i] - num2[i];
            num1_cpy[i-1] -= 1;
        }
    } 
}

void shiftLeft (int *temp, int n) {
    int i;
    for(i=0; i<SIZE*2; i++){
        temp[i] = temp[i+n];
    }
    for(i=SIZE*2-1; i>=SIZE*2-n; i--){
        temp[i] = 0;
    }
}

void single_mul (int *num1, int n, int *temp) {
    int i, front, back, carry=0, index=SIZE*2-1;
    front = getIndex_f(num1);
    back = getIndex_b(num1);
    for (i=back; i>=front; i--) {
        temp[index--] = (num1[i] * n + carry) % 10;
        carry = (num1[i] * n + carry) / 10;
    }
    if (carry != 0) {
        temp[index] = carry;
    }
}

void mulNum(int *num1, int *num2, int neg1, int neg2, int *ans){
    int i,temp_ans[SIZE*2]={0}, front, back, sh=0, point;
    int negAns = neg1 * neg2;
    front = getIndex_f(num2);
    back = getIndex_b(num2);
    point = (getIndex_b(num1) - 60 + 1) + (getIndex_b(num2) - 60 + 1); 
    for (i=back; i>=front; i--) {
        int temp[SIZE*2] = {0};
        single_mul(num1, num2[i], temp);
        shiftLeft(temp, sh++);
        //prinBig2(temp);
        add2(temp, temp_ans, temp_ans);
    }
    printBig_mul(temp_ans, negAns, point);
    //prinBig2(temp_ans);
}

int getBigger (int *num1, int *num2) {
    int front1, front2, i;
    front1 = getIndex_f(num1);
    front2 = getIndex_f(num2);
    if (front1 != front2) {
        return front1 < front2 ? 1:2;
    }
    else if (front1 == front2) {
        for (i=front1; i<SIZE; i++) {
            if (num1[i] > num2[i])  return 1;
            else if (num1[i] < num2[i])  return 2;
        }
    }
    return 1;
}

void add_process (int *num1, int *num2, int neg1, int neg2, int *add_ans) {
    int negAns=1, bigger = getBigger(num1, num2);
    if (neg1 == 1 && neg2 == 1) {
        negAns = 1;
        add(num1, num2, add_ans);
    }
    else if (neg1 == -1 && neg2 == 1) {
        if (bigger == 1) {
            negAns = -1;
            sub(num1, num2, add_ans);
        }
        else if (bigger == 2) {
            negAns = 1;
            sub(num2, num1, add_ans);
        }
    }
    else if (neg1 == 1 && neg2 == -1) {
        if (bigger == 1) {
            negAns = 1;
            sub(num1, num2, add_ans);
        }
        else if (bigger == 2) {
            negAns = -1;
            sub(num2, num1, add_ans);
        }
    }
    else {
        negAns = -1;
        add(num1, num2, add_ans);
    }
    printBig(add_ans, negAns);
    printf("\n");
}

void sub_process (int *num1, int *num2, int neg1, int neg2, int *sub_ans) {
    int negAns=1, bigger = getBigger(num1, num2);
    if (neg1 == 1 && neg2 == 1) {
        if (bigger == 1) {
            negAns = 1;
            sub(num1, num2, sub_ans);
        }
        else if (bigger == 2) {
            negAns = -1;
            sub(num2, num1, sub_ans);

        }
    }
    else if (neg1 == -1 && neg2 == 1) {
        negAns = -1;
        add(num1, num2, sub_ans);
    }
    else if (neg1 == 1 && neg2 == -1) {
        negAns = 1;
        add(num1, num2, sub_ans);
    }
    else {
        if (bigger == 1) {
            negAns = -1;
            sub(num1, num2, sub_ans);
        }
        else if (bigger == 2) {
            negAns = 1;
            sub(num2, num1, sub_ans);
        }
    }
    printBig(sub_ans, negAns);
    printf("\n");
}

int main () {
    char cnum1[SIZE+2], cnum2[SIZE+2]; 
    int num1[SIZE]={0}, num2[SIZE]={0}, neg1=1, neg2=1;
    int add_ans[SIZE]={0}, sub_ans[SIZE]={0}, mul_ans[SIZE*2]={0};
    memset(cnum1, SIZE+2, '0');
    memset(cnum2, SIZE+2, '0');

    scanf("%s", cnum1);
    scanf("%s", cnum2);

    transInt(cnum1, num1, &neg1);
    transInt(cnum2, num2, &neg2);

    // printBig(num1, neg1);
    // printf("\n");
    // printBig(num2, neg2);
    // printf("\n");

    add_process(num1, num2, neg1, neg2, add_ans);
    
    // printBig(num1, neg1);
    // printf("\n");
    // printBig(num2, neg2);
    // printf("\n");
    
    sub_process(num1, num2, neg1, neg2, sub_ans);

    mulNum(num1, num2, neg1, neg2, mul_ans);

    return 0;
}
