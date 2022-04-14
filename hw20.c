#include <stdio.h>

typedef struct dice_s {
    int top;
    int front;
    int right;
}dice_t;

dice_t rollBack (dice_t dice) {
    int back = 7 - dice.front;
    dice.front = dice.top;
    dice.top = back;
    return dice;
}

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

dice_t rollLeft (dice_t dice) {
    int down = 7 - dice.top;
    dice.top = dice.right;
    dice.right = down;
    return dice;
}

dice_t roll (dice_t *dice, int ins, int i) {
    if (ins == 1) {
        dice[i] = rollFront(dice[i]);
    }
    else if (ins == 2) {
        dice[i] = rollBack(dice[i]);
    }
    else if (ins == 3) {
        dice[i] = rollRight(dice[i]);
    }
    else if (ins == 4) {
        dice[i] = rollLeft(dice[i]);
    }
    return dice[i];
}

int compute1 (int *point) {
    int i;
    for (i=6; i>=1; i--) {
        if (point[i] == 2) break;
    }
    return i*2;
}

int compute2 (int *point) {
    int score=0;
    for (int i=6; i>=1; i--) {
        if (point[i] == 1) score+=i;
    }
    return score;
}


int getScore (dice_t *dice) {
    int i, point[7] = {0};
    int twoN=0, oneN=0;
    for (i=0; i<4; i++) {
        point[dice[i].top] += 1;
    }
    for (i=1; i<=6; i++) {
        if (point[i] == 4) return 18;
        else if (point[i] == 3)  return 0; 
        else if (point[i] == 1)  oneN++;
        else if (point[i] == 2)  twoN++;
    }
    if (oneN == 4 )  return 0;
    else if (twoN == 2)  return compute1(point);
    else if (twoN == 1)  return compute2(point);
}

int main () {
    dice_t dice[4]; 
    int i, n, ins0, ins1, ins2, ins3, score=0;
    for (i=0; i<4; i++) {
        dice[i].top = 1;
        dice[i].front = 4;
        dice[i].right = 2;
    }

    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d %d %d %d", &ins0, &ins1, &ins2, &ins3);
        roll(dice, ins0, 0);
        roll(dice, ins1, 1);
        roll(dice, ins2, 2);
        roll(dice, ins3, 3);
    }

    score = getScore(dice);
    printf("%d", score);

    return 0;
}

