#include "checker.h"

int     check_win(t_pile *a, t_pile *b)
{
    int i;

    i = 0;
    if (b->size > 0)
        return (-1);
    while (i + 1 < a->size)
    {
        if (a->numbers[i] > a->numbers[i + 1])
            return (-1);
        i++;
    }
    return (1);
}

int     check_double(t_pile *a)
{
    int i;
    int j;

    j = 1;
    i = 0;

    while (i < a->size)
    {
        while (j < a->size)
        {
            if (a->numbers[i] == a->numbers[j])
                return (-1);
            j++;
        }
        i++;
        j = i + 1;
    }
    return (1);
}

int     check(char **argv)
{
    int i;
    int j;

    j = 0;
    i = 1;
    while (argv[i])
    {
        if (ft_strlen(argv[i]) > 10 || (ft_strlen(argv[i]) == 10
            && (ft_strcmp(INT_MAX, argv[i]) < 0)))
            return (-1);
        while (argv[i][j])
        {
            if (ft_isdigit(argv[i][j]) != 1)
                return (-1);
            j++;
        }
        j = 0;
        i++;
    }
    return (1);
}