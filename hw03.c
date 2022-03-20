#include <stdio.h>

int main(){
    int firstM, secondM, hourSallery, leastMoney, totalSallery;
    int temp;
    float tax, insurance, remain;

    scanf("%d", &firstM);
    scanf("%d", &secondM);
    scanf("%d", &hourSallery);
    scanf("%d", &leastMoney);
    
    totalSallery = (firstM + secondM) * hourSallery;
    tax = totalSallery * 0.08;
    temp = tax * 10;
    tax = temp / 10;
    insurance = leastMoney * 0.05;
    temp = insurance * 10;
    insurance = temp / 10;
    remain = totalSallery - tax - insurance;
    
    printf("%.1f\n%.1f\n%.1f\n", remain, insurance, tax);

    return 0;
}