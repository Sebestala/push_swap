/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:43:40 by sgarcia           #+#    #+#             */
/*   Updated: 2019/01/15 18:38:12 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		free_struct2(t_swap *swap)
{
	t_val	*elem;

	while (swap->val_b)
	{
		elem = swap->val_b;
		swap->val_b = swap->val_b->next;
		free(elem);
	}
	while (swap->val_b2)
	{
		elem = swap->val_b2;
		swap->val_b2 = swap->val_b2->next;
		free(elem);
	}
	free(swap);
}

void		free_struct(t_swap *swap)
{
	t_val	*elem;

	free(swap->tab_neg1);
	free(swap->tab_neg2);
	free(swap->tab_pos1);
	free(swap->tab_pos2);
	while (swap->val_a)
	{
		elem = swap->val_a;
		swap->val_a = swap->val_a->next;
		free(elem);
	}
	while (swap->val_a2)
	{
		elem = swap->val_a2;
		swap->val_a2 = swap->val_a2->next;
		free(elem);
	}
	free(swap->tab_distance_a);
	free(swap->tab_distance_a2);
	free(swap->tab_distance_b);
	free(swap->tab_distance_b2);
	if (swap->line)
		free(swap->line);
	free_struct2(swap);
}

int			test_pile2(t_val *first, t_val *begin)
{
	t_val	*val;
	t_val	*val2;

	val = first;
	while (val)
	{
		val2 = val;
		val = val->next;
		if (val && val2->pos_final > val->pos_final)
			return (FALSE);
	}
	val = begin;
	if (val && val2->pos_final > val->pos_final)
		return (FALSE);
	while (val && val != first)
	{
		val2 = val;
		val = val->next;
		if (val && val != first && val2->pos_final > val->pos_final)
			return (FALSE);
	}
	return (TRUE);
}

t_val		*list_copy(t_val *val)
{
	t_val	*elem;

	elem = memalloc_sterr(sizeof(t_val), "list_copy");
	elem->val = val->val;
	elem->pos_current = val->pos_current;
	elem->pos_final = val->pos_final;
	elem->pos_final_sort = val->pos_final_sort;
	return (elem);
}

void		init_list_copy(t_swap *swap)
{
	t_val	*val;
	t_val	*elem;
	t_val	*elem2;

	val = swap->val_a;
	if (val)
	{
		swap->val_a2 = list_copy(val);
		val = val->next;
	}
	elem = swap->val_a2;
	while (val)
	{
		elem2 = list_copy(val);
		elem->next = elem2;
		elem2->back = elem;
		val = val->next;
		elem = elem2;
	}
	swap->val_a_last2 = elem;
}
