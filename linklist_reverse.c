#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int data;
    struct node_s *next;
} node_t;
typedef node_t* nodep_t;

nodep_t create (int data) {
    nodep_t newNode;
    newNode = (nodep_t)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

nodep_t insertFromBack (nodep_t p, int data) {
    nodep_t newNode = create(data);
    nodep_t current;
    if (p == NULL)  p = newNode;
    else {
        current = p;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    return p;
}

void print (nodep_t p) {
    nodep_t current = p;
    while (current != NULL) {
        printf("%d, ", current->data);
        current = current->next;
    }
}

nodep_t reverse (nodep_t p) {
    nodep_t previous, current, temp;
    current = p;
    previous = NULL;
    while (current->next != NULL) {
        temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }
    current->next = previous;
    p = current;
    return p;
}

int main () {
    nodep_t p = NULL;
    p = insertFromBack(p, 3);
    p = insertFromBack(p, 4);
    p = insertFromBack(p, 5);
    print(p);
    printf("\n");
    p = reverse(p);
    print(p);

    return 0;
}
