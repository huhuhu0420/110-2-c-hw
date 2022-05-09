#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef enum scoreType_s {
    G, GPA, S
} scoreType_t;

typedef enum grade_s {
    a1=95, a2=87, a3=82, b1=78, b2=75, b3=70, c1=68, c2=65, c3=60, f=50
} grade_t;

typedef union score_s {
    grade_t grade;
    int score;
} score_t;

typedef struct stu_s {
    char id[20];
    int score;
    int avg;
} stu_t;

scoreType_t getType (scoreType_t type, char *ch) {
    if (strcmp(ch, "G") == 0) type = G;
    if (strcmp(ch, "GPA") == 0) type = GPA;
    if (strcmp(ch, "S") == 0) type = S;
    return type;
}

void getScore (scoreType_t type, stu_t *stu, int i, char *ch) {
    if (type == G) {
        if (strcmp(ch, "A+")==0)  stu[i].score += 95;
        else if (strcmp(ch, "A")==0)  stu[i].score += 87;
        else if (strcmp(ch, "A-")==0)  stu[i].score += 82;
        else if (strcmp(ch, "B+")==0)  stu[i].score += 78;
        else if (strcmp(ch, "B")==0)  stu[i].score += 75;
        else if (strcmp(ch, "B-")==0)  stu[i].score += 70;
        else if (strcmp(ch, "C+")==0)  stu[i].score += 68;
        else if (strcmp(ch, "C")==0)  stu[i].score += 65;
        else if (strcmp(ch, "C-")==0)  stu[i].score += 60;
        else if (strcmp(ch, "F")==0)  stu[i].score += 50;
    }
    else if (type == GPA) {
        if (strcmp(ch, "4.3")==0)  stu[i].score += 95;
        else if (strcmp(ch, "4.0")==0)  stu[i].score += 87;
        else if (strcmp(ch, "3.7")==0)  stu[i].score += 82;
        else if (strcmp(ch, "3.3")==0)  stu[i].score += 78;
        else if (strcmp(ch, "3.0")==0)  stu[i].score += 75;
        else if (strcmp(ch, "2.7")==0)  stu[i].score += 70;
        else if (strcmp(ch, "2.3")==0)  stu[i].score += 68;
        else if (strcmp(ch, "2.0")==0)  stu[i].score += 65;
        else if (strcmp(ch, "1.7")==0)  stu[i].score += 60;
        else if (strcmp(ch, "0")==0)  stu[i].score += 50;
    }
    else if (type == S) {
        if (strcmp(ch, "90-100")==0)  stu[i].score += 95;
        else if (strcmp(ch, "85-89")==0)  stu[i].score += 87;
        else if (strcmp(ch, "80-84")==0)  stu[i].score += 82;
        else if (strcmp(ch, "77-79")==0)  stu[i].score += 78;
        else if (strcmp(ch, "73-76")==0)  stu[i].score += 75;
        else if (strcmp(ch, "70-72")==0)  stu[i].score += 70;
        else if (strcmp(ch, "67-69")==0)  stu[i].score += 68;
        else if (strcmp(ch, "63-66")==0)  stu[i].score += 65;
        else if (strcmp(ch, "60-62")==0)  stu[i].score += 60;
        else if (strcmp(ch, "0-59")==0)  stu[i].score += 50;
    }
}

int cmp (const void *a, const void *b) {
    return (*(stu_t*)b).avg - (*(stu_t*)a).avg;
}

int main () {
    int n, i, m, j;
    char ch[20];
    scoreType_t type[10];
    stu_t stu[100];
    for (int i=0; i<10; i++) {
        stu[i].score = 0;
        stu[i].avg = 0;
    }
    scanf("%d", &n);
    getchar();
    for (i=0; i<n; i++) {
        scanf("%s", ch);
        getchar();
        type[i] = getType(type[i], ch);
        ch[0] = '\0';
    }
    scanf("%d", &m);
    getchar();
    for (i=0; i<m; i++) {
        scanf("%s", stu[i].id);
        getchar();
        for (j=0; j<n; j++) {
            scanf("%s", ch);
            getchar();
            getScore(type[j], stu, i, ch);
        }
    }
    for (int i=0; i<m; i++) {
        stu[i].avg = round((double)stu[i].score / n);
    }
    qsort(stu, m, sizeof(stu_t), cmp); 
    for (int i=0; i<3; i++) {
        printf("%s\n", stu[i].id);
        printf("%d\n", stu[i].avg);
    }

    return 0;
}
