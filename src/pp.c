/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:44:02 by sgarcia           #+#    #+#             */
/*   Updated: 2019/01/15 15:41:11 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		pa2(t_swap *swap, t_val *element1, t_val *element2)
{
	if (swap->val_b2)
	{
		element1 = swap->val_b2;
		element1->radix_next = NULL;
		element1->radix_back = NULL;
		if (swap->val_b_last2 == swap->val_b2)
		{
			swap->val_b_last2 = NULL;
			swap->val_b2 = NULL;
		}
		else
		{
			element2 = swap->val_b2->next;
			element2->back = NULL;
			swap->val_b2 = element2;
		}
		element1->next = swap->val_a2;
		swap->val_a2->back = element1;
		swap->val_a2 = element1;
		swap->length_b2--;
		swap->length_a2++;
	}
	swap->check_act2 = PA;
}

void		pa(t_swap *swap, t_val *element1, t_val *element2)
{
	if (swap->val_b)
	{
		element1 = swap->val_b;
		element1->radix_next = NULL;
		element1->radix_back = NULL;
		if (swap->val_b_last == swap->val_b)
		{
			swap->val_b_last = NULL;
			swap->val_b = NULL;
		}
		else
		{
			element2 = swap->val_b->next;
			element2->back = NULL;
			swap->val_b = element2;
		}
		element1->next = swap->val_a;
		swap->val_a->back = element1;
		swap->val_a = element1;
		swap->length_b--;
		swap->length_a++;
	}
	swap->check_act = PA;
	pa2(swap, NULL, NULL);
}

void		pb2(t_swap *swap)
{
	t_val	*element1;
	t_val	*element2;

	element1 = swap->val_a2;
	element1->radix_next = NULL;
	element1->radix_back = NULL;
	element2 = swap->val_a2->next;
	element2->back = NULL;
	swap->val_a2 = element2;
	element1->next = swap->val_b2;
	if (swap->val_b2)
		swap->val_b2->back = element1;
	else
	{
		swap->val_b_last2 = element1;
		element1->pos_current = 1;
	}
	swap->length_a2--;
	swap->length_b2++;
	swap->val_b2 = element1;
	swap->check_act2 = PB;
}

void		pb(t_swap *swap)
{
	t_val	*element1;
	t_val	*element2;

	element1 = swap->val_a;
	element1->radix_next = NULL;
	element1->radix_back = NULL;
	element2 = swap->val_a->next;
	element2->back = NULL;
	swap->val_a = element2;
	element1->next = swap->val_b;
	if (swap->val_b)
		swap->val_b->back = element1;
	else
	{
		swap->val_b_last = element1;
		element1->pos_current = 1;
	}
	swap->val_b = element1;
	swap->length_a--;
	swap->length_b++;
	swap->check_act = PB;
	pb2(swap);
}
