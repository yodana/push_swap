#include "push_swap.h"

int        find_pos_pivot(t_pile *target, int pile)
{
    int i;

pile = 1;
    i = target->size / 2;
    return (i);
}
/*int     find_pos_pivot(t_pile *target, int pile)
{
    int i;

    i = 0;
    while (i < target->size - 1)
    {
        if (pile == 0 && target->numbers[i] > target->numbers[i + 1])
            return (i);
        if (pile == 1 && target->numbers[i] < target->numbers[i + 1])
            return (i);
        i--;
    }
    return (-1);
}*/

void        algo_go(t_all *res, int *mv)
{

    int c;
    int i;
    int pivot;

    (void)res->b;
    c = find_pos_pivot(res->a, 0);
    ft_printf("position pivot == %d\n",c);
    pivot = res->a->numbers[c];
    ft_printf("pivot == %d\n", pivot);
    c = 0;
    i = res->a->size;
    while (c < i)
    {
        if (res->pa->numbers[c] <= pivot)
        {
            //ft_printf("number dans pa == %d \n", res->pa->numbers[c]);
                move_pb(res->a, res->b);
        }
        else
        {
            move_ra(res->a, res->b);
        }
        c++;
    }
    *mv = *mv + 1;
}
/*void    algo_go(t_pile *a, t_pile *b, int *mv)
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
        *mv = *mv + 1;
    }
    if (b->size > 1 && b->numbers[0] < b->numbers[1])
     {
            move_sb(a, b);
            *mv = *mv + 1;
     }
    ft_printf("position pivot b == %d\n",k);
}*/