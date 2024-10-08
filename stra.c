/* 
stra.c
array indexed implementation of string library in C 
author: David Wang
*/

#include "str.h"
#include <stddef.h>
#include <assert.h>
#include <stdio.h>

/* returns length of string pointed to by s, 
not including the null character. */
size_t Str_getLength(const char s[]) {
    size_t length = 0;

    assert(s!=NULL);
    while (s[length] != '\0') {
        length++;
    }
    return length;
}

/* copies string pointed to by s2 to pointer s1.
returns s1 (pointer of the copy). */
char *Str_copy(char s1[], const char s2[]) {
    size_t index = 0;
    assert(s1!=NULL && s2!=NULL);
    while (s2[index]!='\0') {
        s1[index] = s2[index];
        index++;
    }
    s1[index] = s2[index];
    return s1;
}


/* appends string pointed to by s2 to the end of 
the string pointed to by s1. 
returns s1 (pointer to final string). */
char *Str_concat(char s1[], const char s2[]) {
    size_t index = 0;
    size_t length1;
    assert(s1!=NULL && s2!=NULL);
    length1 = Str_getLength(s1);
    
    while (s2[index]!='\0') {
        s1[length1+index] = s2[index];
        index++;
    }
    s1[length1+index] = s2[index];
    return s1;
}

/* returns value less than, equal to, or greater than 0
depending if string pointed to by s1 is less than, equal to, or 
greater than string pointed to by s2. */
int Str_compare(const char s1[], const char s2[]) {
    size_t index = 0;

    assert(s1!=NULL && s2!=NULL);
    while(s1[index]!='\0' && s2[index]!='\0') {
        if (s1[index]!=s2[index]) {
            return (int) (s1[index] - s2[index]);
        }
        index++;
    }

    /* since the char \0 has a value of 0, the statement below will
    return a positive number if s2 reached the end of its string
    before s1 (s1 is longer than s2), a negative number if vice-versa,
    and 0 if they both reached the end of their string (equal length).
    the program will only reach this point if all characters so far
    are equal. */
    return (int) (s1[index] - s2[index]);
}

/* searches string pointed to by s1 for string pointed to by s2, 
returns pointer to start of substring if it exists and NULL otherwise */
char *Str_search(const char s1[], const char s2[]) {
    size_t startIndex = 0;
    size_t index1 = 0;
    size_t index2 = 0;

    assert(s1!=NULL && s2!=NULL);
    if (s2[0]=='\0') {
        return (char *) s1;
    }

    while (s1[startIndex]!='\0') {

        index1 = startIndex;
        index2 = 0;

        while (s1[index1]!='\0' && s2[index2]!='\0' && 
               s1[index1]==s2[index2]) {
            index1++;
            index2++;
        }
        if(s2[index2]=='\0') {
            /* if we have completed the search for the substring, 
            return pointer to start of the substring */
            return (char *) &s1[startIndex];
        }
        if(s1[index1]=='\0') {
            /* if reach the end of s1 before s2, no substring exists */
            return NULL;
        }
        /* since substring search for this character failed, 
        try for next character */
        startIndex++;
    }
    return NULL;
}

/*
int main() {
    char *pcResult1;
    char *pcResult2;

    const char acHaystack[] = "";
    const char acNeedle[] = "";
    pcResult1 = Str_search(acHaystack, acNeedle);
    pcResult2 = strstr(acHaystack, acNeedle);
    printf("%c", *pcResult1);
    printf("%c", *pcResult2);
}
*/