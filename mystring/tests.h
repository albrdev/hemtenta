#ifndef _TESTS_H
#define _TESTS_H

#include "mystring.h"

#define COMP_LESS -1
#define COMP_EQUAL 0
#define COMP_GREATER 1

void print_comparison(int compval, int expect);
int is_distinct(mystr *M1, mystr *M2);

#endif /* _TESTS_H */
