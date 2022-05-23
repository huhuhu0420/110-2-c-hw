#include <stdio.h>
#include <stdlib.h>

#define GATEVALUE(TYPE) int(*GateValue)(struct TYPE)

typedef struct gate_sAnd{
    GATEVALUE(gate_sAnd);
    int a;
    int b;
}GateAnd;

int GateAndValue(GateAnd gate){
    return (gate.a & gate.b);
}

void CreateGateAND(GateAnd *obj, int a, int b){
    obj->GateValue = GateAndValue;
    obj->a = a;
    obj->b = b;
}

typedef struct gate_sOr{
    GATEVALUE(gate_sOr);
    int a;
    int b;
}GateOr;

int GateOrValue(GateOr gate){
    return (gate.a | gate.b);
}

void CreateGateOr(GateOr *obj, int a, int b){
    obj->GateValue = GateOrValue;
    obj->a = a;
    obj->b = b;
}

typedef struct gate_sXor{
    GATEVALUE(gate_sXor);
    int a; int b;
}GateXor;

int GateXorValue(GateXor gate){
    return (gate.a ^ gate.b);
}

void CreateGateXor(GateXor *obj, int a, int b){
    obj->GateValue = GateXorValue;
    obj->a = a; obj->b = b;
}

typedef struct gate_sNot{
    GATEVALUE(gate_sNot);
    int a;
}GateNot;

int GateNotValue(GateNot gate){
    if (gate.a == 0) return 1;
    return 0;
}

void CreateGateNot(GateNot *obj, int a){
    obj->GateValue = GateNotValue;
    obj->a = a;
}

typedef struct gate_sEmpty{
    GATEVALUE(gate_sEmpty);
    int a;
}GateEmpty;

int GateEmptyValue(GateEmpty gate){
    return gate.a;
}

void CreateGateEmpty(GateEmpty *obj, int a){
    obj->GateValue = GateEmptyValue;
    obj->a = a;
}

void getValue (char c, int in1, int in2, int *out) {
    if (c == 'A') {
        GateAnd gate;
        CreateGateAND(&gate, in1, in2);
        (*out) = GateAndValue(gate);
    }
    else if (c == 'O') {
        GateOr gate;
        CreateGateOr(&gate, in1, in2);
        (*out) = GateOrValue(gate);
    }
    else if (c == 'X') {
        GateXor gate;
        CreateGateXor(&gate, in1, in2);
        (*out) = GateXorValue(gate);
    }
    else if (c == 'N') {
        GateNot gate;
        CreateGateNot(&gate, in1);
        (*out) = GateNotValue(gate);
    }
    else if (c == 'E') {
        GateEmpty gate;
        CreateGateEmpty(&gate, in1);
        (*out) = GateEmptyValue(gate);
    }
}

int main(){
    int i1, i2, i3, i4, o1, o2, o3, x1, x2, x3;
    char ca, cb, cc, cd, ce, cf;
    scanf("%d,%d,%d,%d", &i1, &i2, &i3, &i4);
    getchar();
    scanf("%c,%c,%c,%c,%c,%c", &ca, &cb, &cc, &cd, &ce, &cf);
    getValue(ca, i1, i2, &x1);
    getValue(cb, x1, 0, &o1);
    getValue(cc, x1, i3, &x2);
    getValue(cd, o1, x2, &o2);
    getValue(ce, x2, i4, &x3);
    getValue(cf, o2, x3, &o3);
    // printf("x1 = %d\n", x1);
    // printf("o1 = %d\n", o1);
    // printf("x2 = %d\n", x2);
    // printf("o2 = %d\n", o2);
    // printf("x3 = %d\n", x3);
    // printf("o3 = %d\n", o3);
    printf("%d,%d,%d", o1, o2, o3);

    return 0;
}
