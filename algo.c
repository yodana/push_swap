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

void        algo_go2(t_all *res, int *mv)
{
    int c;
    int i;
    t_pile *tab_tmp;
    ft_printf("NEW \n ");
    tab_tmp = cpy_tab_pile(res->b, res->pb);
    int pos = find_pos_pivot(tab_tmp, 0);
    ft_printf("pivot position == %d\n", pos);
    c = 0;
    i = tab_tmp->size;
    ft_printf("size de la pile  = %d\n",i);
    ft_printf("pivot ou il faut stop == %d && size == %d\n", res->pb->numbers[res->pb->size - 1], res->pb->size);
    while (c < i)
    {
        //ft_printf("number dans pa == %d \n", tab_tmp[c]);
        if (tab_tmp->numbers[c] >= tab_tmp->numbers[pos])
        {
                move_pa(res->a, res->b);
                *mv = *mv + 1;
                if (c > pos)
                 {
                    move_sa(res->a, res->b);
                    *mv = *mv + 1;
                 }
        }
        else if (c <= pos)
        {
            move_rb(res->a, res->b);
            *mv = *mv + 1;
        }
         ft_printf("mv == %d\n", *mv);
        ft_affichage(res);
        ft_printf("\n\n");
        c++;
    }
    add_pivot(res->pa, tab_tmp->numbers[pos]);
    if (res->pb->size > 0)
    res->pb->size = res->pb->size - 1;
    //free(tab_tmp);
    //*mv = *mv + 1;
    //ft_printf("tab_pivot == %d\n", res->pa->numbers[*mv]);
}

void        algo_go3(t_all *res, int *mv)
{
    

    int c;
    int i;
    t_pile *tab_tmp;
    
    tab_tmp = cpy_tab_pile(res->a, res->pa);
    int pos = find_pos_pivot(res->a, 0);
    ft_printf("pivot == %d\n", tab_tmp->numbers[pos]);
    c = 0;
    i = tab_tmp->size;
    ft_printf("size d ela pile a = %d\n",i);
    while (c < i)
    {
        //ft_printf("number dans pa == %d \n", tab_tmp[c]);
        if (tab_tmp->numbers[c] <= tab_tmp->numbers[pos])
        {
                if (res->a->size > 1)
                move_pb(res->a, res->b);
                *mv = *mv + 1;
                if (c > pos)
                 {   move_sb(res->a, res->b);

                    *mv = *mv + 1;
                 }
        }
        else
        {
            move_ra(res->a, res->b);
            *mv = *mv + 1;
        }
        c++;
    }
    add_pivot(res->pb, tab_tmp->numbers[pos]);
    if (res->pa->size > 0)
        res->pa->size = res->pa->size - 1;
    //ft_printf("tab_pivot == %d\n", res->pb->numbers[*mv]);
}
void        algo_go(t_all *res, int *mv)
{

    int c;
    int i;
    t_pile *tab_tmp;
    
    tab_tmp = cpy_tab_pile(res->a, res->pa);
    int pos = find_pos_pivot(res->a, 0);
    ft_printf("pivot == %d\n", tab_tmp->numbers[pos]);
    c = 0;
    i = res->a->size;
    ft_printf("size d ela pile a = %d\n",i);
    while (c < i)
    {
        //ft_printf("number dans pa == %d \n", tab_tmp[c]);
        if (tab_tmp->numbers[c] <= tab_tmp->numbers[pos])
        {
            //if (res->a->size > 1)
                move_pb(res->a, res->b);
                *mv = *mv + 1;
                if (c > pos)
                {   
                    move_sb(res->a, res->b);
                    *mv = *mv + 1;
                }
        }
        else if (res->a->size > 1)
        {
            move_ra(res->a, res->b);
            *mv = *mv + 1;
        }
        ft_printf("mv == %d\n", *mv);
        ft_affichage(res);
        ft_printf("\n\n");
        c++;
    }
    add_pivot(res->pb, tab_tmp->numbers[pos]);
    //ft_printf("tab_pivot == %d\n", res->pb->numbers[*mv]);
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