/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:43:07 by sgarcia           #+#    #+#             */
/*   Updated: 2019/01/15 18:16:38 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			is_rr_or_rrr3(t_swap *swap)
{
	if (swap->point_next >= swap->point_back)
		swap->rr = swap->length_a / 2 + swap->length_a % 2;
	else
		swap->rrr = swap->length_a / 2;
}

void			is_rr_or_rrr2_2(t_swap *swap, int mid)
{
	calc_tab_distance_a1_2(swap, 0, 1);
	calc_tab_distance_b1_2(swap, 0, 1);
	mid = swap->total_distance_a - swap->total_distance_a2;
	if (mid > 0)
		swap->point_back += mid;
	mid = (swap->total_distance_b - swap->total_distance_b2) / 2;
	if (mid > 0)
		swap->point_back += mid;
	write_clone(swap, swap->val_a_last2);
	is_rr_or_rrr3(swap);
}

void			is_rr_or_rrr2(t_swap *swap, int mid)
{
	mid = swap->length_a / 2;
	while (mid > 0)
	{
		if (swap->check_act2 != PB && swap->val_b2 && is_pa2(swap))
		{
			pa2(swap, NULL, NULL);
			swap->point_back += 2;
		}
		else if (swap->check_act2 != PA && is_pb2(swap))
			swap->point_back += 1;
		else if (is_ss2(swap, 0, 0, 0))
			swap->c = swap->c;
		else if (swap->check_act2 != RB && is_rrb2(swap))
			swap->c = swap->c;
		else if (swap->check_act2 != RRB && is_rb2(swap))
			swap->c = swap->c;
		else
		{
			rrr2(swap);
			mid--;
		}
		is_radix2(swap);
	}
	is_rr_or_rrr2_2(swap, mid);
}

void			is_rr_or_rrr_02(t_swap *swap, int mid)
{
	while (mid > 0)
	{
		if (swap->check_act2 != PB && swap->val_b2 && is_pa2(swap))
		{
			pa2(swap, NULL, NULL);
			swap->point_next += 2;
		}
		else if (swap->check_act2 != PA && is_pb2(swap))
			swap->point_next += 2;
		else if (is_ss2(swap, 0, 0, 0))
			swap->c = swap->c;
		else if (swap->check_act2 != RB && is_rrb2(swap))
			swap->c = swap->c;
		else if (swap->check_act2 != RRB && is_rb2(swap))
			swap->c = swap->c;
		else
		{
			rr2(swap);
			mid--;
		}
		is_radix2(swap);
	}
}

void			is_rr_or_rrr(t_swap *swap)
{
	int		mid;

	mid = swap->length_a / 2 + swap->length_a % 2;
	swap->point_next = 0;
	swap->point_back = 0;
	swap->length_a2 = swap->length_a;
	swap->length_b2 = swap->length_b;
	is_rr_or_rrr_02(swap, mid);
	calc_tab_distance_a1_2(swap, 0, 1);
	calc_tab_distance_b1_2(swap, 0, 1);
	mid = swap->total_distance_a - swap->total_distance_a2;
	if (mid > 0)
		swap->point_next += mid;
	mid = (swap->total_distance_b - swap->total_distance_b2) / 2;
	if (mid > 0)
		swap->point_next += mid;
	write_clone(swap, swap->val_a_last2);
	is_rr_or_rrr2(swap, 0);
}
