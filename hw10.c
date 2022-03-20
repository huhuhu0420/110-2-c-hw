#include <stdio.h>
#include <stdlib.h>

typedef struct node_s{
    int data[4];
    struct node_s *next;
}node_t;
typedef node_t* nodep_t;

nodep_t createNode(int *data){
    nodep_t newNode;
    int i;
    newNode = (nodep_t)malloc(sizeof(node_t));
    for(i=0; i<4; i++){
        newNode->data[i] = data[i];
    }
    newNode->next = NULL;
    return newNode;
}

void printNode(nodep_t p){
    nodep_t current = p;
    int i;
    while(current != NULL){
        for(i=0; i<4; i++){
            printf("%d", current->data[i]);
        }
        if(current->next != NULL)  printf("\n");
        current = current->next;
    }
}

nodep_t insertFromBack(nodep_t p, int *data){
    nodep_t current;
    nodep_t newNode = createNode(data);
    if(p == NULL){
        p = newNode;
    }
    else{
        current = p;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
    return p;
}

void transBi(int *data, int count){
    int i=3;
    while(count != 0){
        data[i] = count % 2;
        count /=2;
        i--;
    }
    while(i >= 0){
        data[i] = 0;
        i--;
    }
}

int transDec(char *input){
    int i, num=0, count=1;
    for(i=7; i>=0; i--){
        num += (input[i] - '0') * count;
        count *= 2;
    }
    return num;
}

int getCount(int num, int count){
    if(num==1 || num==0){
        return count;
    }
    else{
        if(num%2 == 1)
            num = (num + 1) / 2;
        else
            num = num / 2;
        return getCount(num, count+1); 
    }
}

int main(){
    nodep_t p = NULL;
    int data[4], flag=0, count=0, num=0;
    char input[9];
    while(flag != -1){
        count = 0;
        scanf("%s", input);
        scanf("%d", &flag);
        num = transDec(input);
        count = getCount(num, count);
        transBi(data, count);
        p = insertFromBack(p, data);
    }
    printNode(p);

    return 0;
}
