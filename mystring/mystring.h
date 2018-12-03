#ifndef _MYSTRING_H
#define _MYSTRING_H

typedef struct mystr_S mystr;

/* FUNCTION: mystr_new, creates a linked list string
   ARGUMENTS: val - a C string which is a basis for the
     mystr created
   RETURNS: the new mystr containing all chars found in
     val
   EXCEPTIONS: if the C string is empty 0 is returned
 */
mystr *mystr_new(char *val);

/* FUNCTION: mystr_tail, returns the mystr composed by
     all chars excluding the first char in the argument
   ARGUMENTS: S - the string whose tail is to be returned
   RETURNS: the tail of S
   EXCEPTIONS: if S has one character, then 0 is returned
 */
mystr *mystr_get_tail(mystr *S);

/* FUNCTION: mystr_compare, compares two mystr in the
     same manner as string.h strcmp, returning an int
     indicating which mystr is the 'smaller'
   ARGUMENTS: S1, S2 - the mystrs to compare
   RETURNS: -1 if S1 is smaller, 1 if S1 is larger, 0
     otherwise
   EXCEPTIONS: not yet implemented
 */
int mystr_compare(mystr *S1, mystr *S2);

/* FUNCTION: _mystr_debug_print_dup, prints a string
     to stdout
   ARGUMENTS: S - the mystr to debug print
   RETURNS: nothing
   EXCEPTIONS: not yet implemented
 */
void _mystr_debug_print(mystr *S);

/* FUNCTION: mystr_len, produce the length of a mystr
   ARGUMENTS: S - the mystr whose length is requested
   RETURNS: the length
   EXCEPTIONS: if S is empty the length is 0
 */
int mystr_len(mystr *S);

/* FUNCTION: mystr_dup, duplicates a mystr
   ARGUMENTS: S - the mystr to duplicate
   RETURNS: the mystr copy of S
   EXCEPTIONS: if S is empty 0 shall be returned
 */
mystr *mystr_dup(mystr *S);

/* FUNCTION: mystr_inverse, returns a new reverse
     order string 
   ARGUMENTS: S - the mystr to make a reverse order
     copy from
   RETURNS: the reverse order mystr
   EXCEPTIONS: if S is empty 0 shall be returned
 */
mystr *mystr_inverse(mystr *S);

#endif