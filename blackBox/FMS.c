#include <stdio.h> // FMS.c
#include <ctype.h>
typedef enum {start, build_id, build_num, build_invalid, identifier, number, invalid, stop} state_t;
state_t getNextState(state_t current_state, char ch) {
    if (current_state == start) {
        if (ch == ' ') return start;
        else if (isalpha(ch)) return build_id;
        else if (isdigit(ch)) return build_num;
        else if (ch=='#') return stop;
    }
    if (current_state == build_id) {
        if (isalpha(ch)||isdigit(ch)||(ch=='_')) return build_id;
        else if (ch==' ') return identifier;
    }
    if (current_state == build_num) {
        if (isdigit(ch)) return build_num;
        else if (ch==' ') return number;
    }
    else return -1;
}
