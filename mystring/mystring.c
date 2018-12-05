#include <stdlib.h>
#include <stdio.h>

#include "mystring.h"

struct mystr_S {
  char c;
  struct mystr_S *tail;
};

mystr *mystr_new_char(char c, mystr *tail) {
    mystr *res = malloc(sizeof(mystr));
    res -> c = c;
    res -> tail = tail;
    return res;
}

mystr *mystr_new(char *val) {
    if(!val) return NULL;
    if(val[0] == 0) return NULL;
    return mystr_new_char(val[0], mystr_new(&val[1]));
}

char mystr_get_char(mystr *S) {
    return S->c;
}

int mystr_is_empty(mystr *S) {
    return S == NULL;
}

mystr *mystr_get_tail(mystr *S) {
    if(S == NULL) return NULL;
    return S->tail;
}

mystr *mystr_set_tail(mystr *S, mystr *tail) {
    S->tail = tail;
    return S;
}

int mystr_compare(mystr *S1, mystr *S2) {
    if(!S1 && !S2) return 0;
    if(!S1) return -1;
    if(!S2) return 1;
    if(S1->c == S2->c)
        return mystr_compare(S1->tail, S2->tail);
    if(S1->c < S2->c) return -1;
    if(S1->c > S2->c) return 1;
    return -999;
}

void _mystr_debug_print(mystr *S) {
    if(!S) printf("\n");
    else {
        printf("%c", S->c);
        _mystr_debug_print(S->tail);
    }
}

int mystr_len(mystr *S) {
	// Implementera!!
    if(!S) return 0;
    return mystr_len(S->tail) + 1;
}

mystr *mystr_dup(mystr *S) {
	// Implementera!!
    if(!S) return 0;
    return mystr_new_char(mystr_get_char(S), mystr_dup(mystr_get_tail(S)));
}

static mystr *_mystr_inverse(mystr *S, mystr *R) {
    // Implementera!!
    if(!S) return R;
    return _mystr_inverse(mystr_get_tail(S), mystr_new_char(mystr_get_char(S), R));
}

mystr *mystr_inverse(mystr *S) {
	// Implementera!!
    return _mystr_inverse(S, 0);
}
