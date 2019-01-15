/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:44:14 by sgarcia           #+#    #+#             */
/*   Updated: 2019/01/15 15:49:35 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		radix_merge(t_tab *tab1, t_tab *tab2, t_swap *swap, char c)
{
	t_val	*val;
	t_val	*element;

	val = tab1->tab[0];
	while (val)
	{
		element = val->radix_next;
		val->radix_next = tab2->tab[0];
		tab2->tab[0] = val;
		tab1->tab[0] = element;
		val = tab1->tab[0];
	}
	if (c == 'a')
		swap->sort_final_a2 = tab2->tab[0];
	else
		swap->sort_final_b2 = tab2->tab[0];
	element = tab2->tab[0];
	if (element)
		element->radix_back = NULL;
}

static void		radix_sort_pos_and_neg(t_swap *swap, char c, int *i)
{
	t_val	*val;

	if (c == 'a')
		val = swap->val_a2;
	else
		val = swap->val_b2;
	while (val)
	{
		val->radix_back = NULL;
		val->radix_next = NULL;
		if (val->val > swap->biggest)
			swap->biggest = val->val;
		else if (val->val < swap->smallest)
			swap->smallest = val->val;
		if (val->val < 0)
			radix_put_val_at_end_list(val, swap->tab_neg1->tab, val->val % 10);
		else
			radix_put_val_at_end_list(val, swap->tab_pos1->tab, val->val % 10);
		val = val->next;
	}
	while (swap->smallest != 0)
	{
		swap->smallest /= 10;
		(*i)++;
	}
}

static void		make_pos_final2(t_swap *swap, char c, t_val *elem)
{
	t_val	*elem3;
	t_val	*elem2;
	int		i;

	i = 0;
	elem3 = NULL;
	while (elem)
	{
		elem2 = elem;
		elem = elem->radix_back;
		i++;
		elem2->pos_final = i;
		elem2->radix_next = elem;
		elem2->radix_back = elem3;
		elem3 = elem2;
	}
}

static void		make_pos_final(t_swap *swap, char c)
{
	t_val	*elem;
	t_val	*elem2;
	int		i;

	i = 1;
	if (c == 'b')
		elem = swap->sort_final_b2;
	else
		elem = swap->sort_final_a2;
	elem->pos_final = i;
	while (elem->radix_next != NULL)
	{
		elem2 = elem;
		elem = elem->radix_next;
		elem->radix_back = elem2;
		i++;
		elem->pos_final = i;
	}
	if (c == 'b')
	{
		swap->sort_final_b2 = elem;
		make_pos_final2(swap, c, elem);
	}
}

void			radix2(t_swap *swap, char c, int i)
{
	radix_zero(swap);
	radix_sort_pos_and_neg(swap, c, &i);
	radix_sort_algo(swap->tab_neg1, swap->tab_neg2, i);
	while (swap->biggest > 0)
	{
		swap->biggest /= 10;
		i++;
	}
	radix_sort_algo(swap->tab_pos1, swap->tab_pos2, i);
	if (swap->tab_neg1->check == 1)
		i = 1;
	else
		i = 0;
	if (swap->tab_pos1->check == 1 && i == 1)
		radix_merge(swap->tab_neg1, swap->tab_pos1, swap, c);
	else if (swap->tab_pos2->check == 1 && i == 1)
		radix_merge(swap->tab_neg1, swap->tab_pos2, swap, c);
	else if (swap->tab_pos1->check == 1 && i == 0)
		radix_merge(swap->tab_neg2, swap->tab_pos1, swap, c);
	else if (swap->tab_pos2->check == 1 && i == 0)
		radix_merge(swap->tab_neg2, swap->tab_pos2, swap, c);
	make_pos_final(swap, c);
}
