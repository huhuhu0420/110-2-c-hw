#include <stdio.h>
#include <math.h>

#define ShapeText(TYPE) char name[10];\
double (*perimeter)(struct TYPE);\
double (*area)(struct TYPE)

typedef struct shape_s {
    ShapeText(shape_s);
} shape_t;

typedef struct circle_s {
    ShapeText(circle_s);
    double radius;
} circle_t;

double circleArea (circle_t c) {
    return 3.14 * c.radius * c.radius;
}

double circlePeri (circle_t c) {
    return 3.14 * 2 * c.radius;
}

circle_t newCircle (double r) {
    circle_t c;
    c.radius = r;
    c.area = circleArea;
    c.perimeter = circlePeri;
    return c;
}

typedef struct rec_s{
    ShapeText(rec_s);
    double l;
    double w;
} rec_t;

double recArea (rec_t r) {
    return r.l * r.w;
}

double recPeri (rec_t r) {
    return 2 * (r.l + r.w);
}

rec_t newRec (double l, double w) {
    rec_t r;
    r.l = l;
    r.w = w;
    r.area = recArea;
    r.perimeter = recPeri;
    return r;
}

typedef struct square_s {
    ShapeText(square_s);
    double edge;
} square_t;

double squareArea (square_t s) {
    return s.edge * s.edge;
}

double squarePeri (square_t s) {
    return 4 * s.edge;
}

square_t newSquare (double e) {
    square_t s;
    s.edge = e;
    s.perimeter = squarePeri;
    s.area = squareArea;
    return s;
}

typedef struct tri_s {
    ShapeText(tri_s);
    double e1, e2, e3;
} tri_t;

double triArea (tri_t t) {
    double temp = (t.e1 + t.e2 + t.e3) / 2;
    double area = temp * (temp - t.e1) * (temp - t.e2) * (temp - t.e3);
    area = sqrt(area);
    return area;
}

double triPeri (tri_t t) {
    return t.e1 + t.e2 + t.e3;
}

tri_t newTri (double e1, double e2, double e3) {
    tri_t t;
    t.e1 = e1;
    t.e2 = e2;
    t.e3 = e3;
    t.area = triArea;
    t.perimeter = triPeri;
    return t;
}

int main (){
    int n;
    double t1, t2, t3;
    char type;
    double total_peri = 0, total_area = 0;
    double peri, area;
    scanf("%d", &n);
    getchar();
    for (int i=0; i<n; i++) {
        scanf("%c", &type);
        getchar();
        if (type == 'C') {
            circle_t c;
            scanf("%lf", &t1);
            getchar();
            c = newCircle(t1);
            area = circleArea(c);
            peri = circlePeri(c);
            total_area += area;
            total_peri += peri;
            printf("%.2lf %.2lf\n", area, peri);
        }
        else if (type == 'S') {
            square_t s;
            scanf("%lf", &t1);
            getchar();
            s = newSquare(t1);
            area = squareArea(s);
            peri = squarePeri(s);
            total_area += area;
            total_peri += peri;
            printf("%.2lf %.2lf\n", area, peri);
        }
        else if (type == 'R') {
            rec_t r;
            scanf("%lf %lf", &t1, &t2);
            getchar();
            r = newRec(t1, t2);
            area = recArea(r);
            peri = recPeri(r);
            total_area += area;
            total_peri += peri;
            printf("%.2lf %.2lf\n", area, peri);
        }
        else if (type == 'T') {
            tri_t t;
            scanf("%lf %lf %lf", &t1, &t2, &t3);
            getchar();
            t = newTri(t1, t2, t3);
            area = triArea(t);
            peri = triPeri(t);
            total_area += area;
            total_peri += peri;
            printf("%.2lf %.2lf\n", area, peri);
        }
    }
    printf("%.2lf %.2lf\n", total_area, total_peri);
    printf("%lf %lf", total_area, total_peri);

    return 0;
}
