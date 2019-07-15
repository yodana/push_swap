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
    mv = 0;
    while (mv < 2)
    { 
        algo_go2(&res, &mv);
        ft_affichage(&res);
    }
    ft_printf("mv == %d\n", mv);
    return (0);

}