#include "checker.h"

void    ft_affichage(t_all *res)
{
    int i;

    i = 0;
    ft_printf(" A\n");
    while (i < res->size)
    {
        if (i < res->a->size)
            ft_printf("|%d| ",res->a->numbers[i]);
        else
            ft_printf("|| ");
            i++;

    }
    i = 0; 
    ft_printf("\n B\n");
    while (i < res->size)
    {
    if (i < res->b->size)
            ft_printf("|%d| ",res->b->numbers[i]);
        else
            ft_printf("|| ");
            i++;
    }
    ft_printf("\n");
}