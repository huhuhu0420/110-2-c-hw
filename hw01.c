#include <stdio.h>
#include <math.h>

int main(){
  int a, b, c;
  double temp, ans1, ans2;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c); 
  temp = sqrt(b*b-4*a*c);
  //printf("%f\n", temp);
  ans1 = ((-1)*b+temp)/(2*a);
  ans2 = ((-1)*b-temp)/(2*a);
  printf("%.1f\n", ans1);
  printf("%.1f\n", ans2);
  return 0;
}
