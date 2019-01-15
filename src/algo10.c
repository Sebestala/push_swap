/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo10.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:43:15 by sgarcia           #+#    #+#             */
/*   Updated: 2019/01/15 18:46:21 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				is_rrb(t_swap *swap)
{
	int res;

	if (swap->val_b && swap->val_b->next)
	{
		res = swap->check_act;
		rrb(swap);
		calc_tab_distance_b1(swap, 0, 1);
		if (is_pa(swap))
			return (TRUE);
		rb(swap);
		swap->check_act = res;
		calc_tab_distance_b1(swap, 0, 1);
	}
	return (FALSE);
}

int				is_rb(t_swap *swap)
{
	int res;

	if (swap->val_b && swap->val_b->next)
	{
		res = swap->check_act;
		rb(swap);
		calc_tab_distance_b1(swap, 0, 1);
		if (is_pa(swap))
			return (TRUE);
		rrb(swap);
		swap->check_act = res;
		calc_tab_distance_b1(swap, 0, 1);
	}
	return (FALSE);
}

int				is_rrb2(t_swap *swap)
{
	int res;

	if (swap->val_b2 && swap->val_b2->next)
	{
		res = swap->check_act2;
		rrb2(swap);
		calc_tab_distance_b1_2(swap, 0, 1);
		if (is_pa2(swap))
			return (TRUE);
		rb2(swap);
		swap->check_act2 = res;
		calc_tab_distance_b1_2(swap, 0, 1);
	}
	return (FALSE);
}

int				is_rb2(t_swap *swap)
{
	int res;

	if (swap->val_b2 && swap->val_b2->next)
	{
		res = swap->check_act2;
		rb2(swap);
		calc_tab_distance_b1_2(swap, 0, 1);
		if (is_pa2(swap))
			return (TRUE);
		rrb2(swap);
		swap->check_act2 = res;
		calc_tab_distance_b1_2(swap, 0, 1);
	}
	return (FALSE);
}

int				is_pb2(t_swap *swap)
{
	if (swap->tab_distance_a2[0] < 2)
		return (FALSE);
	pb2(swap);
	return (TRUE);
}
