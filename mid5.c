#include <stdio.h>

typedef struct player_c{
    int times;
    int hit[9];
    int hasHit;
    int homebase;
}player_t;

void printPlayer(player_t *player, int n){
    printf("%d\t", player[n].times);
    for(int i=0; i<player[n].times; i++){
        printf("%d", player[n].hit[i]);
    }
    printf("\t");
    printf("%d\t", player[n].hasHit);
    printf("%d\t", player[n].homebase);
}

int getScore(int base){
    int score=0;
    //printf("scorebase = %d\t", base);
    while(base != 0){
        score += base & 1;
        base = base >> 1;
    }
    return score;
}

int runBase(int *base, int n){
    int score;
    *base = (*base) << n;
    *base = (*base) | (1 << (n-1));
    printf("base = %o\t", *base);
    score = getScore((*base) >> 3);
    printf("score = %d\t", score);
    *base = (*base) & 7;
    return score;
}

void transInput(player_t *player, char *input, int i){
    int j=1, round=0;
    player[i].times = input[0] - '0';
    while(input[j] != '\0'){
        if(input[j] == ' '){
            j++;
            continue;
        }
        if(input[j] == 'O')  player[i].hit[round] = 0;
        else if(input[j] == 'H')  player[i].hit[round] = 4;
        else  player[i].hit[round] = input[j] - '0';
        j++;
        round++;
    }
}

int main(){
    player_t player[9];
    int hitTimes, i, j, outTotal, score=0, base=0, outNum=0, round=0;
    int queue[200], front=-1, back=-1;
    char input[20];
    
    for(i=0; i<9; i++){
        scanf("%[^\n]s", input);
        getchar();
        transInput(player, input, i);
        //printPlayer(player, i);
    }
    scanf("%d", &outTotal);

    for(i=0; i<9; i++){
        player[i].hasHit = 0;
        player[i].homebase = 0;
    }

    i = 0;
    
    
    while(outNum < outTotal){
        printf("----%d %d |\t", i, player[i].hit[round]);
        if(player[i].hit[round] == 0){
            outNum ++;
            if(outNum % 3 == 0)  base = 0;
        }
        else{
            score += runBase(&base, player[i].hit[round]);
            player[i].hasHit +=1;
        }
        i++;
        if(i == 9){
            i = 0;
            round ++;
        }
        printf("total score = %d\n", score);
    }
    printf("--%d", score);
    return 0;
}
