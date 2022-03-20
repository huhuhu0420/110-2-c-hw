#include <stdio.h>

float transPoint(char card[2]){
    if(card[0] == 'J' || card[0] == 'Q' || card[0] == 'K')  return 0.5;
    else if(card[0] == 'A')  return 1;
    else if(card[0] == '1')  return 10;
    else  return card[0]-'0'; 
}

void compareCard(float cardA, float cardB){
    if(cardA > 10.5)  cardA = 0;
    if(cardB > 10.5)  cardB = 0;
    printf("%.1f\n", cardA);
    printf("%.1f\n", cardB);
    if(cardA > cardB)  printf("A wins.\n");
    else if(cardA < cardB)  printf("B wins.\n");
    else  printf("It's a tie.\n");
   
}

int main(){
    float cardA=0, cardB=0, point;
    char card[2];
    int i;

    for(i=0; i<3; i++){
        scanf("%s", card);
        point = transPoint(card);
        cardA += point;
    }
    for(i=0; i<3; i++){
        scanf("%s", card);
        point = transPoint(card);
        cardB += point;
    }
    compareCard(cardA, cardB);

    return 0;
}
