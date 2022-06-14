#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    int data;
    struct node_s* next;
} node_t;
typedef node_t* nodep_t;

nodep_t createNode (int data) {
    nodep_t newNode;
    newNode = (nodep_t)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue (nodep_t (*tail), int data) {
    nodep_t current = (*tail), newNode = createNode(data);
    if ((*tail) == NULL)  (*tail) = newNode;
    else {
        while (current->next != NULL)  current = current->next;
        current->next = newNode;
    }
    (*tail) = newNode;
}

void printList (nodep_t (*head), nodep_t (*tail)) {
    nodep_t current = (*head);
    while (current != (*tail)) {
        printf("%d, ", current->data);
        current = current->next;
    }
}

int main () {
    nodep_t tail = NULL, head = NULL;
    enqueue(&tail, 5);
    enqueue(&tail, 8);
    printList()

    return 0;
}
