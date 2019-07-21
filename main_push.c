#include "push_swap.h"
int     main(int argc, char **argv)
{
    t_all res;
    int mv;

    mv = 0;
    if (argc == 0)
        return (0);
    init(&res, argv, argc - 1);
    ft_affichage(&res);
    while (res.a->size > 1)//check_win(res.a, res.b) == -1)
    {
        algo_go(&res, &mv);
        ft_affichage(&res);
    }
    int i = 0;
    while (i < res.pb->size)
    {
        ft_printf("tableau pivot a l index %d | %d\n", i, res.pb->numbers[i]);
        i++;
    }
    while (check_win(res.a, res.b) == -1)// && mv < 1000000)
    {
   // mv = 0;
    /*while (res.a->size > 1)//check_win(res.a, res.b) == -1)
    {
        algo_go3(&res, &mv);
        ft_affichage(&res);
    }*/
    //mv = 0;
    while (check_win(res.a,res.b) == -1 && check_tab(res.a) == 1)//res.b->size >= 1)
    {
        ft_printf(RED"FDP"END_COLOR);
        algo_go2(&res, &mv);
        ft_affichage(&res);
    }
    //}
    //mv = 0;
    while (mv < res.pa->size)
    {
          ft_printf("tableau pa == %d\n", res.pa->numbers[mv]);
        mv++;
    }
    //mv = 0;
    while (check_tab(res.a) == -1)
    {
        algo_go3(&res, &mv);
        ft_affichage(&res);
    } 
    }
    ft_printf("mv == %d\n", mv);
    return (0);

}