#include <stdio.h>

typedef struct stack_s {
    int place;
    int path;
    int dis;
} stack_t;

void process (int d[][10], int n, int start) {
    int top = 0, dis, mindis = 99999, i;
    stack_t stack[100], current;
    stack[top].place = start;
    stack[top].path = 1 << start;
    stack[top].dis = 0;
    while (1) {
        current = stack[top];
        top--;
        for (i=0; i<n; i++) {
            if (((current.path >> i) & 1) == 0) {
                top++;
                stack[top].place = i;
                stack[top].path = current.path | (1 << i);
                stack[top].dis = current.dis + d[current.place][i];
            }
        }
        if (current.path == ((1 << n) - 1)) {
            dis = current.dis + d[current.place][start];
            if (dis < mindis)  mindis = dis;
        }
        if (top < 0)  break;
    }
    printf("%d\n", mindis);
}

int main () {
    int d[10][10], n, i, j;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            scanf("%d", &d[i][j]);
            getchar();
        }
    }
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            printf("%d", d[i][j]);
        }
        printf("\n");
    }
    process(d, n, 0);

    return 0;
}
