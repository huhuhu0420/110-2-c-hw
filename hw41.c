#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void initRec (int d[][10], int rec[][1<<10]) {
    int i, j;
    for (i=0; i<10; i++) {
        for (j=0; j<(1<<10); j++) {
            rec[i][j] = -1;
        }
    }
    for (i=0; i<10; i++) {
        for (j=0; j<4; j++) {
            rec[i][1<<j] = d[i][j];
        }
    }
}

int getRec (int d[][10], int rec[][1<<10], int start, int set, int n, int initial_start) {
    int dis = 0, minDis = 999999, i, temp;
    if (rec[start][set] >= 0) {
        for (i=0; i<n; i++) {
            if (((set>>i) & 1) == 1)  break;
        }
        return rec[start][set] + d[i][initial_start];
    }
    for (i=0; i<n; i++) {
        if (((set >> i) & 1) == 1) {
            temp = ~(1<<i);
            dis = d[start][i] + getRec(d, rec, i, set&temp, n, initial_start);
            if (dis < minDis)  minDis = dis;
        }
    }

    return minDis;
}

int main () {
    int n, d[10][10], rec[10][1<<10], dis, minDis = 999999;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &d[i][j]);
        }
    }
    initRec(d, rec);
    for (int start=0; start<n; start++) {
        int set = ((int)(pow(2, n))-1)^(1<<start);
        // printf("%d\n", set);
        dis = getRec(d, rec, start, set, n, start);
        if (dis < minDis)  minDis = dis;
    }
    printf("%d", dis);

    return 0;
}
