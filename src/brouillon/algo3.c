
#include "../includes/push_swap.h"
/*
static void			is_rrr2(t_swap *swap, t_val *elem, int check, int mid)
{
	while (elem && mid > 0)
	{
		mid--;
		elem = elem->back;
		if (elem && elem->pos_final > elem->next->pos_final && elem->next->pos_final != 1)
			break ;
	}
	if (mid == 0)
		check += 10;
	if (check == 15)
	{
		rrr(swap);
		swap->line = ft_strncpy(swap->line, "rrr", 3);
	}
	else if (check == 10)
	{
		rra(swap);
		swap->line = ft_strncpy(swap->line, "rra", 3);
	}
	else if (check == 5)
	{
		rrb(swap);
		swap->line = ft_strncpy(swap->line, "rrb", 3);
	}
	else
	{
		rrr(swap);
		swap->line = ft_strncpy(swap->line, "rrr", 3);
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
		if (elem && elem->pos_final < elem->next->pos_final)
			break ;
	}
	if (mid == 0 && i > 1)
		check = 5;
	mid = (swap->nb_numb - i) / 2;
	is_rrr2(swap, swap->val_a_last, check, mid);
}

static void			is_rr2(t_swap *swap, t_val *elem, int check, int mid)
{
	while (elem && mid > 0)
	{
		mid--;
		elem = elem->next;
		if (elem && elem->back->pos_final > elem->pos_final && elem->pos_final != 1)
			break ;
	}
	if (mid == 0)
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
	else if (check == 5)
	{
		rb(swap);
		swap->line = ft_strncpy(swap->line, "rb", 3);
	}
	else
		is_rrr(swap, swap->val_b, 0, 0);
}

int			is_sb(t_swap *swap)
{
	if (swap->b0 < swap->b1)
		return (TRUE);
	return (FALSE);
}

void			is_rr(t_swap *swap, t_val *elem, int check, int i)
{
	int		mid;

	while (elem)
	{
		i++;
		elem = elem->next;
	}
	elem = swap->val_b;
	mid = i / 2;
	while (elem && mid > 0)
	{
		mid--;
		elem = elem->next;
		if (elem && elem->back->pos_final < elem->pos_final)
			break ;
	}
	if (mid == 0 && i > 1)
		check = 5;
	mid = (swap->nb_numb - i) / 2;
	is_rr2(swap, swap->val_a, check, mid);
}*/
