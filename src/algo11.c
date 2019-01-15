/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:43:15 by sgarcia           #+#    #+#             */
/*   Updated: 2019/01/15 18:46:17 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		is_ss2_5(t_swap *swap, int i, int *res, int res2)
{
	res2 = absolue(swap->val_b2->pos_current - swap->val_b2->next->pos_final);
	if (res2 > swap->mid_b2)
		res2 = swap->length_b2 - absolue(swap->val_b2->pos_current -
				swap->val_b2->next->pos_final);
	*res = res2;
	res2 = absolue(swap->val_b2->next->pos_current - swap->val_b2->pos_final);
	if (res2 > swap->mid_b2)
		res2 = swap->length_b2 - absolue(swap->val_b2->next->pos_current -
				swap->val_b2->pos_final);
	*res += res2;
	if ((swap->tab_distance_b2[0] + swap->tab_distance_b2[1]) - *res > 0)
		i += 5;
	return (i);
}

static int		is_ss2_4(t_swap *swap, int i, int *res, int res2)
{
	*res = swap->total_distance_b2;
	res2 = swap->check_act2;
	sb2(swap);
	radix2(swap, 'b', 0);
	calc_tab_distance_b1_2(swap, 0, 0);
	if (*res - swap->total_distance_b2 > 0)
		i += 5;
	sb2(swap);
	radix2(swap, 'b', 0);
	calc_tab_distance_b1_2(swap, 0, 0);
	swap->check_act2 = res2;
	return (i);
}

static int		is_ss2_3(t_swap *swap, int i, int res, int res2)
{
	res2 = absolue(swap->val_a2->pos_current - swap->val_a2->next->pos_final);
	if (res2 > swap->mid_a2)
		res2 = swap->length_a2 - absolue(swap->val_a2->pos_current -
				swap->val_a2->next->pos_final);
	res = res2;
	res2 = absolue(swap->val_a2->next->pos_current - swap->val_a2->pos_final);
	if (res2 > swap->mid_a2)
		res2 = swap->length_a2 - absolue(swap->val_a2->next->pos_current -
				swap->val_a2->pos_final);
	res += res2;
	if ((swap->tab_distance_a2[0] + swap->tab_distance_a2[1]) - res > 0)
		i++;
	return (i);
}

static int		is_ss2_2(t_swap *swap, int i, int res, int res2)
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

int				is_ss2(t_swap *swap, int res, int res2, int i)
{
	if (swap->check_act2 != SA && swap->val_a2->next && swap->val_a2->pos_final
			!= swap->length_a2 && swap->val_a2->next->pos_final == 1)
		i = is_ss2_2(swap, i, 0, 0);
	else if (swap->check_act2 != SA && swap->val_a2->next)
		i = is_ss2_3(swap, i, 0, 0);
	if (swap->check_act2 != SB && swap->val_b2 && swap->val_b2->next &&
			swap->val_b2->pos_final != swap->length_b2 &&
			swap->val_b2->next->pos_final == 1)
		i = is_ss2_4(swap, i, &res, 0);
	else if (swap->check_act2 != SB && swap->val_b2 && swap->val_b2->next)
		i = is_ss2_5(swap, i, &res, 0);
	if (swap->check_act2 != SB && i < 5 && swap->val_b2 && swap->val_b2->next
	&& swap->val_b2->pos_current != 1 && swap->val_b2->next->pos_current != 1 &&
swap->val_b2->val < swap->val_b2->next->val &&
(swap->tab_distance_b2[0] + swap->tab_distance_b2[1]) - res == 0)
		i += 5;
	if (i == 6)
		ss2(swap);
	else if (i == 5)
		sb2(swap);
	else if (i == 1)
		sa2(swap);
	return (i);
}
