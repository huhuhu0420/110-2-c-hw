#include <stdio.h>

typedef struct frac_s{
    int property;
    int integer;
    int numerator;
    int denominator;
}frac_t;


frac_t transFraction(char *input){
    int num=0, i=0;
    frac_t f;
    f.property = 1;
    f.integer = 0;
    while(input[i] != '\0'){
        //printf("%d:", i);
        //printf("%c\n", input[i]);
        if(input[i] == '-'){
            f.property = -1;
        }
        else if(input[i] == '/'){
            f.numerator = num;
            num = 0;
        }
        else{
            num = num * 10 + (input[i] - '0');
        }
        i++;
    }
    f.denominator = num;

    return f;
}

frac_t divideFrac(frac_t f1, frac_t f2){
    frac_t ans;
    ans.integer = 0;
    ans.property = 1;
    ans.denominator = f1.denominator * f2.numerator;
    ans.numerator = f1.numerator * f1.property * f2.denominator * f2.property;
    if(ans.numerator < 0){
        ans.property = -1;
        ans.numerator *= (-1);
    }
    return ans;
}

frac_t multFrac(frac_t f1, frac_t f2){
    frac_t ans;
    ans.integer = 0;
    ans.property = 1;
    ans.denominator = f1.denominator * f2.denominator;
    ans.numerator = f1.numerator * f1.property * f2.numerator * f2.property;
    if(ans.numerator < 0){
        ans.property = -1;
        ans.numerator *= (-1);
    }
    return ans;
}
frac_t minusFrac(frac_t f1, frac_t f2){
    frac_t ans;
    ans.integer = 0;
    ans.property = 1;
    ans.denominator = f1.denominator * f2.denominator;
    ans.numerator = f1.numerator * f1.property * f2.denominator - f2.numerator * f2.property * f1.denominator;
    if(ans.numerator < 0){
        ans.property = -1;
        ans.numerator *= (-1);
    }
    return ans;
}

frac_t plusFrac(frac_t f1, frac_t f2){
    frac_t ans;
    ans.integer = 0;
    ans.property = 1;
    ans.denominator = f1.denominator * f2.denominator;
    //printf("%d\n", ans.denominator);
    ans.numerator = f1.numerator * f1.property * f2.denominator + f2.numerator * f2.property * f1.denominator;

    if(ans.numerator < 0){
        ans.property = -1;
        ans.numerator *= (-1);
    }
    //printf("%d %d %d %d\n", ans.property, ans.integer, ans.numerator, ans.denominator);
    return ans;
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
    ans.integer = ans.numerator / ans.denominator;
    ans.numerator = ans.numerator % ans.denominator;
    gcd = getGCD(ans.numerator, ans.denominator);
    ans.numerator /= gcd;
    ans.denominator /= gcd;
    //printf("%d %d %d %d\n", ans.property, ans.integer, ans.numerator, ans.denominator);
    return ans;
}

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

void process(frac_t f1, frac_t f2, char operation){
    frac_t ans;
    if(f1.denominator == 0 || f2.denominator == 0){
        printf("ERROR");
        return;
    }
    if(operation == '+'){
        ans = plusFrac(f1, f2);
    }
    if(operation == '-'){
        ans = minusFrac(f1, f2);
    }
    if(operation == '*'){
        ans = multFrac(f1, f2);
    }
    if(operation == '/'){
        ans = divideFrac(f1, f2);
    }
    ans = becomePretty(ans);
    printFrac(ans);
}

int main(){
    frac_t f1, f2;
    char flag='y', operation, input1[12], input2[12];
    
    while(flag != 'n'){
        scanf("%s", input1);
        scanf("%s", input2);
        getchar();
        scanf("%c", &operation);
        getchar();
        scanf("%c", &flag);
        f1 = transFraction(input1);
        f2 = transFraction(input2);
        //printFrac(f1);
        //printf("\n");
        //printFrac(f2);
        //printf("\n");
        process(f1, f2, operation);
        if(flag != 'n')  printf("\n");
    }
    
    return 0;
}
