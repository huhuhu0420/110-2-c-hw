#include <stdio.h>

typedef struct process_s {
    int time;
    int machineID;
} process_t;

typedef struct task_s {
    int ctime;
    int currentID;
    int processN;
    process_t process[10];
} task_t;

typedef struct machine_s {
    int ctime;
} machine_t;

void f (machine_t machine[], task_t task[], int taskN, int *flag) {
    int i, mid, pid, startTime, endtime, min_endtime=99999;
    int min_mid, min_tid;
    for (i=0; i<taskN; i++) {
        if (task[i].currentID >= task[i].processN)  continue;
        pid = task[i].currentID;
        mid = task[i].process[pid].machineID;
        startTime = machine[mid].ctime > task[i].ctime ? machine[mid].ctime : task[i].ctime;
        endtime = startTime + task[i].process[pid].time;
        if (endtime < min_endtime) {
            min_endtime = endtime;
            min_mid = mid;
            min_tid = i;
        }
    }
    if (min_endtime == 99999) {
        (*flag) = 1;
        return;
    }
    task[min_tid].ctime = min_endtime;
    task[min_tid].currentID += 1;
    machine[min_mid].ctime = min_endtime;
    printf("%d %d\n", min_tid, min_endtime);
}

int main () {
    machine_t machine[10];
    task_t task[10];
    int machineN, taskN, flag = 0;
    scanf("%d %d", &machineN, &taskN);
    for (int i=0; i<10; i++) {
        machine[i].ctime = 0;
        task[i].ctime = 0;
        task[i].currentID = 0;
    }
    for (int i=0; i<taskN; i++) {
        scanf("%d", &task[i].processN);
        for (int j=0; j<task[i].processN; j++) {
            scanf("%d %d", &task[i].process[j].machineID, &task[i].process[j].time);
            getchar();
        }
    }
    for (int i=0; i<taskN; i++) {
        printf("%d-> ", task[i].processN);
        for (int j=0; j<task[i].processN; j++) {
            printf("%d %d ", task[i].process[j].machineID, task[i].process[j].time);
        }
        printf("\n");
    }
    while (1) {
        f(machine, task, taskN, &flag);
        if (flag == 1) break;
    }
    for (int i=0; i<taskN; i++) {
        printf("%d ", task[i].ctime);
    }

    return 0;
}
