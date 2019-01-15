/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:43:07 by sgarcia           #+#    #+#             */
/*   Updated: 2019/01/15 16:44:57 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		is_radix_02(t_swap *swap)
{
	radix(swap, 'a', 0);
	calc_tab_distance_a1(swap, 0, 0);
	if (swap->val_b)
	{
		radix(swap, 'b', 0);
		calc_tab_distance_b1(swap, 0, 0);
	}
}

void			is_radix(t_swap *swap)
{
	if (swap->check_act == RR || swap->check_act == RRR)
	{
		calc_tab_distance_a1(swap, 0, 1);
		calc_tab_distance_b1(swap, 0, 1);
	}
	else if (swap->check_act == RA || swap->check_act == RRA)
		calc_tab_distance_a1(swap, 0, 1);
	else if (swap->check_act == RB || swap->check_act == RRB)
		calc_tab_distance_b1(swap, 0, 1);
	else if (swap->check_act == SA)
		do_ss(swap->val_a, swap->tab_distance_a, swap->length_a, swap);
	else if (swap->check_act == SB)
		do_ss(swap->val_b, swap->tab_distance_b, swap->length_b, swap);
	else if (swap->check_act == SS)
	{
		do_ss(swap->val_a, swap->tab_distance_a, swap->length_a, swap);
		do_ss(swap->val_b, swap->tab_distance_b, swap->length_b, swap);
	}
	else
		is_radix_02(swap);
	is_radix2(swap);
}

void			algo_2(t_swap *swap)
{
	if (swap->rr == 0 && swap->rrr == 0)
		is_rr_or_rrr(swap);
	if (swap->rr > 0)
	{
		rr(swap);
		swap->line = ft_strncpy(swap->line, "rr", 3);
		swap->rr--;
	}
	else if (swap->rrr > 0)
	{
		rrr(swap);
		swap->line = ft_strncpy(swap->line, "rrr", 3);
		swap->rrr--;
	}
}

void			algo(t_swap *swap)
{
	if (swap->val_a->next->pos_final_sort == 1 &&
			swap->val_a->pos_final != swap->length_a && is_ss(swap))
		swap->c = swap->c;
	else if (swap->check_act != PB && swap->val_b && is_pa(swap))
	{
		pa(swap, NULL, NULL);
		swap->line = ft_strncpy(swap->line, "pa", 3);
	}
	else if (swap->check_act != PA && is_pb(swap))
		swap->line = ft_strncpy(swap->line, "pb", 3);
	else if (test_pile2(swap->sort_final_a, swap->val_a))
		algo3(swap);
	else if (is_ss(swap))
		swap->c = swap->c;
	else if (swap->check_act != RB && is_rrb(swap))
		swap->line = ft_strncpy(swap->line, "rrb", 3);
	else if (swap->check_act != RRB && is_rb(swap))
		swap->line = ft_strncpy(swap->line, "rb", 3);
	else
		algo_2(swap);
	is_radix(swap);
}
