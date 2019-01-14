/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:42:52 by sgarcia           #+#    #+#             */
/*   Updated: 2019/01/14 17:47:53 by sgarcia          ###   ########.fr       */
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
			i++;
			elem = elem->next;
		}
		elem = first;
		while (elem && elem != min)
		{
			elem->pos_current = i;
			i++;
			elem = elem->next;
		}
	}
}

static void		calc_tab_distance_a2(t_swap *swap, t_val *elem, int *i)
{
	while (elem)
	{
		swap->tab_distance_a[*i] = absolue(elem->pos_current - elem->pos_final);
		if (swap->tab_distance_a[*i] > swap->mid_a)
			swap->tab_distance_a[*i] =
				swap->length_a - absolue(elem->pos_current - elem->pos_final);
		swap->total_distance_a += swap->tab_distance_a[*i];
		elem = elem->next;
		(*i)++;
	}
}

void			calc_tab_distance_a1(t_swap *swap, int i, int check)
{
	swap->total_distance_a = 0;
	if (check == 0)
	{
		swap->mid_a = swap->length_a / 2;
		calc_pos_current(swap->sort_final_a, swap->val_a);
	}
	calc_tab_distance_a2(swap, swap->val_a, &i);
	while (i < swap->nb_numb)
		swap->tab_distance_a[i++] = -1;
}

static void		calc_tab_distance_b2(t_swap *swap, t_val *elem, int *i)
{
	while (elem)
	{
		swap->tab_distance_b[*i] = absolue(elem->pos_current - elem->pos_final);
		if (swap->tab_distance_b[*i] > swap->mid_b)
			swap->tab_distance_b[*i] =
				swap->length_b - absolue(elem->pos_current - elem->pos_final);
		swap->total_distance_b += swap->tab_distance_b[*i];
		elem = elem->next;
		(*i)++;
	}
}

void			calc_tab_distance_b1(t_swap *swap, int i, int check)
{
	swap->total_distance_b = 0;
	if (check == 0)
	{
		swap->mid_b = swap->length_b / 2;
		calc_pos_current(swap->sort_final_b, swap->val_b);
	}
	calc_tab_distance_b2(swap, swap->val_b, &i);
	while (i < swap->nb_numb)
		swap->tab_distance_b[i++] = -1;
}
