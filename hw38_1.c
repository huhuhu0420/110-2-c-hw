#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    char name[30];
    int age;
    int year;
    int month;
    int date;
    struct node_s *next;
} node_t;
typedef node_t* nodep_t;

nodep_t createNode (int age, char name[30], int year, int month, int date) {
    nodep_t newNode = malloc(sizeof(node_t));
    strncpy(newNode->name, name, 30);
    newNode->age = age;
    newNode->year = year;
    newNode->month = month;
    newNode->date = date;
    newNode->next = NULL;
    return newNode;
}

nodep_t push (nodep_t p, int age, char name[30], int year, int month, int date, nodep_t *top) {
    nodep_t newNode = createNode(age, name, year, month, date), current = p;
    if (p == NULL)  p = newNode;
    else {
        while (current->next != NULL)  current = current->next;
        current->next = newNode;
    }
    (*top) = current;
    return p;
}

void printList (nodep_t p) {
    nodep_t current = p;
    if (current->next == NULL) {
        printf("%s %d %d_%d_%d, ", current->name, current->age, current->year, current->month, current->date);
        return;
    }
    else {
        printList(current->next);
        printf("%s %d %d_%d_%d, ", current->name, current->age, current->year, current->month, current->date);
        return;
    }
}

int main () {
    int age, ins, flag = 0, year, month, date;
    char name[30];
    //char year[30], month[30], date[30], birth[30];
    nodep_t p = NULL, top = NULL;
    while (1) {
        scanf("%d ", &ins);
        switch(ins) {
            case 1:
                memset(name, 0, sizeof(name));
                scanf("%s %d %d %d %d", name, &age, &year, &month, &date);
                printf("%s %d %d %d %d\n", name, age, year, month, date);
                p = push(p, age, name, year, month, date, &top);
                printList(p);
                printf("\n");
                break;
            case 5:
                flag = 1;
                break;
        }
        if (flag == 1)  break;
    }

    return 0;
}
