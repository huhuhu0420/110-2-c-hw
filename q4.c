#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 65536
int main()
{
    int arr[maxn + 5];
    memset(arr, 0, sizeof(arr));
    int a, b, ans;
    while (1) {
        char s[20];
        memset(s, 0, sizeof(s));
        gets(s);
        char now[4];
        memset(now, 0, sizeof(now));
        char ck;
        int tot = 0;
        sscanf(s, "%4s%c%d%c%d%c%c", now, &ck, &a, &ck, &b, &ck, &ck);
        for (int i = 0; i < maxn; i++) {
            if (arr[i] == 1)
                continue;
            char fa[4];
            memset(fa, 0, sizeof(fa));
            sprintf(fa, "%4X", i);
            // printf("%s\n", fa);
            int flag = 0;
            for (int j = 0; j < 4; j++) {
                for (int k = j + 1; k < 4; k++) {
                    if (fa[j] == fa[k]) {
                        flag = 1;
                    }
                }
            }
            if (flag) {
                arr[i] = 1;
                continue;
            }
            int na = 0, nb = 0;
            for (int j = 0; j < 4; j++) {
                if (now[j] == fa[j])
                    na++;
                for (int k = 0; k < 4; k++) {
                    if (j != k && now[j] == fa[k])
                        nb++;
                }
            }
            if (na != a || nb != b) {
                arr[i] = 1;
                continue;
            }
            ans = i;
            tot += 1;
        }
        if (tot == 1) {
            printf("%04X\n", ans);
            break;
        }
    }
    return 0;
}
