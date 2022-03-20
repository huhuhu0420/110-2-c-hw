#include <stdio.h>

typedef struct course_s{
    int courseId;
    int hour;
    int courseTime[3];
}course_t;

int compareCourseTime(course_t c1, course_t c2){
    int i, j, conflict=-1;
    for(i=0; i<c1.hour; i++){
        for(j=0; j<c2.hour; j++){
            //printf("%d %d\n", c1.courseTime[i], c2.courseTime[j]);
            if(c1.courseTime[i] == c2.courseTime[j]){
                conflict = c1.courseTime[i];
                return conflict;
            }
        }
    }
    return conflict;
}

int getConflict(course_t courses[3], int *cId1, int *cId2){
    int i, j, conflict;
    for(i=0; i<2; i++){
        for(j=i+1; j<3; j++){
            conflict = compareCourseTime(courses[i], courses[j]);
            if(conflict != -1){
                *cId1 = courses[i].courseId;
                *cId2 = courses[j].courseId;
                return conflict;
            }
        }
    }
    return conflict;
}

int main(){
    course_t courses[3];
    int i, j, cId1, cId2, conflict;

    for(i=0; i<3; i++){
        scanf("%d", &courses[i].courseId);
        scanf("%d", &courses[i].hour);
        for(j=0; j<courses[i].hour; j++){
            scanf("%d", &courses[i].courseTime[j]);
        }
    }
    conflict = getConflict(courses, &cId1, &cId2);
    printf("%d and %d conflict on %d", cId1, cId2, conflict);

    return 0;
}
