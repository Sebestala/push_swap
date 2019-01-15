/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:43:23 by sgarcia           #+#    #+#             */
/*   Updated: 2019/01/15 15:52:17 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			clean_result(t_swap *swap)
{
	swap->ra = 0;
	swap->rb = 0;
	swap->rr = 0;
	swap->rra = 0;
	swap->rrb = 0;
	swap->rrr = 0;
}

static void		find_end(t_swap *swap)
{
	t_val	*el;
	int		i;

	el = swap->val_a;
	i = 0;
	while (el && el->pos_final_sort != 1)
	{
		el = el->next;
		i++;
	}
	if (i <= swap->length_a / 2 + swap->length_a % 2)
	{
		swap->ra = i - 1;
		ra(swap);
		swap->line = ft_strncpy(swap->line, "ra", 3);
	}
	else
	{
		swap->rra = i - 1;
		rra(swap);
		swap->line = ft_strncpy(swap->line, "rra", 3);
	}
}

static void		algo3_3(t_swap *swap)
{
	if (swap->rb > 0)
	{
		rb(swap);
		swap->line = ft_strncpy(swap->line, "rb", 3);
		swap->rb--;
	}
	else if (swap->rra > 0)
	{
		rra(swap);
		swap->line = ft_strncpy(swap->line, "rra", 3);
		swap->rra--;
	}
	else if (swap->rrb > 0)
	{
		rrb(swap);
		swap->line = ft_strncpy(swap->line, "rrb", 3);
		swap->rrb--;
	}
	else
		find_end(swap);
}

static void		algo3_2(t_swap *swap)
{
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
	else if (swap->ra > 0)
	{
		ra(swap);
		swap->line = ft_strncpy(swap->line, "ra", 3);
		swap->ra--;
	}
	else
		algo3_3(swap);
}

void			algo3(t_swap *swap)
{
	if (swap->is_sort == 0 || (swap->is_sort == 1 && !swap->val_b))
	{
		clean_result(swap);
		swap->is_sort++;
	}
	if (swap->ra == 0 && swap->rb == 0 && swap->rr == 0 &&
			swap->rra == 0 && swap->rrb == 0 && swap->rrr == 0)
	{
		swap->res1 = 9999;
		swap->a = 0;
		swap->b = 0;
		find_ra_rb(swap, swap->val_a, swap->val_b, swap->val_a_last);
		swap->a = 0;
		swap->b = 0;
		find_rra_rrb(swap, swap->val_a_last, swap->val_b, swap->val_a);
		swap->a = 0;
		swap->b = 0;
		find_ra_rrb(swap, swap->val_a, swap->val_b, swap->val_a_last);
		swap->a = 0;
		swap->b = 0;
		find_rra_rb(swap, swap->val_a_last, swap->val_b, swap->val_a);
	}
	algo3_2(swap);
}
