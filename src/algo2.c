/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:43:15 by sgarcia           #+#    #+#             */
/*   Updated: 2019/01/15 18:48:44 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				is_pa2(t_swap *swap)
{
	t_val	*val;
	int		pos;
	int		i;

	val = swap->val_a2;
	pos = 0;
	while (val)
	{
		if (swap->val_b2->val > val->val && pos <= val->pos_final)
			pos = val->pos_final + 1;
		val = val->next;
	}
	if (pos == 0)
		pos = swap->length_a2 + 1;
	if (swap->val_a2->pos_current == 1)
		i = swap->length_a2 + 1;
	else
		i = swap->val_a2->pos_current;
	if (absolue(i - pos) == 0)
		return (TRUE);
	return (FALSE);
}

void			do_ss2(t_val *val, int *tab, int len, t_swap *swap)
{
	int		nb;
	int		total;
	int		i;

	i = 0;
	nb = val->pos_current;
	val->pos_current = val->next->pos_current;
	val->next->pos_current = nb;
	if (val == swap->val_a2)
		total = swap->total_distance_a2;
	if (val == swap->val_b2)
		total = swap->total_distance_b2;
	while (val)
	{
		tab[i] = absolue(val->pos_current - val->pos_final);
		if (tab[i] > len / 2)
			tab[i] = len - absolue(val->pos_current - val->pos_final);
		total += tab[i];
		val = val->next;
		i++;
	}
	while (i < swap->nb_numb)
		tab[i++] = -1;
}

void			is_radix2_2(t_swap *swap)
{
	radix2(swap, 'a', 0);
	calc_tab_distance_a1_2(swap, 0, 0);
	if (swap->val_b2)
	{
		radix2(swap, 'b', 0);
		calc_tab_distance_b1_2(swap, 0, 0);
	}
}

void			is_radix2(t_swap *swap)
{
	if (swap->check_act2 == RR || swap->check_act2 == RRR)
	{
		calc_tab_distance_a1_2(swap, 0, 1);
		calc_tab_distance_b1_2(swap, 0, 1);
	}
	else if (swap->check_act2 == RA || swap->check_act2 == RRA)
		calc_tab_distance_a1_2(swap, 0, 1);
	else if (swap->check_act2 == RB || swap->check_act2 == RRB)
		calc_tab_distance_b1_2(swap, 0, 1);
	else if (swap->check_act2 == SA)
		do_ss2(swap->val_a2, swap->tab_distance_a2, swap->length_a2, swap);
	else if (swap->check_act2 == SB)
		do_ss2(swap->val_b2, swap->tab_distance_b2, swap->length_b2, swap);
	else if (swap->check_act2 == SS)
	{
		do_ss2(swap->val_a2, swap->tab_distance_a2, swap->length_a2, swap);
		do_ss2(swap->val_b2, swap->tab_distance_b2, swap->length_b2, swap);
	}
	else
		is_radix2_2(swap);
}
