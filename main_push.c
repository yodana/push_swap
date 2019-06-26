#include "push_swap.h"
int     main(int argc, char **argv)
{
    t_all res;
    int mv;

    mv = 0;
    if (argc == 0)
        return (0);
    init(&res, argv, argc - 1);
    ft_printf("argv[1] == %s\n",argv[1]);
    while (check_win(res.a, res.b) == -1)
    {
        algo_go(res.a, res.b, &mv);
        ft_affichage(&res,res.a, res.b);
    }
    ft_printf("mv == %d\n", mv);
    return (0);

}