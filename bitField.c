#include <stdio.h>
//#pragma pack(1)

typedef struct data_s {
    unsigned char b0: 1;
    unsigned char b1: 1;
    unsigned char b2: 1;
    unsigned char b3: 1;
    unsigned char b4: 1;
    unsigned char status: 4;
} data_t;

void test01 () {
    data_t data;
    printf("%d\n", sizeof(unsigned char));
    printf("%d\n", sizeof(unsigned));
    printf("%d\n", sizeof(data_t));
    scanf("%c", &data);
    printf("%d", data.b4);
    printf("%d", data.b3);
    printf("%d", data.b2);
    printf("%d", data.b1);
    printf("%d\n", data.b0);
    printf("%d", data.status);
}

struct on_off {
    unsigned light: 1;
    unsigned toaster: 1;
    int count;
    unsigned ac: 4;
    unsigned : 4;
    unsigned clock: 1;
    unsigned : 0;
    unsigned flag: 1;
} kitchen;

struct flag {
    unsigned short f1: 1;
    unsigned short f2: 1;
    unsigned short f3: 1;
    unsigned short f4: 1;
    unsigned short f5: 1;
} room;

struct house_s {
    unsigned int f1: 1;
    unsigned int f2: 1;
    unsigned int f3: 1;
} house;

void test02 () {
    printf("%d\n", sizeof(unsigned));
    printf("%d\n", sizeof(kitchen));
    printf("%d\n", sizeof(room));
    printf("%d\n", sizeof(unsigned short));
    printf("%d\n", sizeof(house));
}

int main () {
    test02();

    return 0;
}
