
#include "../includes/push_swap.h"

static int			is_sa(t_swap *swap)
{
	if (swap->a0 > swap->a1 || swap->xa0 > swap->xa1)
		return (TRUE);
	return (FALSE);
}

static int			is_ss(t_swap *swap)
{
	if ((swap->a0 > swap->a1 || swap->xa0 > swap->xa1)
	&& (swap->b0 > swap->b1 || swap->xb0 > swap->xb1))
		return (TRUE);
	return (FALSE);
}

static int			is_pb(t_swap *swap)
{
	int		i;

	i = 0;
	if (swap->val_a)
	{
		if ((absolue(swap->a0 - swap->a9) < 3
	|| absolue(swap->xa0 - swap->xa9) < 3))
			i++;
		if (swap->a8 != 0 && ((absolue(swap->a0 - swap->a8) < 3
	|| absolue(swap->xa0 - swap->xa8) < 3)))
			i++;
		if (swap->a1 != 0 && ((absolue(swap->a0 - swap->a1) < 3
	|| absolue(swap->xa0 - swap->xa1) < 3)))
			i++;
		if (swap->a2 != 0 && ((absolue(swap->a0 - swap->a2) < 3
	|| absolue(swap->xa0 - swap->xa2) < 3)))
			i++;
		if (i == 4)
			return (TRUE);
	}
	return (FALSE);
}

static int			is_pa(t_swap *swap)
{
	if (swap->val_b)
	{
		if (absolue(swap->b0 - swap->a9) < 3 || absolue(swap->b0 - swap->a0) < 3
	|| absolue(swap->xb0 - swap->xa9) < 3 || absolue(swap->xb0 - swap->xa0) < 3)
			return (TRUE);
		if (swap->a8 != 0 && (absolue(swap->b0 - swap->a8) < 3
	|| absolue(swap->xb0 - swap->xa8) < 3))
			return (TRUE);
		if (swap->a1 != 0 && (absolue(swap->b0 - swap->a1) < 3
	|| absolue(swap->xb0 - swap->xa1) < 3))
			return (TRUE);
	}
	return (FALSE);
}

void		algo(t_swap *swap)
{
	make_value_b(swap, swap->val_b, swap->val_b_last);
	if (is_pa(swap))
		pa(swap);
	else if (is_pb(swap))
		pb(swap);
	else if (is_ss(swap))
		ss(swap);
	else if (is_sa(swap))
		sa(swap);
	else if (is_sb(swap))
		sb(swap);
	else
		is_rr(swap, swap->val_b, 0, 0);
}
