#include <stdio.h>

typedef struct dice_s {
    int top;
    int front;
    int right;
}dice_t;

dice_t rollFront (dice_t dice) {
    int down = 7 - dice.top;
    dice.top = dice.front;
    dice.front = down;
    return dice;
}

dice_t rollRight (dice_t dice) {
    int left = 7 - dice.right;
    dice.right = dice.top;
    dice.top = left;
    return dice;
}

dice_t roll (dice_t *dice, int i, int ins) {
    if (ins == 1) {
        dice[i] = rollFront(dice[i]);
    }
    else if (ins == 2) {
        dice[i] = rollRight(dice[i]);
    }
    return dice[i];
}

int compute (dice_t *dice) {
    if (dice[0].top == dice[1].top) {
        return 0;    
    }
    else {
        return dice[0].top + dice[1].top;
    }
}

int getScore () {
    dice_t dice[2];
    int i, n=0, score=0, ins0, ins1;
    for (i=0; i<2; i++) {
        dice[i].top = 1;
        dice[i].front = 4;
        dice[i].right = 2;
    }
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d %d", &ins0, &ins1);
        dice[0] = roll(dice, 0, ins0);
        dice[1] = roll(dice, 1, ins1);
    }
    printf("%d %d %d %d %d %d", dice[0].front, dice[0].top, 7-dice[0].front, 
           7-dice[0].top, dice[0].right, 7-dice[0].right);
    printf("\n");
    printf("%d %d %d %d %d %d", dice[1].front, dice[1].top, 7-dice[1].front, 
           7-dice[1].top, dice[1].right, 7-dice[1].right);
    score = compute(dice);

    return score;
}

int main () {
    int scoreA, scoreB;
    scoreA = getScore();
    scoreB = getScore();

    printf("%d %d\n", scoreA, scoreB);
    if (scoreA == scoreB) printf("tie\n");
    else if (scoreA > scoreB) printf("a\n");
    else printf("b\n");

    return 0;
}
