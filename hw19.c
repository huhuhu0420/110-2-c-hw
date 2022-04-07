#include <stdio.h>

void process (int n, int *now, char *data, int offset_x, int offset_y, int *ans, int ori_n) {
    if (data[*now] == '2') {
        (*now)++;
        process(n/2, now, data, offset_x, offset_y, ans, ori_n);
        (*now)++;
        process(n/2, now, data, offset_x + (n / 2), offset_y, ans, ori_n);
        (*now)++;
        process(n/2, now, data, offset_x, offset_y + (n / 2), ans, ori_n);
        (*now)++;
        process(n/2, now, data, offset_x + (n / 2), offset_y + (n / 2), ans, ori_n);
    }
    else if (data[*now] == '1') {
        int i, j;
        for (i=offset_y; i<offset_y+n; i++) {
            for (j=offset_x; j<offset_x+n; j++) {
                ans[i * ori_n + j] = 1;
            }
        }
    }
    return;
} 

int main () {
    char data[102];
    int i, n, ans[1000] = {0}, now = 0, flag = 0;

    scanf("%s", data);
    scanf("%d", &n);

    process(n, &now, data, 0, 0, ans, n);

    for (i=0; i<1000; i++) {
        if (ans[i] == 1) {
            flag = 1;
            printf("%d,%d\n", i/n, i%n);
        }
    }
    if (flag == 0) {
        printf("all white");
    }

    return 0;
}
