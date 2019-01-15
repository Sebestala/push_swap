/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:43:07 by sgarcia           #+#    #+#             */
/*   Updated: 2019/01/15 18:26:22 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				is_ss_3(t_swap *swap, int i, int res, int res2)
{
	res2 = absolue(swap->val_a->pos_current - swap->val_a->next->pos_final);
	if (res2 > swap->mid_a)
		res2 = swap->length_a - absolue(swap->val_a->pos_current -
				swap->val_a->next->pos_final);
	res = res2;
	res2 = absolue(swap->val_a->next->pos_current - swap->val_a->pos_final);
	if (res2 > swap->mid_a)
		res2 = swap->length_a - absolue(swap->val_a->next->pos_current -
				swap->val_a->pos_final);
	res += res2;
	if ((swap->tab_distance_a[0] + swap->tab_distance_a[1]) - res > 0)
		i++;
	return (i);
}

int				is_ss_2(t_swap *swap, int i, int res, int res2)
{
	res = swap->total_distance_a2;
	res2 = swap->check_act2;
	sa2(swap);
	radix2(swap, 'a', 0);
	calc_tab_distance_a1_2(swap, 0, 0);
	if (res - swap->total_distance_a2 > 0)
		i++;
	sa2(swap);
	radix2(swap, 'a', 0);
	calc_tab_distance_a1_2(swap, 0, 0);
	swap->check_act2 = res2;
	return (i);
}

int				is_ss(t_swap *swap)
{
	int		res;
	int		res2;
	int		i;

	i = 0;
	res = 0;
	if (swap->check_act != SA && swap->val_a->next && swap->val_a->pos_final !=
			swap->length_a && swap->val_a->next->pos_final == 1)
		i = is_ss_2(swap, i, 0, 0);
	else if (swap->check_act != SA && swap->val_a->next)
		i = is_ss_3(swap, i, 0, 0);
	if (swap->check_act != SB && swap->val_b && swap->val_b->next &&
swap->val_b->pos_final != swap->length_b && swap->val_b->next->pos_final == 1)
		i = is_ss_4(swap, i, &res, 0);
	else if (swap->check_act != SB && swap->val_b && swap->val_b->next)
		i = is_ss_5(swap, i, &res, 0);
	if (swap->check_act != SB && i < 5 && swap->val_b && swap->val_b->next &&
			swap->val_b->pos_current != 1 && swap->val_b->next->pos_current !=
			1 && swap->val_b->val < swap->val_b->next->val &&
			(swap->tab_distance_b[0] + swap->tab_distance_b[1]) - res == 0)
		i += 5;
	i = is_ss_6(swap, i);
	return (i);
}

static int		do_ss_2(t_val *val, int *tab, int len, int total)
{
	int		i;

	i = 0;
	while (val)
	{
		tab[i] = absolue(val->pos_current - val->pos_final);
		if (tab[i] > len / 2)
			tab[i] = len - absolue(val->pos_current - val->pos_final);
		total += tab[i];
		val = val->next;
		i++;
	}
	return (i);
}

void			do_ss(t_val *val, int *tab, int len, t_swap *swap)
{
	int		nb;
	int		total;
	int		i;

	i = 0;
	nb = val->pos_current;
	val->pos_current = val->next->pos_current;
	val->next->pos_current = nb;
	if (val && val->next && (val->pos_current == 1 ||
				val->next->pos_current == 1))
	{
		if (val == swap->val_a)
			calc_tab_distance_a1(swap, 0, 0);
		if (val == swap->val_b)
			calc_tab_distance_b1(swap, 0, 0);
		return ;
	}
	if (val == swap->val_a)
		total = swap->total_distance_a;
	if (val == swap->val_b)
		total = swap->total_distance_b;
	i = do_ss_2(val, tab, len, total);
	while (i < swap->nb_numb)
		tab[i++] = -1;
}
