#include <stdio.h>
#include <string.h>
int main()
{
    int info[10][3]; // 0 score, 1 strike
    int sk[10][200], ask;
    memset(sk, 0, sizeof(sk));
    memset(info, 0, sizeof(info));
    char s[20];
    for (int i = 1; i <= 9; i++) {
        gets(s);
        int k = 1;
        for (int j = 2; j < strlen(s); j++) {
            if (s[j] != ' ') {
                sk[i][k++] = (s[j] == 'H' ? 4 : (s[j] == 'O' ? 0 : s[j] - '0'));
            }
        }
    }
    scanf("%d", &ask);
    int base[5], out = 0, tot = 0, tot_out = 0;
    memset(base, 0, sizeof(base));
    while (1) {
        int player = tot % 9 + 1;
        int times = tot / 9 + 1;
        int stk = sk[player][times];
        if (stk)
            info[player][1] += 1;
        if (stk == 0) {
            tot_out++;
            out++;
        } else if (stk == 1) {
            info[base[3]][0]++;
            for (int i = 3; i >= 2; i--) {
                base[i] = base[i - 1];
            }
            base[1] = player;
        } else if (stk == 2) {
            info[base[3]][0]++;
            info[base[2]][0]++;
            base[3] = base[1];
            base[1] = 0;
            base[2] = player;
        } else if (stk == 3) {
            info[base[3]][0]++;
            info[base[2]][0]++;
            info[base[1]][0]++;
            base[2] = base[1] = 0;
            base[3] = player;
        } else if (stk == 4) {
            info[base[3]][0]++;
            info[base[2]][0]++;
            info[base[1]][0]++;
            info[player][0]++;
            base[3] = base[2] = base[1] = 0;
        }
        if (tot_out == ask) {
            int ans = 0;
            for (int i = 1; i <= 9; i++) {
                ans += info[i][0];
            }
            printf("%d\n", ans);
            for (int i = 1; i <= 3; i++) {
                printf("%d %d %d\n", i, info[i][1], info[i][0]);
            }
            break;
        }
        if (out == 3) {
            out = 0;
            base[1] = base[2] = base[3] = 0;
        }

        tot += 1;
    }
    return 0;
}