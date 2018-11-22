
#include "../includes/push_swap.h"

/*
static int			is_sa(t_swap *swap)
{
	if ((swap->a0 > swap->a1 && !(swap->a0 == swap->nb_numb && swap->a1 == 1))
	|| swap->a0 == 1 && swap->a1 == swap->nb_numb)
		return (TRUE);
	return (FALSE);
}

static int			is_ss(t_swap *swap)
{
	t_val	*val;

	swap->last_b = 0;
	swap->first_b = 0;
	val = swap->val_b;
	while (val)
	{
		if (swap->last_b < val->pos_final)
			swap->last_b = val->pos_final;
		if (swap->first_b > val->pos_final)
			swap->first_b = val->pos_final;
		val = val->next;
	}
	if (is_sa(swap) &&
(swap->b0 < swap->b1 && swap->b0 != swap->first_b && swap->b1 != swap->last_b))
		return (TRUE);
	return (FALSE);
}

static int			is_pb(t_swap *swap)
{
	int		i;

	i = 0;
	if (swap->val_a && swap->val_a->pos_final != 1)
	{
		if ((absolue(swap->a0 - swap->a9) > 2
	|| absolue(swap->xa0 - swap->xa9) > 2))
			i++;
		if (swap->a8 != 0 && ((absolue(swap->a0 - swap->a8) > 2
	|| absolue(swap->xa0 - swap->xa8) > 2)))
			i++;
		if (swap->a1 != 0 && ((absolue(swap->a0 - swap->a1) > 2
	|| absolue(swap->xa0 - swap->xa1) > 2)))
			i++;
		if (swap->a2 != 0 && ((absolue(swap->a0 - swap->a2) > 2
	|| absolue(swap->xa0 - swap->xa2) > 2)))
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

void		algo2(t_swap *swap)
{
	if (is_sb(swap))
	{
		sb(swap);
		swap->line = ft_strncpy(swap->line, "sb", 3);
	}
	else
		is_rr(swap, swap->val_b, 0, 0);
}

void		algo(t_swap *swap)
{
	make_value_b(swap, swap->val_b, swap->val_b_last);
	if (is_pa(swap))
	{
		pa(swap);
		swap->line = ft_strncpy(swap->line, "pa", 3);
	}
	else if (is_pb(swap))
	{
		pb(swap);
		swap->line = ft_strncpy(swap->line, "pb", 3);
	}
	else if (is_ss(swap))
	{
		ss(swap);
		swap->line = ft_strncpy(swap->line, "ss", 3);
	}
	else if (is_sa(swap))
	{
		sa(swap);
		swap->line = ft_strncpy(swap->line, "sa", 3);
	}
	else
		algo2(swap);
}
*/















/*
void		move_next(t_swap *swap, int mid)
{
	if (swap->val_a && swap->val_a->pos_final > mid && swap->val_a->pos_final != swap->nb_numb)
	{
		pb(swap);
		swap->line = ft_strncpy(swap->line, "pb", 3);
	}
	else
	{
		ra(swap);
		swap->line = ft_strncpy(swap->line, "ra", 3);
	}
}

void		move_back(t_swap *swap, int mid)
{
	if (swap->val_a && swap->val_a->pos_final > mid && swap->val_a->pos_final != swap->nb_numb)
	{
		pb(swap);
		swap->line = ft_strncpy(swap->line, "pb", 3);
	}
	else
	{
		rra(swap);
		swap->line = ft_strncpy(swap->line, "rra", 3);
	}
}

void		algo_part1(t_swap *swap)
{
	t_val	*val;
	int		i;

	make_value_b(swap, swap->val_b, swap->val_b_last);
	val = swap->val_a;
	i = 0;
	if (swap->val_a->pos_final == 1)
		swap->check_part = 2;
	if (swap->check_part == 0)
	{
		while (val && val->pos_final != 1)
		{
			i++;
			val = val->next;
		}
		if (i < (swap->nb_numb / 3) * 2)
			swap->check_part = 11;
		else
			swap->check_part = 12;
	}
	if (swap->check_part == 11)
		move_next(swap, swap->nb_numb / 2);
	else if (swap->check_part == 12)
		move_back(swap, swap->nb_numb / 2);
	else
		algo_part2(swap);
}

static void			is_rrr2(t_swap *swap, int check)
{
	if (check == 5)
	{
		rrr(swap);
		swap->line = ft_strncpy(swap->line, "rrr", 3);
	}
	else
	{
		rra(swap);
		swap->line = ft_strncpy(swap->line, "rra", 3);
	}
}

static void			is_rrr(t_swap *swap, t_val *elem, int check, int i)
{
	int		mid;

	while (elem)
	{
		i++;
		elem = elem->next;
	}
	elem = swap->val_b_last;
	mid = i / 2;
	while (elem && mid > 0)
	{
		mid--;
		elem = elem->back;
		if (elem && elem->pos_final < elem->next->pos_final
		&& elem->next->pos_final != swap->first_b && elem->pos_final != swap->last_b)
			break ;
	}
	if (mid != 0 && i > 1)
		check = 5;
	mid = (swap->nb_numb - i) / 2;
	is_rrr2(swap, check);
}

static void			is_rr2(t_swap *swap, t_val *elem, int check, int mid)
{
	while (elem && mid > 0)
	{
		mid--;
		elem = elem->next;
		if (elem && elem->back->pos_final > elem->pos_final
		&& elem->pos_final != 1 && elem->back->pos_final != swap->nb_numb)
			break ;
	}
	if (mid != 0)
		check += 10;
	if (check == 15)
	{
		rr(swap);
		swap->line = ft_strncpy(swap->line, "rr", 3);
	}
	else if (check == 10)
	{
		ra(swap);
		swap->line = ft_strncpy(swap->line, "ra", 3);
	}
	else
		is_rrr(swap, swap->val_b, 0, 0);
}

void			is_rr(t_swap *swap, t_val *elem, int check, int i)
{
	int		mid;

	while (elem)
	{
		i++;
		elem = elem->next;
	}
	mid = i / 2;
	while (elem && mid > 0)
	{
		mid--;
		elem = elem->next;
		if (elem && elem->back->pos_final < elem->pos_final
		&& elem->pos_final != swap->first_b && elem->back->pos_final != swap->last_b)
			break ;
	}
	if (mid != 0 && i > 1)
		check = 5;
	mid = (swap->nb_numb - i) / 2;
	is_rr2(swap, swap->val_a, check, mid);
}

void	algo_part2(t_swap *swap)
{
	if (swap->val_b && swap->val_a && 
	swap->val_b->pos_final > swap->val_a_last->pos_final
	&& swap->val_b->pos_final < swap->val_a->pos_final)
	{
		pa(swap);
		swap->line = ft_strncpy(swap->line, "pa", 3);
	}
	else if (is_ss(swap))
	{
		ss(swap);
		swap->line = ft_strncpy(swap->line, "ss", 3);
	}
	else if (is_sa(swap))
	{
		sa(swap);
		swap->line = ft_strncpy(swap->line, "sa", 3);
	}
	else
		is_rr(swap, swap->val_b, 0, 0);
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



*/
