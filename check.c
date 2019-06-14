#include "checker.h"

int     check_win(t_pile *a, t_pile *b)
{
    int i;

    i = 0;
    if (b->size > 0)
        return (-1);
    while (i + 1 < a->size)
    {
        if (a->numbers[i] > a->numbers[i + 1])
            return (-1);
        i++;
    }
    return (1);
}