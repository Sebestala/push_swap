/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:43:07 by sgarcia           #+#    #+#             */
/*   Updated: 2019/01/14 19:34:10 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		write_clone2(t_swap *swap)
{
	swap->val2->val = swap->val->val;
	swap->val2->pos_current = swap->val->pos_current;
	swap->val2->pos_final = swap->val->pos_final;
	swap->val2->pos_final_sort = swap->val->pos_final_sort;
}

static void		write_clone_4(t_swap *swap)
{
	if (swap->val_b2)
		swap->val_b_last2 = swap->val2;
	swap->length_a2 = swap->length_a;
	swap->length_b2 = swap->length_b;
	swap->check_act2 = swap->check_act;
	radix2(swap, 'a');
	calc_tab_distance_a1_2(swap, 0, 0);
	if (swap->val_b2)
	{
		radix2(swap, 'b');
		calc_tab_distance_b1_2(swap, 0, 0);
	}
}

static void		write_clone_3(t_swap *swap)
{
	swap->val = swap->val->next;
	if (swap->val)
	{
		if (swap->val2->next == NULL)
		{
			swap->val2->next = swap->elem2;
			swap->elem2->back = swap->val2;
			swap->elem2 = NULL;
		}
		swap->val2 = swap->val2->next;
	}
}

static void		write_clone_2(t_swap *swap)
{
	swap->val_a_last2 = swap->val2;
	if (swap->val_b)
	{
		swap->val = swap->val_b;
		swap->elem = swap->val2;
		if (swap->val2->next)
		{
			swap->val2 = swap->val2->next;
			swap->elem->next = NULL;
			swap->elem2 = swap->val_b2;
			swap->val_b2 = swap->val2;
			swap->val2->back = NULL;
		}
		else
			swap->val2 = swap->val_b2;
	}
	else
	{
		swap->val = swap->val->next;
		swap->val_b_last2 = NULL;
		swap->val_b2 = NULL;
	}
}

void			write_clone(t_swap *swap, t_val *elem3)
{
	swap->val = swap->val_a;
	swap->val2 = swap->val_a2;
	swap->elem = NULL;
	swap->elem2 = NULL;
	while (swap->val)
	{
		write_clone2(swap);
		if (swap->val == swap->val_a_last)
			write_clone_2(swap);
		else if (swap->val2 == swap->val_a_last2)
		{
			swap->val2->next = swap->val_b2;
			swap->val_b2->back = swap->val2;
			swap->val2 = swap->val2->next;
			swap->val = swap->val->next;
		}
		else
			write_clone_3(swap);
	}
	write_clone_4(swap);
}
