#include "push_swap.h"

int     find_pos_pivot(t_pile *target, int pile)
{
    int i;

    i = target->size - 1;
    while (i > 0)
    {
        if (pile == 0 && target->numbers[i] < target->numbers[i - 1])
            return (i);
        if (pile == 1 && target->numbers[i] > target->numbers[i - 1])
            return (i);
        i--;
    }
    return (-1);
}

void    algo_go(t_pile *a, t_pile *b, int *mv)
{
    int c;
    int k;
    int i;

    i = 0;
    k = 0;
    c = find_pos_pivot(a, 0);
    k = find_pos_pivot(b, 1);
    if (c == -1 && k == -1)
    {
        while (b->size > 0)
        {
            move_pa(a, b);
            *mv = *mv + 1;
            i++;
        }
        return ;
    }
    while (c >= 0)
    {
        if (a->numbers[c] > a->numbers[0])
          {
                  move_pb(a, b);
                  *mv = *mv + 1;
          }
        else if (a->numbers[c] < a->numbers[0])
        {
              move_ra(a , b);
              *mv = *mv + 1;
        }
       ft_printf("number %d\n",c);
        c--;
    }
    k = find_pos_pivot(b, 1);
    while (k >= 0)
    {
        if (b->numbers[k] > b->numbers[0])
        {
            move_rb(a ,b);
            *mv = *mv + 1;
        }
        else if (b->numbers[k] < b->numbers[0])
         {
            move_pa(a ,b);
            *mv = *mv + 1;
         }
        k--;
    }
    if (a->size > 1 && a->numbers[0] > a->numbers[1])
    {
        i++;
        move_sa(a , b);   
        //*mv = *mv + 1;
    }
    if (b->size > 1 && b->numbers[0] < b->numbers[1])
     {
            move_sb(a, b);
          //  *mv = *mv + 1;
     }
    ft_printf("position pivot b == %d\n",k);
}