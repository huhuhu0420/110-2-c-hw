#include <stdio.h>

typedef struct course_s {
    int id;
    int hour;
    int time[3];
} course_t;

int getTime (course_t *course, int n, int *id2) {
    int record[100]={0}, i, j, temp=0;
    for (i=0; i<n; i++) {
        for (j=0; j<course[i].hour; j++) {
            temp = course[i].time[j];
            record[temp] +=1;
            if (record[temp] == 2) {
                *id2 = course[i].id;
                return temp;
            }
        }
    }
    return temp;
}

int getId1 (course_t *course, int n, int time) {
    int i, j;
    for (i=0; i<n; i++ ) {
        for (j=0; j<course[i].hour; j++) {
            if (course[i].time[j] == time) {
                return course[i].id;
            }
        }
    }
}

int main () {
    course_t course[10];
    int i, j, n, time, id1, id2;
    
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &course[i].id);
        scanf("%d", &course[i].hour);
        for (j=0; j<course[i].hour; j++) {
            scanf("%d", &course[i].time[j]);
        }
    }
    time = getTime(course, n, &id2);
    id1 = getId1(course, n, time);
    printf("%d %d %d\n", time, id1, id2);

    return 0;
}
