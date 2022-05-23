#include <stdio.h>
#include <string.h>
#include <math.h>
#define ShapeText(TYPE) char name[10];\
double (*perimeter)(struct TYPE*);\
double (*area)(struct TYPE*)

typedef struct shape_s {
    ShapeText(shape_s);
} shape_t;

typedef struct circle_s {
    ShapeText(circle_s);
    double radius;
} circle_t;

double circlePerimeter (circle_t *obj) {
    return 2 * 3.14 * obj->radius;
}

double circleArea (circle_t *obj) {
    return 3.14 * obj->radius * obj->radius;
}

void circleNew (circle_t *obj) {
    strcpy(obj->name, "circle");
    obj->perimeter = circlePerimeter;
    obj->area = circleArea;
}

typedef struct rect_s {
    ShapeText(rect_s);
    double length;
    double width;
} rect_t;

double rectPerimeter (rect_t *obj) {
    return 2 * (obj->length + obj->width);
}

double rectArea (rect_t *obj) {
    return obj->width * obj->length;
}

void rectNew (rect_t *obj) {
    strcpy(obj->name, "rect");
    obj->perimeter = rectPerimeter;
    obj->area = rectArea;
}

typedef struct square_s{
    ShapeText(square_s);
    double edge;
} square_t;

double squarePerimeter (square_t *obj) {
    return 4 * obj->edge;
}

double squareArea (square_t *obj) {
    return obj->edge * obj->edge;
}

void squareNew (square_t *obj) {
    strcpy(obj->name, "square");
    obj->perimeter = squarePerimeter;
    obj->area = squareArea;
}

typedef struct tri_s{
    ShapeText(tri_s);
    double edge1;
    double edge2;
    double edge3;
} tri_t;

double triPerimeter (tri_t *obj) {
    return obj->edge1 + obj->edge2 + obj->edge3;
}

double triArea (tri_t *obj) {
    double p = (obj->edge1 + obj->edge2 + obj->edge3)/2;
    double area = p * (p-obj->edge1) * (p-obj->edge2) * (p-obj->edge3);
    return sqrt(area);
}

void triNew (tri_t *obj) {
    strcpy(obj->name, "tri");
    obj->perimeter = triPerimeter;
    obj->area = triArea;
}

int main () {
    int n, i;
    char type;
    double area, perimeter;
    double tArea=0.0, tPerimeter=0.0;
    
    // shape_t s;
    // circle_t c;
    // printf("%d %d", sizeof(&c), sizeof(&s));

    scanf("%d ", &n);
    for (i=0; i<n; i++) {
        scanf("%c", &type);
        getchar();
        if (type == 'C') {
            circle_t c;
            circleNew(&c);
            scanf("%lf", &c.radius);
            getchar();
            area = c.area(&c);
            perimeter = c.perimeter(&c);
            printf("%.2lf %.2lf\n", perimeter, area);
            tArea += area;
            tPerimeter += perimeter;
        }
        else if (type == 'R') {
            rect_t c;
            rectNew(&c);
            scanf("%lf %lf", &c.length, &c.width);
            getchar();
            area = c.area(&c);
            perimeter = c.perimeter(&c);
            printf("%.2lf %.2lf\n", perimeter, area);    
            tArea += area;
            tPerimeter += perimeter;
        }
        else if (type == 'S') {
            square_t c;
            squareNew(&c);
            scanf("%lf", &c.edge);
            getchar();
            area = c.area(&c);
            perimeter = c.perimeter(&c);
            printf("%.2lf %.2lf\n", perimeter, area);    
            tArea += area;
            tPerimeter += perimeter;
        }
        else if (type == 'T') {
            tri_t c;
            triNew(&c);
            scanf("%lf %lf %lf", &c.edge1, &c.edge2, &c.edge3);
            getchar();
            area = c.area(&c);
            perimeter = c.perimeter(&c);
            printf("%.2lf %.2lf\n", perimeter, area);    
            tArea += area;
            tPerimeter += perimeter;
        }
    }
    printf("%.2lf %.2lf",tPerimeter, tArea);

    return 0;
}
