#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    char data;
    struct node_s *left, *right;
} node_t;
typedef node_t* nodep_t;

nodep_t createNode (char data) {
    nodep_t newNode = malloc(sizeof(node_t));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printTree (nodep_t tree) {
    nodep_t current = tree, queue[100];
    int head = 0, tail = -1;
    tail++;
    queue[tail] = current;
    while (1) {
        nodep_t current = queue[head];
        head++;
        printf("%c", current->data);
        if (current->left != NULL) {
            tail++;
            queue[tail] = current->left;
        }
        if (current->right != NULL) {
            tail++;
            queue[tail] = current->right;
        }
        if (head > tail)  break;
    }
}

void p_process (nodep_t *vertex, int start, int end, char *pList, char *iList, int p_index, int direct) {
    int i;
    // printf("%d %d-> ", start, end);
    // printf("p_index=%d, ", p_index);
    for (i=start; i<=end; i++) {
        if (iList[i] == pList[p_index]) {
            // printf("i=%d: ", i);
            break;
        }
    }
    nodep_t newNode = createNode(iList[i]);
    if (direct == -1)  (*vertex) = newNode;
    else if (direct == 0) {
        (*vertex)->left = newNode;    
    }
    else if (direct == 1) {
        (*vertex)->right = newNode;    
    }
    printf("\n");
    if (start == end)  return;
    if (i-1 >= start)
        p_process(&newNode, start, i-1, pList, iList, p_index+1, 0);
    if (i+1 <= end) 
        p_process(&newNode, i+1, end, pList, iList, p_index+i-start+1, 1);
}

void o_process (nodep_t *vertex, int start, int end, char *oList, char *iList, int o_index, int direct) {
    int i;
    // printf("%d %d-> ", start, end);
    // printf("o_index=%d, ", o_index);
    for (i=start; i<=end; i++) {
        if (iList[i] == oList[o_index]) {
            // printf("i=%d: ", i);
            break;
        }
    }
    nodep_t newNode = createNode(iList[i]);
    if (direct == -1)  (*vertex) = newNode;
    else if (direct == 0) {
        (*vertex)->left = newNode;    
    }
    else if (direct == 1) {
        (*vertex)->right = newNode;    
    }
    // printf("\n");
    if (start == end)  return;
    if (i-1 >= start)
        o_process(&newNode, start, i-1, oList, iList, o_index-(end-i)-1, 0);
    if (i+1 <= end) 
        o_process(&newNode, i+1, end, oList, iList, o_index-1, 1);
}

int main () {
    char list1[20], list2[20], order1, order2;
    nodep_t tree = NULL;
    scanf("%c", &order1);
    getchar();
    scanf("%s", list1);
    getchar();
    scanf("%c", &order2);
    getchar();
    scanf("%s", list2);
    getchar();

    if (order1 == 'P' && order2 == 'I') {
        p_process(&tree, 0, strlen(list1)-1, list1, list2, 0, -1);
    }
    if (order1 == 'I' && order2 == 'P') {
        p_process(&tree, 0, strlen(list1)-1, list2, list1, 0, -1);
    }
    if (order1 == 'O' && order2 == 'I') {
        o_process(&tree, 0, strlen(list1)-1, list1, list2, strlen(list1)-1, -1);
    }
    if (order1 == 'I' && order2 == 'O') {
        o_process(&tree, 0, strlen(list1)-1, list2, list1, strlen(list1)-1, -1);
    }

    printTree(tree);

    return 0;
}
