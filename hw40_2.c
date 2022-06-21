#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    char data;
    struct node_s* left, *right;
} node_t;
typedef node_t* nodep_t;

void printTree_pre (nodep_t tree) {
    if (tree == NULL) return; 
    printf("%c", tree->data);
    if (tree->left != NULL)  printTree_pre(tree->left);
    if (tree->right != NULL)  printTree_pre(tree->right);
}

void printTree (nodep_t tree) {
    nodep_t queue[100], current;
    int head = -1, tail = -1;
    queue[++tail] = tree;
    while (1) {
        current = queue[++head];
        printf("%c", current->data);
        if (current->left != NULL)  queue[++tail] = current->left;
        if (current->right != NULL)  queue[++tail] = current->right;
        if (tail <= head)  break;
    }
}

void p_process (nodep_t *tree, char *pList, char *iList, int pIndex, int start, int end, int dir) {
    int i;
    for (i=start; i<=end; i++) {
        if (pList[pIndex] == iList[i])  break; 
    }
    nodep_t newNode = malloc(sizeof(node_t));
    newNode->data = iList[i];
    newNode->left = NULL;
    newNode->right = NULL;
    if (dir == -1)  (*tree) = newNode;
    else if (dir == 0) {
        (*tree)->left = newNode;
    }
    else if (dir == 1) {
        (*tree)->right = newNode;
    }
    if (start == end)  return;
    if (start <= (i-1)) {
        p_process(&newNode, pList, iList, pIndex+1, start, i-1, 0);
    }
    if ((i+1) <= end) {
        p_process(&newNode, pList, iList, pIndex+i-start+1, i+1, end, 1);
    }

}

void o_process (nodep_t *tree, char *oList, char *iList, int oIndex, int start, int end, int dir) {
    int i;
    for (i=start; i<=end; i++) {
        if (oList[oIndex] == iList[i])  break; 
    }
    nodep_t newNode = malloc(sizeof(node_t));
    newNode->data = iList[i];
    newNode->left = NULL;
    newNode->right = NULL;
    if (dir == -1)  (*tree) = newNode;
    else if (dir == 0) {
        (*tree)->left = newNode;
    }
    else if (dir == 1) {
        (*tree)->right = newNode;
    }
    if (start == end)  return;
    if (start <= (i-1)) {
        o_process(&newNode, oList, iList, oIndex-end+i-1, start, i-1, 0);
    }
    if ((i+1) <= end) {
        o_process(&newNode, oList, iList, oIndex-1, i+1, end, 1);
    }

}

int main () {
    nodep_t tree = NULL;
    char l1[20], l2[20], type1, type2;
    scanf("%c", &type1);
    getchar();
    scanf("%s", l1);
    getchar();
    scanf("%c", &type2);
    getchar();
    scanf("%s", l2);
    printf("%s\n", l1);
    printf("%s\n", l2);
    if (type1 == 'P' && type2 == 'I') {
        p_process(&tree, l1, l2, 0, 0, strlen(l1)-1, -1);
    }
    else if (type1 == 'I' && type2 == 'P') {
        p_process(&tree, l2, l1, 0, 0, strlen(l1)-1, -1);
    }
    else if (type1 == 'O' && type2 == 'I') {
        o_process(&tree, l1, l2, strlen(l1)-1, 0, strlen(l1)-1, -1);
    }
    else if (type1 == 'I' && type2 == 'O') {
        o_process(&tree, l2, l1, strlen(l1)-1, 0, strlen(l1)-1, -1);
    }
    printTree_pre(tree);
    printf("\n");
    printTree(tree);
    return 0;
}
