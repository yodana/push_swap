#include "checker.h"

int     move_r(t_pile *target)
{
    int i;
    int save;

    i = 0;
    save = target->numbers[0];
    while (i + 1 < target->size)
    {
        target->numbers[i] = target->numbers[i + 1];
        i++;
    }
    target->numbers[i] = save;
    return (1);
}

int     move_rr(t_pile *a, t_pile *b)
{
    move_r(a);
    move_r(b);
    return (1);
}

int     move_rb(t_pile *a, t_pile *b)
{
    (void)a;
    move_r(b);
    return (1);
}

int     move_ra(t_pile *a, t_pile *b)
{
    (void)b;
    move_r(a);
    return (1);
}