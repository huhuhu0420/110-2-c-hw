#include <stdio.h>
#include <math.h>

double f1 (double x, double a) {
    double temp = pow(a - (x * x), 0.5L);
    return temp;
}

double f2 (double x, double a) {
    double temp = (a * pow(x, 3.0L) + 7.0L * x) / 
        pow(a + x, 0.5L);
    return temp;
}

double getArea (int p, int q, double n, double a, double (*f)(double, double)) {
    double temp=0, area = (double)(q - p)/(2.0L*n), x = (double)(q - p)/n;
    temp += fabs((*f)(p, a));
    double i=1.0L;
    //printf("x=%lf\n", x);
    while (p+i*x < q) {
        //printf("p+i*x=%lf\n ", p+i*x);
        temp += fabs((*f)(p+i*x, a)) * 2.0L;
        i++;
    }
    temp += fabs((*f)(q, a));
    return temp * area;
}

void process (int type) {
    double a, area, pre_area=0.0L, n=1.0L;
    int p, q, err;
    //a = 4; p = -1, q = 5, err = 6;
    scanf("%lf", &a);
    scanf("%d", &p);
    scanf("%d", &q);
    scanf("%d", &err);
    double (*f)(double, double);
    if (type == 1)  f = f1;
    else if (type == 2)  f = f2;
    while (1) {
        area = getArea(p, q, n, a,f);
        if (fabs(area - pre_area) < pow(10.0L, -1*err) && fabs(area - pre_area)>0.0L) break;
        pre_area = area;
        n = n * 2.0L;
    }
    printf("%.12lf\n", area);
}

int main () {
    int type;
    while (1) {
        scanf("%d", &type);
        if (type == 0)  break;
        process(type);
    }

    return 0;
}
