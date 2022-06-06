#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int data;
    struct node_s *next;
} node_t;
typedef node_t* nodep_t;

nodep_t createNode (int data) {
    nodep_t newNode;
    newNode = (nodep_t)malloc(sizeof(nodep_t));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList (nodep_t p) {
    nodep_t current = p;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    if (p == NULL)  printf("None any node");
    printf("\n");
}

nodep_t insertBack (nodep_t p, int data) {
    nodep_t newNode = createNode(data), current;
    if (p == NULL) p = newNode;
    else {
        current = p;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    return p;
}

nodep_t insertData (nodep_t p, int target, int data) {
    nodep_t current = p, newNode = createNode(data), cnext;
    while (current != NULL) {
        if (current->data == target) {
            cnext = current->next;
            current->next = newNode;
            newNode->next = cnext;
            break;
        }
        current = current->next;
    }
    return p;
}

nodep_t deleteData (nodep_t p, int target) {
    nodep_t current = p, cLast;
    cLast = NULL;
    while (current != NULL) {
        if (current->data == target) {
            if (cLast == NULL)  p = current->next;
            else
                cLast->next = current->next;
        }
        cLast = current;
        current = current->next;
    }
    return p;
}

nodep_t deleteFirst (nodep_t p) {
    if (p != NULL) {
        p = p->next;
    }
    return p;
}

nodep_t deleteEnd (nodep_t p) {
    nodep_t current = p, cLast = NULL;
    while (current != NULL) {
        if (current->next == NULL) {
            if (cLast == NULL)  p = NULL;
            else
                cLast->next = NULL;
        }
        cLast = current;
        current = current->next;
    }
    return p;
}

int main () {
    nodep_t p = NULL;
    int i, n, ins, target, data, flag = 0;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &data);
        p = insertBack(p, data);
    }
    while (1) {
        scanf("%d", &ins);
        switch (ins) {
            case 1:
                scanf("%d", &data);
                p = insertBack(p, data);
                break;
            case 2:
                scanf("%d %d", &target, &data);
                p = insertData(p, target, data);
                break;
            case 3:
                scanf("%d", &data);
                p = deleteData(p, data);
                break;
            case 4:
                p = deleteFirst(p);
                break;
            case 5:
                p = deleteEnd(p);
                break;
            case 6:
                flag = 1;
                break;
                
        }
        if (flag == 1)  break;
    }
    printList(p);

    return 0;
}
