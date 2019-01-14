/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:45:11 by sgarcia           #+#    #+#             */
/*   Updated: 2019/01/14 17:45:21 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ra2(t_swap *swap)
{
	t_val	*element1;

	if (swap->val_a2)
	{
		swap->val_a2->back = swap->val_a_last2;
		swap->val_a_last2->next = swap->val_a2;
		element1 = swap->val_a2->next;
		element1->back = NULL;
		swap->val_a_last2 = swap->val_a2;
		swap->val_a2 = element1;
		swap->val_a_last2->next = NULL;
	}
	swap->check_act2 = RA;
}

void		ra(t_swap *swap)
{
	t_val	*element1;

	if (swap->val_a)
	{
		swap->val_a->back = swap->val_a_last;
		swap->val_a_last->next = swap->val_a;
		element1 = swap->val_a->next;
		element1->back = NULL;
		swap->val_a_last = swap->val_a;
		swap->val_a = element1;
		swap->val_a_last->next = NULL;
	}
	swap->check_act = RA;
	ra2(swap);
}

void		rb2(t_swap *swap)
{
	t_val	*element1;

	if (swap->val_b2)
	{
		swap->val_b2->back = swap->val_b_last2;
		swap->val_b_last2->next = swap->val_b2;
		element1 = swap->val_b2->next;
		element1->back = NULL;
		swap->val_b_last2 = swap->val_b2;
		swap->val_b2 = element1;
		swap->val_b_last2->next = NULL;
	}
	swap->check_act2 = RB;
}

void		rb(t_swap *swap)
{
	t_val	*element1;

	if (swap->val_b)
	{
		swap->val_b->back = swap->val_b_last;
		swap->val_b_last->next = swap->val_b;
		element1 = swap->val_b->next;
		element1->back = NULL;
		swap->val_b_last = swap->val_b;
		swap->val_b = element1;
		swap->val_b_last->next = NULL;
	}
	swap->check_act = RB;
	rb2(swap);
}

void		rr2(t_swap *swap)
{
	ra2(swap);
	rb2(swap);
	swap->check_act2 = RR;
}

void		rr(t_swap *swap)
{
	ra(swap);
	rb(swap);
	swap->check_act = RR;
}
