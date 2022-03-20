#include <stdio.h>
#include <stdlib.h>

typedef struct node_s{
    int data[11];
    struct node_s *next;
}node_t;
typedef node_t* nodep_t;

nodep_t createNode(int *data){
    nodep_t newNode;
    int i;
    newNode = (nodep_t)malloc(sizeof(node_t));
    for(i=0; i<11; i++){
        newNode->data[i] = data[i];
    }
    newNode->next = NULL;
    return newNode;
}

void printNode(nodep_t p){
    nodep_t current = p;
    int i;
    while(current != NULL){
        for(i=0; i<11; i++){
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
    int i=10;
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

int getCountSum(int num){
    int i, countSum=0, count=0;
    for(i=0; i<=num; i++){
        count = 0;
        count = getCount(i, count);
        //printf("%d count:%d\n", i, count);
        countSum += count;
    }
    return countSum;
}

int main(){
    nodep_t p = NULL;
    int data[11], flag=0, countSum=0, num=0;
    char input[9];
    while(flag != -1){
        scanf("%s", input);
        scanf("%d", &flag);
        num = transDec(input);
        //printf("%d\n", num);
        countSum = getCountSum(num);
        //printf("%d\n", countSum);
        transBi(data, countSum);
        p = insertFromBack(p, data);
    }
    printNode(p);

    return 0;
}
