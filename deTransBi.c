#include <stdio.h>

int main () {
    double n;
    int ff;
    char ss[100];
    scanf("%lf", &n);
    int first = n;
    double second = n - first;
    int i=1;
    while (first != 0) {
        ff += ((first % 2) * i );
        i *= 10;
        first = first / 2;
    }
    int s = 0;
    while (second != 0) {
        second *= 2;
        int f = second;
        second -= f;
        ss[s] = f + '0';
        i *= 10;
        s++;
    }
    ss[s] = '\0';
    printf("%d", ff);
    printf(".");
    printf("%s", ss);

    return 0;
}
