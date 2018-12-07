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

/* mystr_len: Returns the number of elements in mystr
*/
int mystr_len(mystr *S) {
	// Implementera!!
    if(!S) return 0;
    return mystr_len(S->tail) + 1;
}

/*  mystr_dup: Duplicate a mystr
*/
mystr *mystr_dup(mystr *S) {
	// Implementera!!
    if(!S) return 0; // End of list
    return mystr_new_char(mystr_get_char(S), mystr_dup(mystr_get_tail(S))); // Create a new mystr, copy char value, then set its tail to a duplicate of next
}

/*  _mystr_inverse: Helper function for reversing a mystr via recursion
    Static keyword because it is "private" to this translation unit (the linker won't complain if theres another function with the same name somewhere else)
*/
static mystr *_mystr_inverse(mystr *S, mystr *R) {
    // Implementera!!
    if(!S) return R;
    return _mystr_inverse(mystr_get_tail(S), mystr_new_char(mystr_get_char(S), R)); // Create a new mystr from every node in S, when we reach the end, R will be a pointer to a duplicate mystr list starting from the other end
}

/*  mystr_inverse: Reversing a copy of mystr
    Based on school class code, there's not much to do more here, but there's an iterative version in branch 'mystring2' on Git
*/
mystr *mystr_inverse(mystr *S) {
	// Implementera!!
    return _mystr_inverse(S, 0); // Start reversing mystr, setting the end tail auto. in the first 'iteration' in next function
}
