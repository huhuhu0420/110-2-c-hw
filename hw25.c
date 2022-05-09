#include <stdio.h>
#include <ctype.h>
#include <string.h>

void match (char *data, int start, int *end, int k) {
    int flag=0, i=start, now=0;
    if (isupper(data[i]) != 0)  now = 1;
    i++;
    flag++;
    if (flag == k) {
        (*end) = i;
        flag = 0;
        now = (now + 1) % 2;
    }
    while (data[i] != '\0') {
        // printf("%d %d %d\n", i, flag, now);
        // printf("%d\n", isupper(data[i]));
        if (now == 1 && isupper(data[i]) == 0)  return;
        else if (now == 0 && isupper(data[i]) > 0)  return;
        i++;
        flag ++;
        if (flag == k) {
            (*end) = i;
            flag = 0;
            now = (now + 1) % 2;
        }
    }   
}

int process (char *data, int k) {
    int len=0, max=-1, end=0;
    for (int i=0; i<strlen(data); i++) {
        end = i;
        match(data, i, &end, k);
        len = end - i;
        if (len > max)  max = len;
    }
    return max;
}

int main () {
    int k=0;
    char data[100];

    scanf("%d", &k);
    scanf("%s", data);
    printf("%d", process(data, k));

    return 0;
}
