#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    int data;
    int power;
    struct node_s *next;
} node_t;
typedef node_t* nodep_t;

void printNode (nodep_t pol) {
    nodep_t current = pol;
    int isFirst = 1;
    char ch[2] = "";
    if (pol == NULL) {
        printf("0");
        return;
    }
    while (current != NULL) {
        strcpy(ch, "+");
        if (current->data < 0)  strcpy(ch, "");  
        if (isFirst == 1) {
            isFirst = 0;
            strcpy(ch, "");
        }
        if (current->power == 1) {
            if (current->data == 1)  printf("%sx", ch);
            else if (current->data == -1)  printf("%sx", ch);
            else {
                printf("%s%dx", ch, current->data);
            }
        }
        else if (current->power == 0) {
            printf("%s%d", ch, current->data);
        }
        else {
            if (current->data == 1)  printf("%sx^%d", ch, current->power);
            else if (current->data == -1)  printf("%sx^%d", ch, current->power);
            else {
                printf("%s%dx^%d", ch, current->data, current->power);
            }
        }
        current = current->next;
    }
}

nodep_t insert (nodep_t pol, int data, int power) {
    nodep_t current = pol, newNode = malloc(sizeof(node_t));
    newNode->data = data;
    newNode->power = power;
    newNode->next = NULL;
    if (pol == NULL)  pol = newNode;
    else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    return pol;
}

nodep_t getInput (nodep_t pol) {
    int i = 0, count = 0, num[20] = {0};
    char ch;
    while (1) {
        scanf("%d", &num[count++]);
        if (scanf("%c", &ch) == EOF || ch == '\n')  break;
    }
    for (i=0; i<count; i++) {
        if (num[i] != 0)
            pol = insert(pol, num[i], count-i-1);
    }
    return pol;
}

nodep_t add (nodep_t ans, nodep_t pol1, nodep_t pol2) {
    while (pol1 != NULL && pol2 != NULL) {
        if (pol1->power > pol2->power) {
            ans = insert(ans, pol1->data, pol1->power);
            pol1 = pol1->next;
        }
        else if (pol1->power < pol2->power) {
            ans = insert(ans, pol2->data, pol2->power);
            pol2 = pol2->next;
        }
        else if (pol1->power == pol2->power) {
            if (pol1->data + pol2->data != 0)
                ans = insert(ans, pol2->data + pol1->data, pol2->power);
            pol2 = pol2->next;
            pol1 = pol1->next;
        }
    } 
    while (pol1 != NULL) {
        ans = insert(ans, pol1->data, pol1->power);
        pol1 = pol1->next;
    }
    while (pol2 != NULL) {
        ans = insert(ans, pol2->data, pol2->power);
        pol2 = pol2->next;
    }
    return ans;
}

nodep_t sub (nodep_t ans, nodep_t pol1, nodep_t pol2) {
    while (pol1 != NULL && pol2 != NULL) {
        if (pol1->power > pol2->power) {
            ans = insert(ans, pol1->data, pol1->power);
            pol1 = pol1->next;
        }
        else if (pol1->power < pol2->power) {
            ans = insert(ans, (-1) * pol2->data, pol2->power);
            pol2 = pol2->next;
        }
        else if (pol1->power == pol2->power) {
            if (pol1->data - pol2->data != 0)
                ans = insert(ans, pol1->data - pol2->data, pol2->power);
            pol2 = pol2->next;
            pol1 = pol1->next;
        }
    } 
    while (pol1 != NULL) {
        ans = insert(ans, pol1->data, pol1->power);
        pol1 = pol1->next;
    }
    while (pol2 != NULL) {
        ans = insert(ans, pol2->data * (-1), pol2->power);
        pol2 = pol2->next;
    }
    return ans;
}

nodep_t copy (nodep_t temp, nodep_t target) {
    while (target != NULL) {
        temp = insert(temp, target->data, target->power);
        target = target->next;
    }
    return temp;
}

void freeNode (nodep_t p) {
    nodep_t cp = p;
    while (p != NULL) {
        cp = p;
        p = p->next;
        free(cp);
    }
} 

nodep_t mul (nodep_t ans, nodep_t pol1, nodep_t pol2) {
    nodep_t cp2 = pol2;
    while (pol1 != NULL) {
        nodep_t temp = NULL, temp2 = NULL;
        cp2 = pol2;
        while (cp2 != NULL) {
            temp = insert(temp, pol1->data*cp2->data, pol1->power+cp2->power);
            cp2 = cp2->next;
        }
        // printf("temp-> ");
        // printNode(temp);
        // printf("\n");
        temp2 = ans;
        //free(ans);
        ans = NULL;
        // printf("temp2-> ");
        // printNode(temp2);
        // printf("\n");
        ans = add(ans, temp, temp2);
        // printf("ans-> ");
        // printNode(ans);
        // printf("\n");
        free(temp);
        free(temp2);
        pol1 = pol1->next;
    }
    return ans;
}

int main () {
    nodep_t pol1 = NULL, pol2 = NULL;
    nodep_t addAns = NULL, subAns = NULL, mulAns = NULL;
    pol1 = getInput(pol1);
    printNode(pol1);
    printf("\n");
    pol2 = getInput(pol2);
    printNode(pol2);
    printf("\n");
    addAns = add(addAns, pol1, pol2);
    printNode(addAns);
    printf("\n");
    subAns = sub(subAns, pol1, pol2);
    printNode(subAns);
    printf("\n");
    mulAns = mul(mulAns, pol1, pol2);
    printNode(mulAns);
    printf("\n");

    return 0;
}
