#include <stdio.h>
#include <string.h>
#define max 65536

int main () {
    int flag[max]={0}, i=0, guessN=0, ans=0;
    int a=0, b=0;
    char now[4], guess[5];

    while (1) {
        guessN = 0;
        scanf("%4s,%dA%dB", now, &a, &b);
        for (i=0; i<max; i++) {
            if (flag[i] == 1)  continue;
            sprintf(guess, "%04X", i);
            // printf("%s\n", guess);
            int na=0, nb=0, j=0, k=0;
            for (j=0; j<4; j++) {
                for (k=j; k<4; k++) {
                    if (guess[j] == guess[k] && j != k) {
                        flag[i] = 1;
                    }
                }
            }
            for (j=0; j<4; j++) {
                for (k=0; k<4; k++) {
                    if (guess[j] == now[k]) {
                        if (j == k)  na++;
                        else nb++;
                    }
                }
            }
            if (na != a || nb != b) {
                flag[i] = 1;
                continue;
            }
            guessN++;
            ans=i;
        }
        if (guessN == 1) {
            printf("%04X", ans);
            break;
        }
    }

    return 0;
}
