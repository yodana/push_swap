#include "checker.h"

t_pile  *init_pile_b(int size)
{
    t_pile *b;

    if (!(b = (t_pile*)malloc(sizeof(t_pile))))
        return (NULL);
    if (!(b->numbers = (int*)malloc(sizeof(int) * size)))
        return (NULL);
    b->size = size;
    return (b);
}

t_pile  *init_pile_a(char **numbers, int size)
{
    int i;
    int j;
    t_pile *a;

    i = 1;
    j = 0;
    if (!(a = (t_pile*)malloc(sizeof(t_pile))))
        return (NULL);
    if (!(a->numbers = (int*)malloc(sizeof(int) * size)))
        return (NULL);
    while (numbers[i])
    {
        a->numbers[j] = ft_atoi(numbers[i]);
        i++;
        j++;
    }
    a->size = size;
    return (a);
}

int     init(t_all *res, char **numbers, int size)
{
    if (!(res->a = init_pile_a(numbers, size)))
        return (-1);
    if (!(res->b = init_pile_a(numbers, size)))
        return (-1);
    return (1);
}