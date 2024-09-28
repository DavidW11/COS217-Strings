# include "str.h"
# include <stddef.h>
# include <assert.h>

# include <string.h>

/* returns length of string s, not including the null character. */
size_t Str_getLength(const char pcSrc[]) {
    assert(pcSrc!=NULL);
    size_t length = 0;
    while (pcSrc[length] != '\0') {
        length++;
    }
    return length;
}

/* copies string pointed to by s2 to pointer s1.
returns s1 (pointer of the copy). */
char *Str_copy(char *s1, const char *s2) {
    /* no way to know if s2 can fit in s1 */
    assert(s1!=NULL && s2!=NULL);
    int index = 0;
    while (s2[index]!='\0') {
        s1[index] = s2[index];
    }
    return s1;
}

/* appends string pointed to by s2 to the end of 
the string pointed to by s1. 
returns s1 (pointer to final string). */
char *Str_concat(char *s1, const char *s2);

/* returns value less than, equal to, or greater than 0
depending if string pointed to by s1 is less than, equal to, or 
greater than string pointed to by s2. */
int Str_compare(const char *s1, const char *s2);

/* searches string pointed to by s1 for string pointed to by s2, 
returns pointer to start of substring if it exists and NULL otherwise */
char *Str_search(const char *s1, const char *s2);
