#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    int data;
    int power;
    struct node_s* next;
} node_t;
typedef node_t* nodep_t;

nodep_t createNode(int data, int power) {
    nodep_t newNode;
    newNode = malloc(sizeof(nodep_t));
    newNode->data = data;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

nodep_t insertBack (nodep_t p, int data, int power) {
    nodep_t current, newNode = createNode(data, power);
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

void printList (nodep_t p) {
    nodep_t current = p;
    char sign[2];
    int first = 1, notZero = 0;
    while (current != NULL) {
        if (current->data != 0){
            strcpy(sign, "");
            if (current->data > 0 && first == 0)  strcpy(sign, "+"); 
            if (current->power == 0){
                printf("%s%d", sign, current->data);
                notZero = 1;
            }
            else if (current->power == 1) {
                if (current->data == 1)  printf("%sx", sign);
                else if (current->data == -1)  printf("-x");
                else printf("%s%dx", sign, current->data);
                notZero = 1;
            }
            else{
                if (current->data == 1)  printf("%sx^%d", sign, current->power);
                else if (current->data == -1)  printf("-x^%d", current->power);
                else  printf("%s%dx^%d", sign, current->data, current->power);
                notZero = 1;
            }
        }
        current = current->next;
        first = 0;
    }
    if (notZero == 0)  printf("0");
}

nodep_t getInput (nodep_t p) { 
    int data[20] = {0}, count = 0;
    char c;
    while (1) {
        scanf("%d", &data[count++]);
        if (scanf("%c", &c) == EOF || c == '\n')  break;
    }
    int i=0;
    while (count != 0) {
        count--;
        if (data[i] != 0){
            p = insertBack(p, data[i], count);
        }
        i++;
    }
    return p;
}

nodep_t add (nodep_t p1, nodep_t p2, nodep_t addAns) {
    nodep_t cp1 = p1, cp2 = p2;
    int data;
    while (cp1 != NULL && cp2 != NULL) {
        if (cp1->power > cp2->power) {
            addAns = insertBack(addAns, cp1->data, cp1->power);
            cp1 = cp1->next;
            continue;
        }
        if (cp1->power < cp2->power) {
            addAns = insertBack(addAns, cp2->data, cp2->power);
            cp2 = cp2->next;
            continue;
        }
        if (cp1->power == cp2->power)  data = cp1->data + cp2->data;
        addAns = insertBack(addAns, data, cp1->power);
        cp1 = cp1->next;
        cp2 = cp2->next;
    }
    while (cp1 != NULL) {
        addAns = insertBack(addAns, cp1->data, cp1->power);
        cp1 = cp1->next;
    }
    while (cp2 != NULL) {
        addAns = insertBack(addAns, cp2->data, cp2->power);
        cp2 = cp2->next;
    }
    return addAns;
}

nodep_t sub (nodep_t p1, nodep_t p2, nodep_t subAns) {
    nodep_t cp1 = p1, cp2 = p2;
    int data;
    while (cp1 != NULL && cp2 != NULL) {
        if (cp1->power > cp2->power) {
            subAns = insertBack(subAns, cp1->data, cp1->power);
            cp1 = cp1->next;
            continue;
        }
        if (cp1->power < cp2->power) {
            subAns = insertBack(subAns, (-1)*cp2->data, cp2->power);
            cp2 = cp2->next;
            continue;
        }
        if (cp1->power == cp2->power)  data = cp1->data - cp2->data;
        subAns = insertBack(subAns, data, cp1->power);
        cp1 = cp1->next;
        cp2 = cp2->next;
    }
    while (cp1 != NULL) {
        subAns = insertBack(subAns, cp1->data, cp1->power);
        cp1 = cp1->next;
    }
    while (cp2 != NULL) {
        subAns = insertBack(subAns, (-1)*cp2->data, cp2->power);
        cp2 = cp2->next;
    }
    return subAns;
}

nodep_t freeList (nodep_t p) {
    nodep_t temp;
    while (p != NULL) {
        temp = p;
        p = p->next;
        free(temp);
    }
    return p;
}

nodep_t copyList (nodep_t des, nodep_t source) {
    des = freeList(des);
    while (source != NULL) {
        des = insertBack(des, source->data, source->power);
        source = source->next;
    }
    return des;;
}

nodep_t mul (nodep_t p1, nodep_t p2, nodep_t mulAns) {
    nodep_t cp1 = p1, cp2 = p2, temp = NULL, temp2 = NULL;
    int data, power;
    while (cp2 != NULL) {
        cp1 = p1;
        temp = NULL;
        while (cp1 != NULL) {
            data = cp1->data * cp2->data;
            power = cp1->power + cp2->power;
            temp = insertBack(temp, data, power);
            // printList(temp);
            // printf("\n");
            cp1 = cp1->next;
        } 
        temp2 = freeList(temp2);
        temp2 = add(temp, mulAns, temp2);
        mulAns = copyList(mulAns, temp2);
        cp2 = cp2->next;
    }
    return mulAns;
}

int main () {
    nodep_t p1 = NULL, p2 = NULL, addAns = NULL, subAns = NULL, mulAns = NULL;
    p1 = getInput(p1);
    // printList(p1);
    // printf("\n");
    p2 = getInput(p2);
    // printList(p2);
    // printf("\n");

    addAns = add(p1, p2, addAns);
    printList(addAns);
    printf("\n");
    subAns = sub(p1, p2, subAns);
    printList(subAns);
    printf("\n");
    mulAns = mul(p1, p2, mulAns);
    printList(mulAns);
    printf("\n");

    return 0;
}
