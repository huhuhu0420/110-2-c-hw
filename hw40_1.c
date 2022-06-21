#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    char data;
    struct node_s *left, *right;
} node_t;
typedef node_t* nodep_t;

void printTree (nodep_t tree) {
    int head = 0, tail = 0;
    nodep_t current, queue[100];
    queue[tail] = tree;
    while (1) {
        current = queue[head];
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

void printTree_pre (nodep_t tree) {
    printf("%c", tree->data);
    if (tree->left != NULL)  printTree_pre(tree->left);
    if (tree->right != NULL)  printTree_pre(tree->right);
}

void printTree_mid (nodep_t tree) {
    if (tree->left != NULL)  printTree_mid(tree->left);
    printf("%c", tree->data);
    if (tree->right != NULL)  printTree_mid(tree->right);
}

void printTree_post (nodep_t tree) {
    if (tree->left != NULL)  printTree_post(tree->left);
    if (tree->right != NULL)  printTree_post(tree->right);
    printf("%c", tree->data);
}

void p_process (nodep_t *tree, char *pList, char *iList, int p_index, int start, int end, int dir) {
    int i;
    nodep_t newNode = malloc(sizeof(node_t));
    for (i=start; i<=end; i++) {
        if (pList[p_index] == iList[i])  break;
    }
    newNode->data = pList[p_index];
    newNode->left = NULL;
    newNode->right = NULL;
    if (dir == -1)  (*tree) = newNode;
    else if (dir == 0) {
        (*tree)->left = newNode;
    }
    else if (dir == 1) {
        (*tree)->right = newNode;
    }
    if (start >= end)  return;
    if (start <= i-1 )
        p_process(&newNode, pList, iList, p_index+1, start, i-1, 0);
    if (i+1 <= end)
        p_process(&newNode, pList, iList, p_index-start+i+1, i+1, end, 1);
}

void o_process (nodep_t *tree, char *oList, char *iList, int o_index, int start, int end, int dir) {
    int i;
    nodep_t newNode = malloc(sizeof(node_t));
    for (i=start; i<=end; i++) {
        if (oList[o_index] == iList[i])  break;
    }
    newNode->data = oList[o_index];
    newNode->left = NULL;
    newNode->right = NULL;
    if (dir == -1)  (*tree) = newNode;
    else if (dir == 0) {
        (*tree)->left = newNode;
    }
    else if (dir == 1) {
        (*tree)->right = newNode;
    }
    if (start >= end)  return;
    if (start <= i-1 )
        o_process(&newNode, oList, iList, o_index-end+i-1, start, i-1, 0);
    if (i+1 <= end)
        o_process(&newNode, oList, iList, o_index-1, i+1, end, 1);
}

int main () {
    char type0, type1, list0[20], list1[20], pList[20], oList[20], iList[20];
    nodep_t tree;
    scanf("%c", &type0);
    getchar();
    scanf("%s", list0);
    scanf("%c", &type1);
    getchar();
    scanf("%s", list1);
    printf("%s\n", list0);
    printf("%s\n", list1);
    o_process(&tree, list0, list1, 8, 0, 8, -1);
    printTree(tree);
    printf("\n");
    printTree_pre(tree);
    printf("\n");
    printTree_post(tree);
    printf("\n");
    printTree_mid(tree);
    return 0;
}
