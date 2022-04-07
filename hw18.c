#include <stdio.h>
#include <string.h>

int isDuplicate (char *data, int start, int m) {
    int i, j;
    // printf("%d %d\n", start, start+m);
    for (i=start; i<start+m; i++) {
        for (j=start; j<start+m; j++) {
            if(data[i] == data[j] && i != j){
                return 1;
            }
        }
    }
    return 0;
}

int getCount (char *data, int m) {
    int start, count=0, len;
    len = strlen(data);
    for (start=0; start<=len-m; start++) {
        if(isDuplicate(data, start, m) == 0)  count++;
    }
    return count;
}

int main () {
    char data[100];
    int m, count;

    scanf("%s", data);
    scanf("%d", &m);
    count = getCount(data, m);
    printf("%d", count);

    return 0;
}
