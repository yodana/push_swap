#include "checker.h"
#include <stdio.h>
void    ft_affichage(t_all *res, t_pile *a, t_pile *b)
{
    int i;

    i = 0;
    printf(" A  B\n");
    while (i < res->size)
    {
        if (i < a->size)
            printf("|%d| ",a->numbers[i]);
        else
            printf("||\n");
        if (i < b->size)
            printf("|%d| \n",b->numbers[i]);
        else
            printf("||\n");
        i++;
    }
}