#include <stdio.h>

int strcmp_rec (char *a, char *b) {
    if (a[0] != b[0]) {
        return 1;
    }
    else if (a[0] == '\0' && b[0] == '\0') {
        return 0;
    }
    else {
        return strcmp_rec(a+1, b+1);
    }
}

int main () {
    char a[] = "abed";
    char b[] = "abcd";
    printf("%d\n", strcmp_rec(a, b));

    return 0;
}
