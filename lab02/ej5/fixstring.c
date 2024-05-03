#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s)
{
    unsigned int length = 0;

    for (unsigned int i = 0; s[i] != '\0'; i++)
    {
        length++;
    }

    return length;
}

bool fstring_eq(fixstring s1, fixstring s2)
{
    bool eq = true;

    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
    {
        eq = eq && s1[i] == s2[i];
    }

    return eq;
}

bool fstring_less_eq(fixstring s1, fixstring s2)
{
    bool is_alpha;

    unsigned int i = 0;

    while ((s1[i] == s2[i]) && (s1[i] != '\0' && s2[i] != '\0'))
    {
        i++;
    }

    if (s1[i] <= s2[i])
    {
        is_alpha = true;
    }
    else
    {
        is_alpha = false;
    }

    return is_alpha;
}

void fstring_set(fixstring s1, const fixstring s2)
{
    int i = 0;
    while (i < FIXSTRING_MAX && s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void fstring_swap(fixstring s1, fixstring s2)
{
    fixstring aux;
    
    fstring_set(aux, s1);
    fstring_set(s1, s2);
    fstring_set(s2, aux);
}
