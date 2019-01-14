/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:43:23 by sgarcia           #+#    #+#             */
/*   Updated: 2019/01/14 18:09:13 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		find_ra_rrb2(t_swap *swap)
{
	clean_result(swap);
	swap->res1 = swap->b + swap->a;
	swap->ra = swap->a;
	swap->rrb = swap->b;
}

void			find_ra_rrb(t_swap *swap, t_val *el, t_val *el2, t_val *back)
{
	while (swap->a < swap->res1 || swap->res1 == 0)
	{
		if (!el2 || (swap->b + swap->a >= swap->res1 && swap->res1 != 0))
		{
			back = el;
			el = el->next;
			el2 = swap->val_b;
			swap->b = 0;
			swap->a++;
		}
		if (!el || !el2)
			break ;
		if (el2->val > back->val && (el2->val < el->val ||
			el->pos_final_sort == 1) && swap->a + swap->b < swap->res1)
			find_ra_rrb2(swap);
		if (el2 == swap->val_b && swap->val_b_last != el2)
			el2 = swap->val_b_last;
		else
			el2 = el2->back;
		swap->b++;
	}
}

static void		find_ra_rb2(t_swap *swap)
{
	clean_result(swap);
	if (swap->a < swap->b)
	{
		swap->res1 = swap->b;
		swap->rr = swap->a;
		swap->rb = swap->b - swap->a;
	}
	else
	{
		swap->res1 = swap->a;
		swap->rr = swap->b;
		swap->ra = swap->a - swap->b;
	}
}

void			find_ra_rb(t_swap *swap, t_val *el, t_val *el2, t_val *back)
{
	while (swap->a < swap->res1 || swap->res1 == 0)
	{
		if (!el2 || (swap->b >= swap->res1 && swap->res1 != 0))
		{
			back = el;
			el = el->next;
			el2 = swap->val_b;
			swap->b = 0;
			swap->a++;
		}
		if (!el || !el2)
			break ;
		if (el2->val > back->val && (el2->val < el->val ||
	el->pos_final_sort == 1) && (swap->a < swap->res1 && swap->b < swap->res1))
			find_ra_rb2(swap);
		el2 = el2->next;
		swap->b++;
	}
}
