#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der)
{
    if (izq < der)
    {
        unsigned int ppiv = partition(a, izq, der);

        if (0 < ppiv)
        {
            quick_sort_rec(a, izq, ppiv - 1);
        }
        if (ppiv < der)
        {
            quick_sort_rec(a, ppiv + 1, der);
        }
    }
}

void quick_sort(int a[], unsigned int length)
{
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}
