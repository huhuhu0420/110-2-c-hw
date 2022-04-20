#include <stdio.h>

typedef struct player_s {
    int to_home;
    int hit_time;
    int has_hit;
    char hit[10];
    int base;
} player_t;

void run (player_t *player, int i, int n) {
    for (int i=0; i<9; i++) {
        if (player[i].base != 0)  player[i].base+=n;
    }
    player[i].base += n;
    player[i].has_hit += 1;
}

void clear (player_t *player) {
    for (int i=0; i<9; i++) {
        player[i].base = 0;
    }
}

int getScore (player_t *player) {
    int score = 0;
    for (int i=0; i<9; i++) {
        if (player[i].base >= 4) {
            player[i].base = 0;
            player[i].to_home += 1;
            score += 1;
        }
    }
    return score;
}

int main () {
    int i, j, score=0, out=0, total=0, round=0, n=0;
    player_t player[9];

    for (i=0; i<9; i++) {
        player[i].base = 0;
        player[i].hit_time = 0;
        player[i].to_home = 0;
        player[i].has_hit = 0;
    }

    for (i=0; i<9; i++) {
        scanf("%d ", &player[i].hit_time);
        for (j=0; j<player[i].hit_time; j++) {
            scanf("%c ", &player[i].hit[j]);
        }
        player[i].hit[j] = '\0';
    }
    scanf("%d", &total);

    for (i=0; i<9; i++) {
        printf("%s", player[i].hit);
        printf("\n");
    }
    i = 0;
    while (out < total) {
        if (player[i].hit[round] == 'H')  n = 4;
        else if (player[i].hit[round] == 'O')  n = 0;
        else n = player[i].hit[round] - '0';
        printf("%d, ", n);
        if (n == 0) {
            out ++;
            if (out % 3 == 0)  clear(player);
        }
        else {
            run(player, i, n);
            score += getScore(player);
        }
        if (i == 8) {
            i = 0;
            round ++;
        }
        else  i++;
    }
    printf("%d\n", score);
    for (int i=0; i<3; i++) {
        printf("%d %d %d\n", i+1, player[i].has_hit, player[i].to_home);
    }

    return 0;
}
