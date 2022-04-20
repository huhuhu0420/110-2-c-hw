#include <stdio.h>
#define size 65536

int main () {
    int a=0, b=0, ga=0, gb=0, flag[size]={0}, guessN=0, ans=0;
    char guess[5], now[5];
    while (1) {
        guessN = 0;
        scanf("%4s,%dA%dB", now, &a, &b);
        for (int i=0; i<size; i++) {
            if (flag[i] == 1)  continue;
            sprintf(guess, "%04X", i);
            for (int j=0; j<4; j++) {
                for (int k=j+1; k<4; k++) {
                    if (guess[j] == guess[k]) {
                        flag[i] = 1;
                    } 
                }
            }
            ga=0; gb=0;
            for (int j=0; j<4; j++) {
                for (int k=0; k<4; k++) {
                    if (guess[j] == now[k]) {
                        if (j == k)  ga++;
                        else gb++;
                    }
                } 
            }
            if (ga != a || gb != b) {
                flag[i] = 1;
                continue;
            }
            guessN++;
            ans = i;
        }
        if (guessN == 1) {
            printf("%04X", ans);
            break;
        }
    }

    return 0;
}
