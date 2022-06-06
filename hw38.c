#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    char birth[20];
    char name[20];
    int age;
    struct node_s* next;
} node_t;
typedef node_t* nodep_t;

nodep_t createNode (char name[20], int age, char birth[20]) {
    nodep_t newNode;
    newNode = (nodep_t)malloc(sizeof(node_t));
    newNode->age = age;
    strcpy(newNode->name, name);
    strcpy(newNode->birth, birth);
    newNode->next = NULL;
    return newNode;
}

nodep_t push (nodep_t p, char *name, int age, char *birth, nodep_t (*top)) {
    nodep_t current, newNode = createNode(name, age, birth);
    if (p == NULL)  p = newNode;
    else {
        current = p;
        while (current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
    (*top) = newNode;
    return p;
}

nodep_t pop (nodep_t p, int *isEmpty, nodep_t (*top)) {
    nodep_t current = p, last = p;
    if (current == NULL) {
        (*isEmpty) = 1;
        return p;
    }
    if (current->next == NULL) {
        p = NULL;
        (*isEmpty) = 1;
        (*top) = p;
        return p;
    }
    while (current->next !=NULL){
        last = current;
        current = current->next;
    }
    last->next = NULL;
    (*top) = last;
    return p;
}

void printList (nodep_t p) {
    nodep_t current = p;
    if (current->next == NULL) {
        printf("%s %d %s\n", current->name, current->age, current->birth);
        return;
    }
    else {
        printList(current->next);
        printf("%s %d %s\n", current->name, current->age, current->birth);
        return;
    }
}

void getBirth (char *birth, char *year, char *month, char *date) {
    strcpy(birth, year);
    strcat(birth, "_");
    strcat(birth, month);
    strcat(birth, "_");
    strcat(birth, date);
}

int getCount (nodep_t p) {
    int count = 0;
    nodep_t current = p;
    while (current != NULL) {
        current = current->next;
        count++;
    }
    return count;
}

int main () {
    nodep_t p = NULL, top = NULL;
    char name[20], year[10], month[10], date[10], birth[20];
    int age, isEmpty = 0, ins, flag = 0, popIns, count;
    while (1) {
        scanf("%d", &ins);
        //printf("%d\n", ins);
        getchar();
        switch (ins) {
            case 1:
                memset(year, 0, sizeof(year));
                memset(name, 0, sizeof(name));
                memset(month, 0, sizeof(month));
                memset(date, 0, sizeof(date));
                memset(birth, 0, sizeof(birth));
                scanf("%s %d %s %s %s", name, &age, year, month, date);
                //printf("%s %d %s %s %s\n", name, age, year, month, date);
                getBirth(birth, year, month, date);
                p = push(p, name, age, birth, &top);
                isEmpty = 0;
                break;
            case 2:
                scanf("%d", &popIns);
                if (isEmpty == 1) {
                    printf("The Stack is empty\n");
                    continue;
                }
                if (popIns == 1) {
                    printf("%s\n", top->name);
                }
                else if (popIns == 2) {
                    printf("%d\n", top->age);
                }
                else if (popIns == 3) {
                    printf("%s\n", top->birth);
                }
                p = pop(p, &isEmpty, &top);
                break;
            case 3:
                if (isEmpty == 1) {
                    printf("The Stack is empty\n");
                    continue;
                }
                while (isEmpty != 1) {
                    printf("%s %d %s\n", top->name, top->age, top->birth);
                    p = pop(p, &isEmpty, &top);
                }
                break;
            case 4:
                if (isEmpty == 1) {
                    printf("The Stack is empty\n");
                    continue;
                }
                printList(p);
                break;
            case 5:
                count = getCount(p);
                printf("%d\n", count);
                flag = 1;
                break;
        }
        if (flag == 1)  break;
    }
    return 0;
}
