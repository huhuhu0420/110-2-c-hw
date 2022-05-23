#include <stdio.h>
#include <string.h>

void Reverse (char star[][100], int width, int height) {
    char starcpy[100][100];
    int i, j;
    for (i=0; i<height; i++) {
        for (j=0; j<width; j++) {
            starcpy[i][j] = star[i][j];
        }
        starcpy[i][j] = '\0';
    }
    for (i=0; i<height; i++) {
        for (j=0; j<width; j++) {
            star[i][j] = starcpy[i][width-1-j];
        }
        star[i][j] = '\0';
    }
}

void Inverse(char input[][100],int width,int height){                                                    
    int i,j;           
    for(i=0;i<height/2;i++){  
        for(j=0;j<width;j++){  
            char tmp;  
            tmp=input[i][j];  
            input[i][j]=input[height-i-1][j];                                         
            input[height-i-1][j]=tmp;                                                   
        }                                                                               
    }                                                                                   
}

void process (char *name, int width, int height, char *ins) {
    char star[100][100];
    for (int i=0; i<height; i++) {
        scanf("%s", star[i]);
    }
    if (strcmp(ins, "R") == 0)  Reverse(star, width, height);
    else if (strcmp(ins, "I") == 0)  Inverse(star, width, height);
    else if (strcmp(ins, "IR") == 0) {
        Reverse(star, width, height); 
        Inverse(star, width, height);
    }
    printf("%s\n", name);
    for (int i=0; i<height; i++) {
        printf("%s", star[i]);
        printf("\n");
    }
}

int main () {
    int width=0, height=0;
    char name[100], ins[3];
    while (scanf("%s %d %d %s", name, &width, &height, ins) != EOF)
        process(name, width, height, ins);
    return 0;
}

/*
將星座上下左右翻轉

input:

ENDEAVOURS 40 15 IR
_____________________./o._______________
___________________./sssso-_____________
_________________`:osssssss+-___________
_______________`:+sssssssssso/._________
_____________`-/ossssssssssssso/._______
__________`-/+sssssssssssssssso+:`______
_________`-:/+sssssssssssssssssso+/.____
_______`.://osssssssssssssssssssso++-___
______.://+ssssssssssssssssssssssso++:__
____.:///ossssssssssssssssssssssssso++:_
__`:////ssssssssssssssssssssssssssso+++.
`-////+ssssssssssssssssssssssssssso++++-
_`..-+oosssssssssssssssssssssssso+++++/`
____./++++++++++++++++++++++++++++++/:._
__`:::::::::::::::::::::::::------``____

output:

ENDEAVOURS
____``------:::::::::::::::::::::::::`__
_.:/++++++++++++++++++++++++++++++/.____
`/+++++ossssssssssssssssssssssssoo+-..`_
-++++osssssssssssssssssssssssssss+////-`
.+++osssssssssssssssssssssssssss////:`__
_:++ossssssssssssssssssssssssso///:.____
__:++osssssssssssssssssssssss+//:.______
___-++osssssssssssssssssssso//:.`_______
____./+ossssssssssssssssss+/:-`_________
______`:+ossssssssssssssss+/-`__________
_______./ossssssssssssso/-`_____________
_________./ossssssssss+:`_______________
___________-+ssssssso:`_________________
_____________-ossss/.___________________
_______________.o/._____________________

*/
