#include <stdio.h>
#include <math.h>
#include <string.h>

int main () {
    int n, i=0, k;
    scanf("%d", &k);
    n = k;
    char data[100];
    while (n != 0) {
        data[i++] = (n % 10) + '0';
        n = n / 10;
    }
    data[i] = '\0';
    printf("%s\n", data);
    int l = strlen(data);
    int sum = 0;
    for (i=0; i<l; i++) {
        sum += pow((data[i]-'0'), l);
    }
    if (sum == k) printf("Y");
    else printf("No");

    return 0;
}
