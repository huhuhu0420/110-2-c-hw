#include <stdio.h>
#include <math.h>
#define PI 3.14159

int main(){
    double r, area, perimeter;

    scanf("%lf", &r);
    area = r * r * PI;
    area = (int)(area * 1000 + 0.5) / 1000.0;
    printf("%.3lf\n", area);
    perimeter = 2 * r * PI;
    perimeter = (int)(perimeter * 1000 + 0.5) / 1000.0;
    printf("%.3lf\n", perimeter);
    
    return 0;
}

