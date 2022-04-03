#include <stdio.h>

typedef struct frac_s{
    int property;
    int integer;
    int numerator;
    int denominator;
}frac_t;

void printFrac(frac_t f){
    if(f.numerator == 0){
        if(f.integer == 0){
            printf("%d", 0);
        }
        else{
            printf("%d", f.property * f.integer);
        }
    }
    else if(f.integer != 0){
        printf("%d", f.property * f.integer);
        printf("(%d/%d)", f.numerator, f.denominator);
    }
    else{
        printf("%d/%d", f.numerator * f.property , f.denominator);
    }
}

int isZero(frac_t f){
    if(f.numerator != 0 || f.integer !=0){
        return 0;
    }
    return 1;
}

int isOne(frac_t f){
    if(f.integer == 1 && f.property == 1 && f.numerator == 0)  return 1;
    if(f.integer == 1 && f.property == -1 && f.numerator == 0)  return -1;
    return 0;
}

void printLine(frac_t m, frac_t b){
    printf("y=");
    if(isZero(m) != 1 && isOne(m) == 0){
        printFrac(m);
        printf("x");
    }
    else if(isOne(m) == 1){
        printf("x");
    }
    else if(isOne(m) == -1){
        printf("-x");
    }
    if(b.property == 1 && isZero(b) != 1)  printf("+");
    if(isZero(m) == 1 || isZero(b) != 1) printFrac(b);
}

int getGCD(int a, int b){
    if(b == 0){
        return a;
    }
    else{
        return getGCD(b, a%b);
    }
}

frac_t becomePretty(frac_t ans){
    int gcd;
    if(ans.numerator < 0){
        ans.property *= (-1);
        ans.numerator *= (-1);
    }
    if(ans.denominator < 0){
        ans.property *= (-1);
        ans.denominator *= (-1);
    }
    ans.integer = ans.numerator / ans.denominator;
    ans.numerator = ans.numerator % ans.denominator;
    gcd = getGCD(ans.numerator, ans.denominator);
    ans.numerator /= gcd;
    ans.denominator /= gcd;
    // printf("%d %d %d %d\n", ans.property, ans.integer, ans.numerator, ans.denominator);
    return ans;
}

int main(){
    frac_t m = {1, 0, 0, 0}, b = {1, 0, 0, 0};
    int x1, x2, y1, y2;
    
    scanf("%d,%d", &x1, &y1);
    scanf("%d,%d", &x2, &y2);

    m.numerator = y1 - y2;
    m.denominator = x1 - x2;
    b.numerator = x2 * y1 - x1 * y2;
    b.denominator = x2 - x1;

    m = becomePretty(m);
    b = becomePretty(b);

    // printFrac(m);
    // printf("\n");
    // printFrac(b);
    // printf("\n");
    printLine(m, b);

    return 0;
}
