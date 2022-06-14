#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node_s {
    char data;
    struct node_s *left, *right;
} node_t;
typedef node_t* nodep_t;

nodep_t create(char data) {
    nodep_t newNode = malloc(sizeof(node_t));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// void uildPI(nodep_t *p,int start,int end,char* mid,char* front,int front_now,int sign){
//     int i;
//     printf("%d %d-> ", start, end);
//     for(int i=start;i<=end;i++){
//         if(mid[i] == front[front_now]){
//             break;
//         }
//     }
//     nodep_t newNode = create(mid[i]);
//     printf("%c",newNode->data);
//     if(sign == -1){
//         (*p) = newNode;
//     }
//     else if(sign == 0){
//         (*p)->left = newNode;
//     }
//     else if(sign == 1){
//         (*p)->right = newNode;
//     }
//
//     if( start == end){
//         return;
//     }
//     if(i-1 >= start){
//         buildPI(&newNode,start,i-1,mid,front,front_now+1,0);
//     }
//     if(i+1 <= end){
//         buildPI(&newNode,i+1,end,mid,front,front_now-start+i+1,1);
//     }
// }
//
void buildPI (nodep_t *vertex, int start, int end, char *pList, char *iList, int p_index, int direct) {
    int i;
    printf("%d %d-> ", start, end);
    printf("p_index=%d, ", p_index);
    for (i=start; i<=end; i++) {
        if (iList[i] == pList[p_index]) {
            printf("i=%d: ", i);
            break;
        }
    }
    nodep_t newNode = create(iList[i]);
    //printf("%c",newNode->data);
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
        buildPI(&newNode, start, i-1, pList, iList, p_index+1, 0);
    if (i+1 <= end)
        buildPI(&newNode, i+1, end, pList, iList, p_index+i-start+1, 1);
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

int main(){
    char s[100],temp1,temp2,mid[100],front_back[100];
    int mid_index=0;
    nodep_t tree=NULL;
    scanf("%c",&temp1);
    getchar();
    gets(s);
    if(temp1 == 'P' || temp1 == 'O'){
        strcpy(front_back,s);
    }
    else{
        strcpy(mid,s);
    }
    scanf(" %c",&temp2);
    getchar();
    gets(s);
    if(temp2 == 'P' || temp2 == 'O'){
        strcpy(front_back,s);
    }
    else{
        strcpy(mid,s);
    }
    printf("%s,%s\n",mid,front_back);
    if(temp1 == 'P' || temp2 == 'P'){
        buildPI(&tree,0,strlen(front_back)-1,mid,front_back,0,-1);
        printTree(tree);
    }

}
