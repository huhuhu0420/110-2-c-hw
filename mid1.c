#include <stdio.h>

void one2n (int n){
    for (int i=1; i<=n; i++) {
        printf("%d", i);
    }
}

void n2one (int n){
    for (int i=n; i>=1; i--) {
        printf("%d", i);
    }
}

void tri (int n) {
    for (int i=1; i<=n; i++) {
        one2n(i);
        printf("\n");
    }
}

void tri2 (int n) {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            printf("%d", i);
        }
        printf("\n");
    }
}

void rev_tri (int n) {
    for (int i=n; i>=1; i--) {
        n2one(i);
        printf("\n");
    }
}

void case1 (int n) {
    tri(n);
    rev_tri(n);
    tri2(n);
}

void tri_2 (int n) {
    for (int i=1; i<=n; i++) {
        one2n(i);
        n2one(i-1);
        printf("\n");
    }
}

void two2n (int n) {
    for (int i=2; i<=n; i++) {
        printf("%d", i);
    }
}

void tri_top (int n) {
    for (int i=1; i<n; i++) {
        n2one(i);
        two2n(i);
        printf("\n");
    }
}

void tri_down (int n) {
    for (int i=n-1; i>=1; i--) {
        n2one(i);
        two2n(i);
        printf("\n");
    }
}

void case2 (int n) {
    tri_2(n);
    tri_top(n);
    tri_down(n);
}

int main () {
    case2(5);

    return 0;
}
