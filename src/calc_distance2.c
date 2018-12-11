
#include "../includes/push_swap.h"

static void		calc_pos_current(t_val *min, t_val *first)
{
	t_val	*elem;
	int		i;

	if (min)
	{
		i = 1;
		elem = min;
		while (elem)
		{
//printf("ELEM    val = %d    pos_current = %d  final = %d \n", elem->val, elem->pos_current, elem->pos_final);
			elem->pos_current = i;
			elem = elem->next;
			i++;
		}
		elem = first;
		while (elem && elem != min)
		{
			elem->pos_current = i;
			elem = elem->next;
			i++;
		}
	}
}

static void		calc_tab_distance_a2(t_swap *swap, t_val *elem, int *i)
{
	while (elem)
	{
		swap->tab_distance_a2[*i] = absolue(elem->pos_current - elem->pos_final);
		if (swap->tab_distance_a2[*i] > swap->mid_a2)
			swap->tab_distance_a2[*i] = swap->length_a2 - absolue(elem->pos_current - elem->pos_final);
		swap->total_distance_a2 += swap->tab_distance_a2[*i];
//printf("A2 i = %d   val = %d    pos_current = %d  final = %d    total_distance = %d    length_a2 = %d    mid_a2 = %d  \n", *i, elem->val, elem->pos_current, elem->pos_final, swap->total_distance_a2, swap->length_a2, swap->mid_a2);
		elem = elem->next;
		(*i)++;
	}
}

void			calc_tab_distance_a1_2(t_swap *swap, int i, int check)
{
	swap->total_distance_a2 = 0;
	if (check == 0)
	{
		swap->mid_a2 = swap->length_a2 / 2;
		calc_pos_current(swap->sort_final_a2, swap->val_a2);
	}
	calc_tab_distance_a2(swap, swap->val_a2, &i);
	while (i < swap->nb_numb)
		swap->tab_distance_a2[i++] = -1;
//	test_radix(swap, 2, 'a');
}

static void		calc_tab_distance_b2(t_swap *swap, t_val *elem, int *i)
{
	while (elem)
	{
		swap->tab_distance_b2[*i] = absolue(elem->pos_current - elem->pos_final);
		if (swap->tab_distance_b2[*i] > swap->mid_b2)
			swap->tab_distance_b2[*i] = swap->length_b2 - absolue(elem->pos_current - elem->pos_final);
		swap->total_distance_b2 += swap->tab_distance_b2[*i];
//printf("B2 i = %d   val = %d    pos_current = %d  final = %d    total_distance = %d  \n", *i, elem->val, elem->pos_current, elem->pos_final, swap->total_distance_b2);
		elem = elem->next;
		(*i)++;
	}
}

void			calc_tab_distance_b1_2(t_swap *swap, int i, int check)
{
	swap->total_distance_b2 = 0;
	if (check == 0)
	{
		swap->mid_b2 = swap->length_b2 / 2;
//printf("\n   length_b = %d   mid_b = %d \n", swap->length_b, swap->mid_b);
		calc_pos_current(swap->sort_final_b2, swap->val_b2);
	}
	calc_tab_distance_b2(swap, swap->val_b2, &i);
	while (i < swap->nb_numb)
		swap->tab_distance_b2[i++] = -1;
//	test_radix(swap, 2, 'b');
}
