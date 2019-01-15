/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:45:37 by sgarcia           #+#    #+#             */
/*   Updated: 2019/01/15 18:41:50 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		sa2(t_swap *swap)
{
	t_val	*element1;
	t_val	*element2;

	if (swap->val_a2 && swap->val_a2->next)
	{
		element2 = swap->val_a2->next;
		if (element2->next)
		{
			element1 = element2->next;
			element1->back = swap->val_a2;
			swap->val_a2->next = element1;
		}
		else
		{
			swap->val_a_last2 = swap->val_a2;
			swap->val_a2->next = NULL;
		}
		element2->back = NULL;
		element2->next = swap->val_a2;
		swap->val_a2->back = element2;
		swap->val_a2 = element2;
	}
	swap->check_act2 = SA;
}

void		sa(t_swap *swap)
{
	t_val	*element1;
	t_val	*element2;

	if (swap->val_a && swap->val_a->next)
	{
		element2 = swap->val_a->next;
		if (element2->next)
		{
			element1 = element2->next;
			element1->back = swap->val_a;
			swap->val_a->next = element1;
		}
		else
		{
			swap->val_a_last = swap->val_a;
			swap->val_a->next = NULL;
		}
		element2->back = NULL;
		element2->next = swap->val_a;
		swap->val_a->back = element2;
		swap->val_a = element2;
	}
	swap->check_act = SA;
	sa2(swap);
}

void		sb2(t_swap *swap)
{
	t_val	*element1;
	t_val	*element2;

	if (swap->val_b2 && swap->val_b2->next)
	{
		element2 = swap->val_b2->next;
		if (element2->next)
		{
			element1 = element2->next;
			element1->back = swap->val_b2;
			swap->val_b2->next = element1;
		}
		else
		{
			swap->val_b_last2 = swap->val_b2;
			swap->val_b2->next = NULL;
		}
		element2->back = NULL;
		element2->next = swap->val_b2;
		swap->val_b2->back = element2;
		swap->val_b2 = element2;
	}
	swap->check_act2 = SB;
}

void		sb(t_swap *swap)
{
	t_val	*element1;
	t_val	*element2;

	if (swap->val_b && swap->val_b->next)
	{
		element2 = swap->val_b->next;
		if (element2->next)
		{
			element1 = element2->next;
			element1->back = swap->val_b;
			swap->val_b->next = element1;
		}
		else
		{
			swap->val_b_last = swap->val_b;
			swap->val_b->next = NULL;
		}
		element2->back = NULL;
		element2->next = swap->val_b;
		swap->val_b->back = element2;
		swap->val_b = element2;
	}
	swap->check_act = SB;
	sb2(swap);
}

void		ss2(t_swap *swap)
{
	sa2(swap);
	sb2(swap);
	swap->check_act2 = SS;
}
