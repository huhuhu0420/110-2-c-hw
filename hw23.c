#include <stdio.h>

typedef struct cube_s {
    int front[3][3], right[3][3], top[3][3], 
        back[3][3], left[3][3], down[3][3];
} cube_t;

/*
00 01 02
10 11 12
20 21 22

20 10 00
21 11 01
22 12 02
*/

void printSingle (int data[3][3]) {
    printf("%d %d %d    ", data[0][0], data[0][1], data[0][2]);
    printf("\n");
    printf("%d %d %d    ", data[1][0], data[1][1], data[1][2]);
    printf("\n");
    printf("%d %d %d    ", data[2][0], data[2][1], data[2][2]);
    printf("\n");
}

void printCube (cube_t cube) {
    printSingle(cube.top);
    printf("top---\n");
    printSingle(cube.front);
    printf("front---\n");
    printSingle(cube.right);
    printf("right---\n");
    printSingle(cube.down);
    printf("down---\n");
    printSingle(cube.back);
    printf("back---\n");
    printSingle(cube.left);
    printf("left---\n");

}

cube_t clockwise_top (cube_t cube) {
    int temp[3][3];
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            temp[i][j] = cube.top[2-j][i];
        }
    }
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cube.top[i][j] = temp[i][j];
        }
    }
    return cube;
}

cube_t clockwise_right (cube_t cube) {
    int temp[3][3];
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            temp[i][j] = cube.right[2-j][i];
        }
    }
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cube.right[i][j] = temp[i][j];
        }
    }
    return cube;
}

/*
00 01 02 
10 11 12
20 21 22

02 12 22
01 11 21
00 10 20
*/

cube_t counterclock_left (cube_t cube) {
    int temp[3][3];
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            temp[i][j] = cube.left[j][2-i];
        }
    }
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cube.left[i][j] = temp[i][j];
        }
    }
    return cube;
}

cube_t counterclock_down (cube_t cube) {
    int temp[3][3];
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            temp[i][j] = cube.down[j][2-i];
        }
    }
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cube.down[i][j] = temp[i][j];
        }
    }
    return cube;
}

cube_t type10 (cube_t cube) {
    int temp;
    for (int i=0; i<3; i++) {
        temp = cube.back[i][0];
        cube.back[i][0] = cube.down[i][0];
        cube.down[i][0] = cube.front[2-i][2];
        cube.front[2-i][2] = cube.top[i][0];
        cube.top[i][0] = temp;
    }
    cube = counterclock_left(cube);
    return cube;
}

cube_t type11 (cube_t cube) {
    int temp;
    for (int i=0; i<3; i++) {
        temp = cube.back[i][1];
        cube.back[i][1] = cube.down[i][1];
        cube.down[i][1] = cube.front[2-i][1];
        cube.front[2-i][1] = cube.top[i][1];
        cube.top[i][1] = temp;
    }
    return cube;
}

cube_t type12 (cube_t cube) {
    int temp;
    for (int i=0; i<3; i++) {
        temp = cube.back[i][2];
        cube.back[i][2] = cube.down[i][2];
        cube.down[i][2] = cube.front[2-i][0];
        cube.front[2-i][0] = cube.top[i][2];
        cube.top[i][2] = temp;
    }
    cube = clockwise_right(cube);
    return cube;
}

cube_t type20 (cube_t cube) {
    int temp;
    for (int i=0; i<3; i++) {
        temp = cube.front[0][i];
        cube.front[0][i] = cube.left[0][i];
        cube.left[0][i] = cube.back[0][i];
        cube.back[0][i] = cube.right[0][i];
        cube.right[0][i] = temp;
    }
    cube = clockwise_top(cube);
    return cube;
}

cube_t type21 (cube_t cube) {
    int temp;
    for (int i=0; i<3; i++) {
        temp = cube.front[1][i];
        cube.front[1][i] = cube.left[1][i];
        cube.left[1][i] = cube.back[1][i];
        cube.back[1][i] = cube.right[1][i];
        cube.right[1][i] = temp;
    }
    return cube;
}

cube_t type22 (cube_t cube) {
    int temp;
    for (int i=0; i<3; i++) {
        temp = cube.front[2][i];
        cube.front[2][i] = cube.left[2][i];
        cube.left[2][i] = cube.back[2][i];
        cube.back[2][i] = cube.right[2][i];
        cube.right[2][i] = temp;
    }
    cube = counterclock_down(cube);
    return cube;
}

cube_t process (cube_t cube, int ins) {
    if (ins == 10)  cube = type10(cube);
    else if (ins == 11)  cube = type11(cube);
    else if (ins == 12)  cube = type12(cube);
    else if (ins == 20)  cube = type20(cube);
    else if (ins == 21)  cube = type21(cube);
    else if (ins == 22)  cube = type22(cube);
    return cube;
}

int main () {
    cube_t cube;
    int n=0, ins=0;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cube.top[i][j] = 1;
            cube.right[i][j] = 2;
            cube.front[i][j] = 3;
            cube.back[i][j] = 4;
            cube.left[i][j] = 5;
            cube.down[i][j] = 6;
        } 
    }
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &ins);
        cube = process(cube, ins);
        //printCube(cube);
    }

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            printf("%d ", cube.top[i][j]);
        }
        printf("\n");
    }

    return 0;
}
