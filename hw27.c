#include <stdio.h>
#include <stdlib.h>

typedef struct task_s {
    int days;
    int nextN;
    int next[10];
} task_t;

typedef struct stack_s {
    int current;
    int curr_acc_day;
} stack_t;

void dfs (task_t task[], int final) {
    stack_t stack[100];
    int i, top=-1 ,current, curr_acc_day, nextIndex, finalDay[100], fIndex=0, fmax=-999;
    int flag=0;
    top++;
    stack[top].current = 0;
    stack[top].curr_acc_day = task[0].days;
    while (1) {
        current = stack[top].current;
        curr_acc_day = stack[top].curr_acc_day;
        top--;
        if (current == final)  flag=1;
        // printf("%d %d:\n", current, curr_acc_day);
        if (task[current].nextN == 0) {
            finalDay[fIndex] = curr_acc_day;
            fIndex++;
            if (current + 1 <= final && flag == 0) {
                top++;
                stack[top].current = current + 1;
                stack[top].curr_acc_day = task[current+1].days;
                // printf("stack:%d, %d\n", stack[top].current, stack[top].curr_acc_day);
            }
            if (top < 0)  break;
            continue;
        }
        for (i=0; i<task[current].nextN; i++) {
            nextIndex = task[current].next[i] - 1;
            top++;
            stack[top].current = nextIndex;
            stack[top].curr_acc_day = task[nextIndex].days + curr_acc_day;
            // printf("stack:%d, %d\n", stack[top].current, stack[top].curr_acc_day);
        }
        if (top == -1)  break;
    }
    for (i=0; i<fIndex; i++) {
        if (finalDay[i] > fmax)  fmax = finalDay[i];
    }
    printf("%d\n", fmax);
}

void process () {
    task_t task[100];
    int i, j, taskN;
    scanf("%d", &taskN);
    for (i=0; i<taskN; i++) {
        scanf("%d", &task[i].days);
        scanf("%d", &task[i].nextN);
        for (j=0; j<task[i].nextN; j++) {
            scanf("%d", &task[i].next[j]);
        }
    }
    dfs(task, taskN-1);
}

int main () {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        process();
    }

    return 0;
}
