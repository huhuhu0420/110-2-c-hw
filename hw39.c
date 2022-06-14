#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    char name[30];
    int age, year, month, date;
    struct node_s *next;
} node_t;
typedef node_t* nodep_t;

nodep_t createNode (char *name, int age, int year, int month, int date) {
    nodep_t newNode = malloc(sizeof(node_t));
    newNode->age = age;
    newNode->year = year;
    newNode->month = month;
    newNode->date = date;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

void printList (nodep_t (*head)) {
    nodep_t current = (*head);
    if ((*head) == NULL) {
        printf("The Queue is empty\n");
    }
    while (current != NULL) {
        printf("%s ", current->name);
        printf("%d ", current->age);
        printf("%d_%d_%d\n", current->year, current->month, current->date);
        current = current->next;
    }
}

node_t dequeue (nodep_t (*head), nodep_t (*tail), int *isEmpty) {
    node_t item;
    nodep_t p_item;
    if ((*head) == NULL) {
        (*isEmpty) = 1;
        return item;
    }
    (*isEmpty) = 0;
    item = *(*head);
    p_item = (*head);
    if ((*head) == (*tail)) {
        (*head) = NULL;
        (*tail) = NULL;
    }
    else
        (*head) = p_item->next;
    free(p_item);
    return item;
}

void enqueue (nodep_t *head, nodep_t *tail, char *name, int age, int year, int month, int date) {
    nodep_t newNode = createNode(name, age, year, month, date);
    if ((*tail) == NULL) {
        (*head) = newNode;
        (*tail) = newNode;
    }
    else {
        (*tail)->next = newNode;
        (*tail) = newNode;
    }
}

int getCount (nodep_t *head) {
    nodep_t current = *head;
    int count = 0;
    while (current != NULL) {
        count += 1;
        current = current->next;
    }
    return count;
}

int main () {
    int isEmpty = 0, ins, year, month, date, age, deqIns;
    nodep_t head = NULL, tail = NULL;
    node_t item;
    char name[30];

    while (ins != 5) {
        scanf("%d", &ins);
        getchar();
        //printf("%d-> ", ins);
        switch (ins) {
            case 1:
                scanf("%s %d %d %d %d", name, &age, &year, &month, &date);
                //printf("%s %d %d %d %d\n", name, age, year, month, date);
                enqueue(&head, &tail, name, age, year, month, date);
                break;
            case 2:
                scanf("%d", &deqIns);
                item = dequeue(&head, &tail, &isEmpty);
                if (isEmpty == 1) {
                    printf("The Queue is empty\n");
                }
                else {
                    if (deqIns == 1)  printf("%s\n", item.name);
                    else if (deqIns == 2)  printf("%d\n", item.age);
                    else if (deqIns == 3)  printf("%d_%d_%d\n", item.year, item.month, item.date);
                }
                break;
            case 3:
                item = dequeue(&head, &tail, &isEmpty);
                if (isEmpty == 1) {
                    printf("The Queue is empty\n");
                    break;
                }
                printf("%s ", item.name);
                printf("%d ", item.age);
                printf("%d_%d_%d\n", item.year, item.month, item.date);
                while (1) {
                    item = dequeue(&head, &tail, &isEmpty);
                    if (isEmpty == 1) {
                        break;
                    }
                    printf("%s ", item.name);
                    printf("%d ", item.age);
                    printf("%d_%d_%d\n", item.year, item.month, item.date);
                }
                break;
            case 4:
                printList(&head);
                break;
            case 5:
                printf("%d\n", getCount(&head));
                break;
        }
        //printList(&head);
    }

    return 0;
}
