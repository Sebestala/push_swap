
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
		if (swap->tab_distance_a2[*i] > swap->mid_a)
			swap->tab_distance_a2[*i] = swap->length_a - absolue(elem->pos_current - elem->pos_final);
		swap->total_distance_a2 += swap->tab_distance_a2[*i];
//printf("A2 i = %d   val = %d    pos_current = %d  final = %d    total_distance = %d  \n", *i, elem->val, elem->pos_current, elem->pos_final, swap->total_distance_a2);
		elem = elem->next;
		(*i)++;
	}
}

void			calc_tab_distance_a1_2(t_swap *swap, int i)
{
	t_val	*elem;

	if (swap->val_a2)
	{
		swap->total_distance_a2 = 0;
		elem = swap->val_a2;
		calc_pos_current(swap->sort_final_a2, swap->val_a2);
		calc_tab_distance_a2(swap, elem, &i);
		while (i < swap->nb_numb)
		{
//printf(" i = %d  \n", i);
//fflush(stdout);
			swap->tab_distance_a2[i++] = -1;
			}
	}
}

static void		calc_tab_distance_b2(t_swap *swap, t_val *elem, int *i)
{
	while (elem)
	{
		swap->tab_distance_b2[*i] = absolue(elem->pos_current - elem->pos_final);
		if (swap->tab_distance_b2[*i] > swap->mid_b)
			swap->tab_distance_b2[*i] = swap->length_b - absolue(elem->pos_current - elem->pos_final);
		swap->total_distance_b2 += swap->tab_distance_b2[*i];
		elem = elem->next;
		(*i)++;
	}
}

void			calc_tab_distance_b1_2(t_swap *swap, int i)
{
	t_val	*elem;

	if (swap->val_b2)
	{
		swap->total_distance_b2 = 0;
		elem = swap->sort_final_b2;
		calc_pos_current(swap->sort_final_b2, swap->val_b2);
		calc_tab_distance_b2(swap, elem, &i);
		while (i < swap->nb_numb)
			swap->tab_distance_b2[i++] = -1;
	}
}
