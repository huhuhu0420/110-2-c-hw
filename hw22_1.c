#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct article_s {
    char word[20];
    int count;
} article_t;

void replace (char sentence[20][20], char old[], char new[], int sid) {
    char change[20][20], cid = 0;
    int i;
    for (i=0; i<sid; i++) {
        if (strcmp(sentence[i], old) == 0) {
            strcpy(change[cid], new);
            cid++;
        }
        else {
            strcpy(change[cid++], sentence[i]);
        }
    }
    for (i=0; i<cid; i++) {
        printf("%s ", change[i]);
    }
}

void insert (char sentence[20][20], char old[], char new[], int sid) {
    char change[20][20], cid = 0;
    int i;
    for (i=0; i<sid; i++) {
        if (strcmp(sentence[i], old) == 0) {
            strcpy(change[cid++], old);
            strcpy(change[cid], new);
            cid++;
        }
        else {
            strcpy(change[cid++], sentence[i]);
        }
    }
    for (i=0; i<cid; i++) {
        printf("%s ", change[i]);
    }
}

void delete (char sentence[20][20], char old[], char new[], int sid) {
    char change[20][20], cid = 0;
    int i;
    for (i=0; i<sid; i++) {
        if (strcmp(sentence[i], old) == 0) {
            continue;
        }
        else {
            strcpy(change[cid++], sentence[i]);
        }
    }
    for (i=0; i<cid; i++) {
        printf("%s ", change[i]);
    }
}

int cmp (const void* a, const void* b) {
    int tmp =  (*(article_t*)b).count - (*(article_t*)a).count;
    if (tmp == 0) {
        return (strcmp((*(article_t*)a).word, (*(article_t*)b).word));
    }
    return tmp;
}

void getCount (char sentence[20][20], int sid) {
    article_t article[10];
    int i, aid = 0, flag = 0, j;
    for (i=0; i<sid; i++) {
        flag = 0;
        for (j=0; j<aid; j++) {
            if (strcmp(sentence[i], article[j].word) == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            strcpy(article[aid++].word, sentence[i]);
        }
    }
    for (i=0; i<10; i++)  article[i].count = 0;
    for (i=0; i<aid; i++) {
        printf("%s ", article[i].word);
        for (j=0; j<sid; j++) {
            if (strcmp(article[i].word, sentence[j]) == 0) {
                article[i].count++;
            }
        }
    }
    printf("\n");
    qsort(article, aid, sizeof(article_t), cmp);
    for (i=0; i<aid; i++) {
        printf("%s %d\n", article[i].word, article[i].count);
    }
}

int main () {
    char sentence[20][20], input[100], *token, pWord[20], qWord[20];
    const char split[2] = " ";
    char article[10];
    int sid = 0, i, j;
    scanf("%[^\n]s", input);
    token = strtok(input, split);
    while (token != NULL) {
        strcpy(sentence[sid], token);
        sid++;
        token = strtok(NULL, split);
    }
    for (i=0; i<sid; i++) {
        printf("%s ", sentence[i]);
    }
    scanf("%s", pWord);
    scanf("%s", qWord);
    printf("\n");
    replace(sentence, pWord, qWord, sid);
    printf("\n");
    insert(sentence, pWord, qWord, sid);
    printf("\n");
    delete(sentence, pWord, qWord, sid);
    printf("\n");
    getCount(sentence, sid);

    return 0;
}
