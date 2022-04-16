#include <stdio.h>
#include <string.h>

void transInt (char *cnum, int *num, int *neg) {
    int i=0, j=0; 
    int integer[40]={0}, index=0;
    if (cnum[0] == '-') {
        *neg = -1;
        i = 1;
    }
    for (; i<strlen(cnum); i++) {
        if (cnum[i] == '.')  break;
        integer[index] = cnum[i] - '0';
        index ++;
    }
    for (j=39; j>=1; j--) {
        num[j] = integer[--index];
        if (index == 0)  break;
    }
    index = 40;
    i += 1;
    for (; i<strlen(cnum); i++) {
        num[index++] = cnum[i] - '0';
    }
}

int getIndex_f (int *num) {
    int i;
    for (i=0; i<40; i++) {
        if (num[i] != 0)  return i;
    }
    return i;
}

int getIndex_b (int *num) {
    int i;
    for (i=79; i>=40; i--) {
        if (num[i] != 0)  return i;
    }
    return i;
}

void printBig (int *num, int neg) {
    int front, back, i;
    front = getIndex_f(num);
    back = getIndex_b(num);
    if (neg == -1) {
        printf("-");
    }
    if (front == 40 && back == 39) {
        printf("0");
        return;
    }
    for (i=front; i<=39; i++) {
        printf("%d", num[i]);
    }
    printf(".");
    for (i=40; i<=back; i++) {
        printf("%d", num[i]);
    }
}

void add (int *num1, int *num2, int *ans) {
    int carry=0, temp=0;
    for (int i=79; i>=0; i--) {
        temp = num1[i] + num2[i] + carry;
        ans[i] = temp % 10;
        carry = temp / 10;
    }
}

void sub (int *num1, int *num2, int *ans) {
    int num1_cpy[80]={0};
    for (int i=0; i<80; i++) {
        num1_cpy[i] = num1[i];
    }
    for (int i=79; i>=0; i--) {
        if (num1_cpy[i] >= num2[i]) {
            ans[i] = num1_cpy[i] - num2[i];
        }
        else {
            ans[i] = 10 + num1_cpy[i] - num2[i];
            num1_cpy[i-1] -= 1;
        }
    } 
}

int getBigger (int *num1, int *num2) {
    int front1, front2, i;
    front1 = getIndex_f(num1);
    front2 = getIndex_f(num2);
    if (front1 != front2) {
        return front1 < front2 ? 1:2;
    }
    else if (front1 == front2) {
        for (i=front1; i<80; i++) {
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
}

int main () {
    char cnum1[82], cnum2[82]; 
    int num1[80]={0}, num2[80]={0}, neg1=1, neg2=1;
    int add_ans[80]={0}, sub_ans[80]={0}, mul_ans[160]={0};
    memset(cnum1, 82, '0');
    memset(cnum2, 82, '0');

    scanf("%s", cnum1);
    scanf("%s", cnum2);

    transInt(cnum1, num1, &neg1);
    transInt(cnum2, num2, &neg2);

    printBig(num1, neg1);
    printf("\n");
    printBig(num2, neg2);
    printf("\n");

    add_process(num1, num2, neg1, neg2, add_ans);
    printf("\n---add---\n");
    
    printBig(num1, neg1);
    printf("\n");
    printBig(num2, neg2);
    printf("\n");
    
    sub_process(num1, num2, neg1, neg2, sub_ans);
    printf("\n---sub---\n");

    return 0;
}
