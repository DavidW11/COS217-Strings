/* pointer incremented implementation of string library in C */

# include "str.h"
# include <stddef.h>
# include <assert.h>
# include <stdio.h>

# include <string.h>

/* returns length of string pointed to by s,
not including the null character. */
size_t Str_getLength(const char *s) {
    char *end = s;

    assert(s!=NULL);
    while (*end != '\0') {
        end++;
    }
    /* subtracting 2 pointers gives distance in array elements */
    return (size_t) (end-s);
}

/* copies string pointed to by s2 to pointer s1.
returns s1 (pointer of the copy). */
char *Str_copy(char *s1, const char *s2) {
    char *currentChar = s2;
    assert(s1!=NULL && s2!=NULL);
    while (*currentChar != '\0') {
        *s1 = *currentChar;
        s1++;
        currentChar++;
    }
    *s1 = *currentChar;
    return s1;
}

/* appends string pointed to by s2 to the end of 
the string pointed to by s1. 
returns s1 (pointer to final string). */
char *Str_concat(char *s1, const char *s2) {
    char *end = s1;
    char *currentChar = s2;

    assert(s1!=NULL && s2!=NULL);
    /* iterate to end of string pointed to by s1 */
    while (*end!='\0') {
        end++;
    }
    while (*currentChar!='\0') {
        *end = *currentChar;
        end++;
        currentChar++;
    }
    *end = *currentChar;
    return s1;
}

/* returns value less than, equal to, or greater than 0
depending if string pointed to by s1 is less than, equal to, or 
greater than string pointed to by s2. */
int Str_compare(const char *s1, const char *s2) {
    char *c1 = s1;
    char *c2 = s2;

    assert(s1!=NULL && s2!=NULL);
    while (*c1 != '\0' && *c2 != '\0') {
        if (*c1 != *c2) {
            return (int) (*c1 - *c2);
        }
        c1++;
        c2++;
    }
    return (int) (*c1 - *c2);
}

/* searches string pointed to by s1 for string pointed to by s2, 
returns pointer to start of substring if it exists and NULL otherwise */
char *Str_search(const char *s1, const char *s2) {
    char *startSubstring = s1;
    char *c1 = s1;
    char *c2 = s2;

    assert(s1!=NULL && s2!=NULL);
    if (*c2=='\0') {
        return c1;
    }

    while (*startSubstring != '\0') {
        c1 = startSubstring;
        c2 = s2;

        while (*c1!='\0' && *c2!='\0' && 
               *c1 == *c2) {
            c1++;
            c2++;
        }
        if (*c2=='\0') {
            return startSubstring;
        }
        if (*c1=='\0') {
            return NULL;
        }
        startSubstring++;
    }
    return NULL;
}
