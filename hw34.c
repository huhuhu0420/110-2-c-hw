#include <stdio.h>
#include <string.h>
#include <ctype.h>

void process (char *article, char *ins) {
    int ins_index=0, article_index=0;
    int len = strlen(article);
    int i;
    char temp;
    while (ins[ins_index] != '\0') {
        len = strlen(article);
        switch (ins[ins_index]) {
            case '0':
                article_index = 0;
                break;
            case '$':
                article_index = len;
                break;
            case 'x':
                if (article[article_index] != '\0') {
                    for (i=article_index; i<len-1; i++) {
                        article[i] = article[i+1];
                    }
                article[i] = '\0';
                }
                break;
            case 's':
                if (article_index < len - 1){
                    temp = article[article_index];
                    article[article_index] = article[article_index + 1];
                    article[article_index + 1] = temp;
                    break;
                }
            case 'i':
                for (int i=len; i>=article_index; i--) {
                    article[i+1] = article[i];
                }
                ins_index ++;
                article[article_index] = ins[ins_index];
                article_index++;
                break;
            case 'u':
                if (isalpha(article[article_index])) {
                    article[article_index] = toupper(article[article_index]);
                }
                article_index++;
                break;
            case '+':
                article_index++;
                break;
            case '-':
                article_index--;
                break;
        }
        ins_index++;
    }
}

int main () {
    char article[200], ins[200];
    scanf("%[^\n]s", article);
    getchar();
    scanf("%[^\n]s", ins);
    process(article, ins);
    printf("%s", article);

    return 0;
}
