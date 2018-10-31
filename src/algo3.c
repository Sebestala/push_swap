
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
		rrr(swap);
	else if (check == 10)
		rra(swap);
	else if (check == 5)
		rrb(swap);
	else
		rrr(swap);
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
		rr(swap);
	else if (check == 10)
		ra(swap);
	else if (check == 5)
		rb(swap);
	else
		is_rrr(swap, swap->val_b, 0, 0);
}

void			is_rr(t_swap *swap, t_val *element, int check, int i)
{
	int		mid;

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
