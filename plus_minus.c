#include <stdio.h>
#include <assert.h>
#include <string.h>
#define MAX 10

int main()
{
    int YN;
    do{
        char i[MAX], j[MAX];
        int length_i, length_j, p_m, i_num[MAX] = { 0 }, j_num[MAX] = { 0 }, sum[MAX] = { 0 }, difference[MAX] = {0};

        

        printf("Input first number:");
        scanf("%s", i);
        length_i = strlen(i);
        assert(length_i <= MAX);

        printf("Input second number:");
        scanf("%s", j);
        length_j = strlen(j);
        assert(length_j <= MAX);

        printf("plus or minus? 1 or 0 :");
        scanf("%d", &p_m);

        for (int m = 0; m < length_i ; m++) {
            i_num[m] = i[length_i - m - 1] - '0';
        }
        for (int m = 0; m < length_j; m++) {
            j_num[m] = j[length_j - m - 1] - '0';
        }

        if (p_m == 1) {
            int over, m,length_sum;
            for (over = m = 0; m < MAX; m++) {
                sum[m] = i_num[m] + j_num[m] + over;
                over = sum[m] / 10;
                sum[m] %= 10;
            }
            

            if (over > 0) {
                printf("overflow.\n");
            }
            else {
                int k = MAX - 1, s = 0;
                printf("Plus,ans:");
                while (k > 0) {
                    if (sum[k] != 0) {
                        s = k;
                        break;
                    }
                    k--;
                }
                for (int k = s; k >= 0; k--) {
                    printf("%d", sum[k]);
                }
                printf("\n");
               
            }
        }
        else {
            int minus, m;
            for (minus = m = 0; m < MAX; m++) {
                difference[m] = i_num[m] - j_num[m] - minus;
                if (difference[m] < 0) {
                    minus = 1;
                    difference[m] += 10;
                }
                else {
                    minus = 0;
                }
            }

            int k = MAX - 1, s = 0;
            printf("Minus,ans:");
            while (k > 0) {
                if (difference[k] != 0) {
                    s = k;
                    break;
                }
                k--;
            }
            for (int k = s; k >= 0; k--) {                
                printf("%d", difference[k]);
            }
            printf("\n");
        }

        printf("calculate again? 1:0 :");
        scanf("%d", &YN);
    } while (YN == 1);    
}


