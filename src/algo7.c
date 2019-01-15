/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:43:07 by sgarcia           #+#    #+#             */
/*   Updated: 2019/01/15 15:59:14 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				is_pb(t_swap *swap)
{
	if (swap->tab_distance_a[0] < 2)
		return (FALSE);
	pb(swap);
	return (TRUE);
}

int				is_pa(t_swap *swap)
{
	t_val	*val;
	int		pos;
	int		i;

	val = swap->val_a;
	pos = 0;
	while (val)
	{
		if (swap->val_b->val > val->val && pos <= val->pos_final)
			pos = val->pos_final + 1;
		val = val->next;
	}
	if (pos == 0)
		pos = swap->length_a + 1;
	if (swap->val_a->pos_current == 1)
		i = swap->length_a + 1;
	else
		i = swap->val_a->pos_current;
	if (absolue(i - pos) == 0)
		return (TRUE);
	return (FALSE);
}

int				is_ss_6(t_swap *swap, int i)
{
	if (i == 6)
	{
		ss(swap);
		swap->line = ft_strncpy(swap->line, "ss", 3);
	}
	else if (i == 5)
	{
		sb(swap);
		swap->line = ft_strncpy(swap->line, "sb", 3);
	}
	else if (i == 1)
	{
		sa(swap);
		swap->line = ft_strncpy(swap->line, "sa", 3);
	}
	return (i);
}

int				is_ss_5(t_swap *swap, int i, int *res, int res2)
{
	res2 = absolue(swap->val_b->pos_current - swap->val_b->next->pos_final);
	if (res2 > swap->mid_b)
		res2 = swap->length_b - absolue(swap->val_b->pos_current -
				swap->val_b->next->pos_final);
	*res = res2;
	res2 = absolue(swap->val_b->next->pos_current - swap->val_b->pos_final);
	if (res2 > swap->mid_b)
		res2 = swap->length_b - absolue(swap->val_b->next->pos_current -
				swap->val_b->pos_final);
	*res += res2;
	if ((swap->tab_distance_b[0] + swap->tab_distance_b[1]) - *res > 0)
		i += 5;
	return (i);
}

int				is_ss_4(t_swap *swap, int i, int *res, int res2)
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
