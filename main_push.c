#include <stdio.h>
#include "push_swap.h"
int     main(int argc, char **argv)
{
    t_all res;

    if (argc == 0)
        return (0);
    init(&res, argv, argc - 1); 
    while (check_win(res.a, res.b) == -1)
    {
        
    }
    return (0);

}