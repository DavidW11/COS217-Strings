/* pointer incremented implementation of string library in C */

# include "str.h"
# include <stddef.h>
# include <assert.h>
# include <stdio.h>

# include <string.h>

/* returns length of string pointed to by s,
not including the null character. */
size_t Str_getLength(const char *s) {
    const char *end = s;

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
    const char *currentChar = s2;
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
    const char *currentChar = s2;

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

    assert(s1!=NULL && s2!=NULL);
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2) {
            return (int) (*s1 - *s2);
        }
        s1++;
        s2++;
    }
    return (int) (*s1 - *s2);
}

/* searches string pointed to by s1 for string pointed to by s2, 
returns pointer to start of substring if it exists and NULL otherwise */
char *Str_search(const char *s1, const char *s2) {
    const char *startSubstring = s1;

    assert(s1!=NULL && s2!=NULL);
    if (*s2=='\0') {
        return (char *) s1;
    }

    while (*startSubstring != '\0') {
        s1 = startSubstring;
        s2 = s2;

        while (*s1!='\0' && *s2!='\0' && 
               *s1 == *s2) {
            s1++;
            s2++;
        }
        if (*s2=='\0') {
            return (char *) startSubstring;
        }
        if (*s1=='\0') {
            return NULL;
        }
        startSubstring++;
    }
    return NULL;
}
