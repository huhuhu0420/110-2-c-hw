#include <stdio.h>
#include<string.h>
#include<assert.h>

#define STRINGLEN 80
#define LETTER 100
int main(void)
{
    char string[STRINGLEN];
    printf("輸入英文句子:");
    scanf("%[^\n]s", string);
    char file[LETTER][STRINGLEN];
    int fileCount = 0;
    char *start = string;
    char delimeters[] = " ";
    start = strtok(start, delimeters);
    while (start != NULL) {
        strcpy(file[fileCount], start);
        fileCount++;
        assert(fileCount < LETTER);
        start = strtok(NULL, delimeters);
    }
    for (int i = 0; i < fileCount; i++) {
        printf("%s\n", file[i]);
    }

    int num[LETTER] = {0};
    for (int i=0; i<fileCount; i++) {
        for (int j=0; j<fileCount; j++) {
            if (strcmp(file[i], file[j])==0)  num[i]++;
        }
    }

    for (int i=0; i<fileCount; i++) {
        printf("%s %d\n", file[i], num[i]);
    }

    char temp[100];
    int tempNum;
    for (int i=0; i<fileCount; i++) {
        for (int j=0; j<fileCount-i-1; j++) {
            if (num[j] < num[j+1]){
                tempNum = num[j];
                num[j] = num[j+1];
                num[j+1] = tempNum;
                strcpy(temp, file[j]);
                strcpy(file[j], file[j+1]);
                strcpy(file[j+1], temp);
            }
            else if (num[j] == num[j+1] && strcmp(file[j], file[j+1])>0) {
                strcpy(temp, file[j]);
                strcpy(file[j], file[j+1]);
                strcpy(file[j+1], temp);
            }
        }
    }
    
    printf("%d %s\n", num[0], file[0]);
    for (int i=1; i<fileCount; i++) {
        if (strcmp(file[i], file[i-1]) != 0)  printf("%d %s\n", num[i], file[i]);
    }

}
