#include <stdio.h>
#include "tests.h"

void print_comparison(int compval, int expect) {
    if(compval == expect) return;
    printf("ERROR: expected ");
    switch(compval) {
      case COMP_LESS:
        printf("less"); break;
      case COMP_EQUAL:
        printf("equal"); break;
      case COMP_GREATER:
        printf("greater"); break;
      case -999:
        printf("(error)"); break;
      default:
        printf("(undef)"); break;
    }
    printf(" got ");
    switch(compval) {
      case COMP_LESS:
        printf("less\n"); break;
      case COMP_EQUAL:
        printf("equal\n"); break;
      case COMP_GREATER:
        printf("greater\n"); break;
      case -999:
        printf("(error)\n"); break;
      default:
        printf("(undef)\n"); break;
    }
}
int is_distinct(mystr *M1, mystr *M2) {
    if(M1 == 0 || M2 == 0) return 1;
    if(M1 == M2) return 0;
    return is_distinct(mystr_get_tail(M1), mystr_get_tail(M2));
}