
#include "../includes/push_swap.h"

static void			is_rrr2(t_swap *swap, t_val *element, int check, int mid)
{
	while (element && mid > 0)
	{
		mid++;
		element = element->back;
		if (absolue(element->pos_final - element->back->pos_final) < 3)
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

static void			is_rrr(t_swap *swap, t_val *element, int check, int i)
{
	int		mid;

	while (element)
	{
		i++;
		element = element->next;
	}
	element = swap->val_b_last;
	mid = i / 2;
	while (element && mid > 0)
	{
		mid++;
		element = element->back;
		if (absolue(element->pos_final - element->back->pos_final) < 3)
			break ;
	}
	if (mid == 0)
		check = 5;
	mid = (swap->nb_numb -i) / 2;
	is_rrr2(swap, swap->val_a_last, check, mid);
}

static void			is_rr2(t_swap *swap, t_val *element, int check, int mid)
{
	while (element && mid > 0)
	{
		mid++;
		element = element->next;
		if (absolue(element->pos_final - element->back->pos_final) < 3)
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

void			is_rr(t_swap *swap, t_val *element, int check, int i)
{
	int		mid;

	if (is_sb(swap))
	{
		sb(swap);
		swap->line = ft_strncpy(swap->line, "sb", 3);
	}
	while (element)
	{
		i++;
		element = element->next;
	}
	element = swap->val_b;
	mid = i / 2;
	while (element && mid > 0)
	{
		mid++;
		element = element->next;
		if (absolue(element->pos_final - element->back->pos_final) < 3)
			break ;
	}
	if (mid == 0)
		check = 5;
	mid = (swap->nb_numb -i) / 2;
	is_rr2(swap, swap->val_a, check, mid);
}

int			is_sb(t_swap *swap)
{
	if (swap->b0 > swap->b1 || swap->xb0 > swap->xb1)
		return (TRUE);
	return (FALSE);
}
