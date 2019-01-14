/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_distance2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:43:32 by sgarcia           #+#    #+#             */
/*   Updated: 2019/01/14 17:48:21 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		swap->tab_distance_a2[*i] =
			absolue(elem->pos_current - elem->pos_final);
		if (swap->tab_distance_a2[*i] > swap->mid_a2)
			swap->tab_distance_a2[*i] =
				swap->length_a2 - absolue(elem->pos_current - elem->pos_final);
		swap->total_distance_a2 += swap->tab_distance_a2[*i];
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
}

static void		calc_tab_distance_b2(t_swap *swap, t_val *elem, int *i)
{
	while (elem)
	{
		swap->tab_distance_b2[*i] =
			absolue(elem->pos_current - elem->pos_final);
		if (swap->tab_distance_b2[*i] > swap->mid_b2)
			swap->tab_distance_b2[*i] =
				swap->length_b2 - absolue(elem->pos_current - elem->pos_final);
		swap->total_distance_b2 += swap->tab_distance_b2[*i];
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
		calc_pos_current(swap->sort_final_b2, swap->val_b2);
	}
	calc_tab_distance_b2(swap, swap->val_b2, &i);
	while (i < swap->nb_numb)
		swap->tab_distance_b2[i++] = -1;
}
