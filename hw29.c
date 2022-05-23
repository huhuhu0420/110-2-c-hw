#include <stdio.h>

typedef struct process_s {
    int machine_id;
    int time;
} process_t;

typedef struct task_s {
    int current_id;
    int haveDone_time;
    int process_num;
    process_t process[100];
} task_t;

typedef struct machine_s {
    int time[100];
    int num;
} machine_t;

int getFinishTime (machine_t machine, process_t process, task_t task) {
    int finishTIme = 
        machine.time[process.machine_id] > task.haveDone_time ? machine.time[process.machine_id]:task.haveDone_time;
    finishTIme += process.time;
    return finishTIme;
}

int getCorrectProcess (machine_t machine, task_t *task, int m, int *task_id, int *process_id) {
    int min = 99999, finishTIme;
    *task_id = -1;
    for (int i=1; i<=m; i++){
        if (task[i].current_id <= task[i].process_num) {
            finishTIme = getFinishTime(machine, task[i].process[task[i].current_id], task[i]);
            //printf("%d %d\n", i, finishTIme);
            if (finishTIme < min) {
                min = finishTIme;
                *task_id = i;
                *process_id = task[i].current_id;
            }
        }
    }
    return min;
}

void arrange (machine_t *machine, task_t *task, int m, int *flag) {
    int task_id, process_id, finishTime;
    finishTime = getCorrectProcess(*machine, task, m, &task_id, &process_id);
    //printf("process -- %d %d\n", task_id, process_id);
    (*machine).time[task[task_id].process[process_id].machine_id] = finishTime;
    task[task_id].current_id += 1;
    //printf("+++%d %d\n", task[task_id].current_id, task[task_id].process_num);
    task[task_id].haveDone_time = (*machine).time[task[task_id].process[process_id].machine_id];
    //for (int i=0; i<(*machine).num; i++) {
    //    printf("%d:%d ", i, (*machine).time[i]);
    //}
    //printf("\n");
    //for (int i=1; i<=m; i++) {
    //    printf("%d %d %d %d\n", i, task[i].current_id, task[i].haveDone_time, task[i].haveDone_time);
    //}
    if (task_id == -1) {
        *flag = -1;
        return;
    } 
}

void do_sth (machine_t machine, task_t *task, int m) {
    int flag = 0, total = 0;
    while (flag == 0)  arrange(&machine, task, m, &flag);
    for (int i=1; i<=m; i++) {
        total += task[i].haveDone_time;
    }
    printf("%d", total);
}
    
int main () {
    int m, i, j; 
    machine_t machine;
    task_t task[100];

    scanf("%d %d ", &machine.num, &m);
    for (i=0; i<machine.num; i++) {
        machine.time[i] = 0;
    }
    for (i=1; i<=m; i++) {
        task[i].current_id = 1;
        task[i].haveDone_time = 0;
        scanf("%d", &task[i].process_num);
        for (j=1; j<=task[i].process_num; j++) {
            scanf("%d %d", &task[i].process[j].machine_id , &task[i].process[j].time);
        }
    }
    // for (i=1; i<=m; i++) {
    //     printf("%d--> ", i);
    //     for (j=1; j<=task[i].process_num; j++) {
    //         printf("%d %d, ", task[i].process[j].machine_id, task[i].process[j].time);
    //     }
    //     printf("\n");
    // }
    
    do_sth(machine, task, m);

    return 0;
}
