#include "push_swap.h"

t_pile    *cpy_tab_pile(t_pile *a, t_pile *pa)
{
    int i;
    t_pile *new;

    i = 0;
    new = (t_pile*)malloc(sizeof(t_pile));
    new->numbers = (int*)malloc(sizeof(int) * a->size);
    ft_printf("size of pa == %d\n", pa->size);
      //ft_printf("pivot of pa == %d\n", pa->numbers[pa->size - 1]);
    if (pa->size == 0)
    {
        while (i < a->size)
        {
            new->numbers[i] = a->numbers[i];
            i++;
        }
        ft_printf(RED "COUCOU" END_COLOR);
    }
    else
    {
        while (pa->numbers[pa->size - 1] != a->numbers[i])
        {
            new->numbers[i] = a->numbers[i];
            i++;
        }
    }
    new->size = i;
    i = 0;
    while (i < new->size)
    {
        ft_printf("tab valeur == %d\n", new->numbers[i]);
        i++;
    }
    return (new);
}

void  add_pivot(t_pile *p, int pivot)
{
    int i;

    i = p->size;
    p->numbers[i] = pivot;
    p->size = p->size + 1;
}
