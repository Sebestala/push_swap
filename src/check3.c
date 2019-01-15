/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:43:40 by sgarcia           #+#    #+#             */
/*   Updated: 2019/01/15 18:41:56 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			absolue(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}

void		rr(t_swap *swap)
{
	ra(swap);
	rb(swap);
	swap->check_act = RR;
}

void		rrr(t_swap *swap)
{
	rra(swap);
	rrb(swap);
	swap->check_act = RRR;
}

void		ss(t_swap *swap)
{
	sa(swap);
	sb(swap);
	swap->check_act = SS;
}
