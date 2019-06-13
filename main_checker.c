#include "checker.h"
#include <stdio.h>

int     main(int argc, char **argv)
{
    char *mv;
    t_all res;

    if (argc == 0)
        return (0);
    init(&res, argv, argc);
    while ((mv = ft_get_txt(0)) != NULL)
    {
         check_move(&res, mv);
    }
    return (0);
}