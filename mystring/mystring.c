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
    int count = 0;
    while(S) {
        count++;
        S = mystr_get_tail(S);
    }

    return count;
}

mystr *mystr_dup(mystr *S) {
	// Implementera!!
    // Way more work in iterative version of this
    if(!S) return 0;

    mystr *prev = mystr_new_char(mystr_get_char(S), 0); // Make first outside loop to save a pointer to it
    mystr *new = 0;
    mystr *first = prev; // We'll need a pointer to the first
    S = mystr_get_tail(S);
    while(S)
    {
        new = mystr_new_char(mystr_get_char(S), 0); // Create the next nodes
        mystr_set_tail(prev, new); // Set previous node's tail to the new one
        prev = new;
        S = mystr_get_tail(S);
    }

    return first;
}

mystr *mystr_inverse(mystr *S) {
	// Implementera!!
    if(!S) return 0;

    mystr *result = 0;
    while(S)
    {
        result = mystr_new_char(mystr_get_char(S), result);
        S = mystr_get_tail(S);
    }

    return result;
}
