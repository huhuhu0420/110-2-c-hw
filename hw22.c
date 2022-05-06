#include <stdio.h>
#include <string.h>

void replace (char sentence[][30], char *old, char *new, int len) {
    for (int i=0; i<len; i++) {
        if (strcmp(sentence[i], old) == 0) {
            printf("%s ", new);
            continue;
        }
        printf("%s ", sentence[i]);
    }
}

void insert (char sentence[][30], char *old, char *new, int len) {
    for (int i=0; i<len; i++) {
        if (strcmp(sentence[i], old) == 0) {
            printf("%s ", new);
        }
        printf("%s ", sentence[i]);
    }
}

void delete (char sentence[][30], char *old, int len) {
    for (int i=0; i<len; i++) {
        if (strcmp(sentence[i], old) == 0) {
            continue;
        }
        printf("%s ", sentence[i]);
    }
}

void getTimes (char sentence[][30], char word[][30], int times[], int len, int *word_len) {
    int flag;
    for (int i=0; i<len; i++) {
        flag = 0;
        for (int j=0; j<(*word_len); j++) {
            if (strcmp(sentence[i], word[j]) == 0) {
                flag = 1;
                times[j] ++;
                break;
            }
        }
        if (flag == 1) continue;
        strcpy(word[*word_len], sentence[i]);
        (*word_len) ++;
    }
}

int main () {
    char input[200], sentence[20][30], word[20][30], old[30], new[30], *token;
    const char split[2]=" ";
    int len=0, word_len=0, times[20]={0};

    scanf("%[^\n]s", input);
    token = strtok(input, split);
    while (token != NULL) {
        strcpy(sentence[len], token);
        token = strtok(NULL, split);
        len ++;
    }
    scanf("%s", old);
    scanf("%s", new);
    
    replace(sentence, old, new, len);
    printf("\n");
    insert(sentence, old, new, len);
    printf("\n");
    delete(sentence, old, len);
    printf("\n");

    getTimes(sentence, word, times, len, &word_len);
    char temp[30];
    int times_temp=0;
    for (int i=0; i<word_len; i++) {
        for (int j=0; j<word_len-1-i; j++) {
            if (times[j] < times[j+1]) {
                strncpy(temp, word[j], 30);
                strncpy(word[j], word[j+1], 30);
                strncpy(word[j+1], temp, 30);
                times_temp = times[j];
                times[j] = times[j+1];
                times[j+1] = times_temp; 
            }
            else if (times[j] == times[j+1] && strlen(word[j]) > strlen(word[j+1])) {
                strncpy(temp, word[j], 30);
                strncpy(word[j], word[j+1], 30);
                strncpy(word[j+1], temp, 30);
                times_temp = times[j];
                times[j] = times[j+1];
                times[j+1] = times_temp;
            }
            else if (times[j] == times[j+1] && strlen(word[j]) == strlen(word[j+1]) && strcmp(word[j], word[j+1]) > 0) {
                strncpy(temp, word[j], 30);
                strncpy(word[j], word[j+1], 30);
                strncpy(word[j+1], temp, 30);
                times_temp = times[j];
                times[j] = times[j+1];
                times[j+1] = times_temp;
            }
        }
    }
    for (int i=0; i<word_len; i++) {
        printf("%s %d\n", word[i], times[i]+1);
    }

    return 0;
}
