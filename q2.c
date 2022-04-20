#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct fract fract;
struct fract {
    int neg;
    int num;
    int den;
};
fract input()
{
    fract k;
    int id = 0, di = 0;
    char s[20];
    gets(s);
    int w = strlen(s);
    if (s[0] == '-')
        k.neg = 1, id = 1;
    else
        k.neg = 0;
    int sum = 0;
    while (id != w) {
        if (s[id] == '/') {
            k.num = sum;
            sum = 0;
        } else if (s[id] == '(') {
            di = sum;
            sum = 0;
        } else if (s[id] == ')') {
            k.num += di * sum;
        } else
            sum = sum * 10 + (s[id] - '0');
        id++;
    }
    if (sum == 0)
        k.neg = 2;
    else
        k.den = sum;
    return k;
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    while (1) {
        char c, y;
        fract a = input();
        fract b = input();
        scanf("%c", &c);
        getchar();
        scanf("%c", &y);
        getchar();
        if (a.neg == 2 || b.neg == 2) {
            puts("ERROR");
            continue;
        }
        if (a.neg == 1)
            a.num = -a.num;
        if (b.neg == 1)
            b.num = -b.num;
        if (c == '+') {
            int temp = a.den;
            a.den *= b.den;
            a.num *= b.den;
            b.num *= temp;
            b.den *= temp;
            a.num += b.num;
        } else if (c == '-') {
            int temp = a.den;
            a.den *= b.den;
            a.num *= b.den;
            b.num *= temp;
            b.den *= temp;
            a.num -= b.num;
        } else if (c == '*') {
            a.den *= b.den;
            a.num *= b.num;
        } else if (c == '/') {
            a.den *= b.num;
            a.num *= b.den;
        }
        int g = gcd(a.num, a.den);
        a.num /= g;
        a.den /= g;
        if (a.den < 0) {
            a.num *= -1;
            a.den *= -1;
        }
        if (a.num == 0)
            puts("0");
        else if (a.den == 1) {
            printf("%d\n", a.num);
        } else if (abs(a.num) < abs(a.den)) {
            printf("%d/%d\n", a.num, a.den);
        } else {
            printf("%d(", a.num / a.den);
            printf("%d/%d)\n", a.num % a.den, a.den);
        }
        if (y == 'n') {
            return 0;
        }
    }
    return 0;
}