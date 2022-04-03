#include <stdio.h>

void sort(int *a, int an, int *b, int bn, int *c){
    int ci=0, ai=0, bi=0;
    while(ai<an && bi<bn){
        if(a[ai]<=b[bi]){
            c[ci] = a[ai];
            ai++;
            ci++;
        }
        else if(a[ai]>b[bi]){
            c[ci] = b[bi];
            bi++;
            ci++;
        }
    }
    while(ai<an){
        c[ci]=a[ai];
        ci++;
        ai++;
    }
    while(bi<bn){
        c[ci]=b[bi];
        ci++;
        bi++;
    }
}

int main(){
    int a[]={1,3,5};
    int b[]={2,4,5,6};
    int c[]={0,0,0,0,0,0,0};
    sort(a, 3, b, 4, c);
    for(int i=0; i<7; i++){
        printf("%d,", c[i]);
    }

    return 0;
}
