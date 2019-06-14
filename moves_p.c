#include "checker.h"

int     move_p(t_pile *giver, t_pile *receiv)
{
    int i;

    i = receiv->size;
    if (giver->size > 0)
    {
        receiv->size = receiv->size + 1;
        while (i > 0)
        {
            receiv->numbers[i] = receiv->numbers[i - 1];
            i--;
        }
        receiv->numbers[0] = giver->numbers[0];
        i = 0;
        while (i + 1 < giver->size)
        {
            giver->numbers[i] = giver->numbers[i + 1];
            i++;
        }
        giver->size = giver->size - 1;
    }
    return (1);
}

int     move_pb(t_pile *a, t_pile *b)
{
    move_p(a, b);
    return (1);
}

int     move_pa(t_pile *a, t_pile *b)
{
    move_p(b, a);
    return (1);
}