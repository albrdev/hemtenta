#include <stdio.h>

#include "tests.h"

#include "mystring.h"

int main(void) {
    mystr *str1 = mystr_new("Hej!");
    mystr *str2 = mystr_new("Hej!");
    print_comparison(mystr_compare(str1, str2), COMP_EQUAL);
    str1 = mystr_new("Abram");
    str2 = mystr_new("Abraham");
    print_comparison(mystr_compare(str1, str2), COMP_GREATER);
    str1 = mystr_new("Abra");
    str2 = mystr_new("Abrakadabra");
    print_comparison(mystr_compare(str1, str2), COMP_LESS);
    str1 = mystr_new("Adam");
    str2 = mystr_new("Bertil");
    print_comparison(mystr_compare(str1, str2), COMP_LESS);
    int n = mystr_len(str2);
    printf("%d == 6?\n", n);
    str2 = mystr_dup(str1);
    if(!is_distinct(str1,str2)) {
        printf("ERROR: mystr_dup did not copy the string!\n");
    }
    print_comparison(mystr_compare(str1, str2), COMP_EQUAL);
    str1 = mystr_new("sirap");
    str1 = mystr_inverse(str1);
    str2 = mystr_new("paris");
    print_comparison(mystr_compare(str1, str2), COMP_EQUAL);
    return 0;
}