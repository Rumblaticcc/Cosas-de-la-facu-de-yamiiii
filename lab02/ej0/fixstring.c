#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s)
{
    unsigned int length;

    for (int i = 0; s[i] != '\0'; i++)
    {
        length = i;
    }
    return length + 1;
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
    bool eq = true;

    for (unsigned int i = 0; i < fstring_length(s1); i++)
    {
        if (s1[0] < s2[0])
        {
            eq = true;
        }
        else if (s1[i] == s2[i] && fstring_length(s1) < fstring_length(s2))
        {
            eq = true;
        }
        else
        {
            eq = false;
        }
    }
    return eq;
}
