#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct string_s {
    char data[50];
} string_t;

int getIndex (string_t *origin, int len, char *token) {
    for (int i=0; i<len; i++) {
        if (strcmp(token, origin[i].data) == 0) {
            return i;
        }
    }
    return -1;
}

void getTest (int *test, int i, string_t *origin, int len) {
    char input[200], *token;
    const char split[2] = " ";
    int index=0;

    scanf("%[^\n]s", input);
    token = strtok(input, split);
    while (token != NULL) {
        index = getIndex(origin, len, token);
        test[i] |= (1 << index);
        token = strtok(NULL, split);
    }
}

int main () {
    char input[200], *token;
    const char split[2] = " ";
    int len=0, i=0, j=0, count=0, test[20]={0}, n=0, flag=0;
    string_t origin[20];

    scanf("%[^\n]s", input);

    token = strtok(input, split); 
    while (token != NULL) {
        flag = 0;
        for (int i=0; i<len+1; i++) {
            if (strcmp(token, origin[i].data) == 0){
                flag = 1;
                token = strtok(NULL, split);
                break;
            }
        }
        if (flag == 1)  continue;
        strcpy(origin[len].data, token);
        token = strtok(NULL, split);
        len++;
    }
    scanf("%d", &n);
    getchar();

    for (i=0 ;i<n; i++) {
        getTest(test, i, origin, len);
        getchar();
    }
    for (i=0; i<n; i++) {
        for (j=i+1; j<n; j++) {
            if ((test[i] ^ test[j]) == pow(2, len) - 1) {
                count ++;
            }
        }
    }
    printf("%d", count);
    return 0;
}
