#include <stdio.h>

typedef struct player_c{
    int times;
    int base;
    int hit[9];
    int hasHit;
    int score;
}player_t;

player_t trans (char *input, player_t player) {
    player.times = input[0] - '0';
    int index = 2;
    for (int i=0; i<player.times; i++) {
        if (input[index] == 'O')  player.hit[i] = 0;
        else if (input[index] == 'H')  player.hit[i] = 4;
        else  player.hit[i] = input[index] - '0';
        index += 2;
    }

    return player;
}

void run (player_t *player, int i, int num) {
    for (int j=0; j<9; j++) {
        if (player[j].base > 0) {
            player[j].base += num;
        }
    }
    player[i].base += num;
    player[i].hasHit += 1;
}

int getScore (player_t *player) {
    int score = 0;
    for (int i=0; i<9; i++) {
        if (player[i].base >= 4) {
            player[i].score += 1;
            player[i].base = 0;
            score += 1;
        }
    }
    return score;
}

void clear (player_t *player) {
    for (int i=0; i<9; i++) {
        player[i].base = 0;
    }
}

int main () {
    int i, out=0, outTotal=0, round=0, pIndex=0, score=0;
    player_t player[9];
    char input[20];
    for (i=0; i<9 ; i++) {
        player[i].base = 0;
        player[i].score = 0;
        player[i].hasHit = 0;
        scanf("%[^\n]s", input);
        getchar();
        player[i] = trans(input, player[i]);
    }
    scanf("%d", &outTotal);

    while (out < outTotal) {
        printf("%d %d -> ", pIndex, player[pIndex].hit[round]);
        if (player[pIndex].hit[round] == 0) {
            out++;
            if (out % 3 == 0) {
                clear(player);
            }
        } 
        else  run(player, pIndex, player[pIndex].hit[round]);
        for (int j=0; j<9; j++) {
            printf("%d ", player[j].base);
        }
        printf("\n");
        score += getScore(player);
        if (pIndex == 8) {
            pIndex = 0;
            round ++;
        }
        else  pIndex++;
    }
    printf("%d\n", score);
    for (int i=0; i<3; i++) {
        printf("%d %d %d\n", i+1, player[i].hasHit, player[i].score);
    }

    return 0;
}
