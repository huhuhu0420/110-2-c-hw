#include <stdio.h>

typedef struct stack_s {
    int place;
    int set;
    int dis;
} stack_t;

int dfs (int d[][10], int n, int start) {
    int top = -1, i, dis, mindis = 999999;
    stack_t stack[100], current;
    top++;
    stack[top].place = start;
    stack[top].set = 1 << start;
    stack[top].dis = 0;
    while (1) {
        current = stack[top--];
        for (i=0; i<n; i++) {
            if (((current.set >> i) & 1) == 0) {
                top++;
                stack[top].place = i;
                stack[top].set = current.set | (1 << i);
                stack[top].dis = current.dis + d[current.place][i];
            }
        }
        if (current.set == (1 << n) - 1) {
            dis = current.dis + d[current.place][start];
            if (dis < mindis)  mindis = dis;
        }
        if (top < 0)  break;
    }
    return mindis;
}

int main () {
    int n, d[10][10], dis;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &d[i][j]);
        }
    }
    dis = dfs(d, n, 0);
    printf("%d", dis);

    return 0;
}
