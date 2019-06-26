#include "checker.h"

void    ft_affichage(t_all *res, t_pile *a, t_pile *b)
{
    int i;

    i = 0;
    ft_printf(" A\n");
    while (i < res->size)
    {
        if (i < a->size)
            ft_printf("|%d| ",a->numbers[i]);
        else
            ft_printf("|| ");
            i++;

    }
    i = 0; 
    ft_printf("\n B\n");
    while (i < res->size)
    {
    if (i < b->size)
            ft_printf("|%d| ",b->numbers[i]);
        else
            ft_printf("|| ");
            i++;
    }
    ft_printf("\n");
}