#include "../../includes/checker.h"

int     ft_init_color(char *color, t_all *res)
{
    int i;

    i = 1;
    (void)res;
    (void)color;
    if (ft_strcmp("BLUE", &color[2]) == 0)
    {
          res->commands->color_b = 55;
           res->commands->color_g = 255;
            res->commands->color_r = 255;
    }
    else if (ft_strcmp("GREEN", &color[2]) == 0)
    {
        res->commands->color_g = 200;
          res->commands->color_b = 100;
           res->commands->color_r = 100;
    }
    else if (ft_strcmp("RED", &color[2]) == 0)
    {
         res->commands->color_g = 55;
          res->commands->color_b = 200;
           res->commands->color_r = 100;
    }
    return (0);
    
}
int     ft_parsing_argv(char **argv, t_all *res)
{
    int i;
    int j;

    i = 1;
    j = 1;
    if (!(res->commands = (t_argv*)malloc(sizeof(t_argv))))
		return (-1);
         res->commands->color_g = 255;
          res->commands->color_b = 255;
           res->commands->color_r = 255;
    res->commands->v = 0;
    res->commands->c = 0;
    while (argv[i] && argv[i][0] == '-')
    {
        if (!argv[i][1])
            return (0);
        while (argv[i][j])// && (argv[i][j] == 'v' || argv[i][j] == 'c'))
        {
            if (argv[i][j] == 'v')
                res->commands->v = 1;
            else if (argv[i][j] == 'm')
                res->commands->m = 1;
            else if (argv[i][j] == 'c')
            {
                res->commands->c = 1;
                if (argv[i][j + 1] && argv[i][j + 1] == '=')
                {
                    ft_init_color(&argv[i][j], res);
                    break ;
                }
            }
            else
            {
                 ft_printf("i == %d\n",i );
                return (0);
            }
            j++;
        }
        i++;
        j = 1;
    }
   // ft_printf("i == %d\n",i );
   if (!argv[i])
    i = 1;
    return (i - 1);
}