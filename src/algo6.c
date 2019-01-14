/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:43:07 by sgarcia           #+#    #+#             */
/*   Updated: 2019/01/14 21:42:43 by sgarcia          ###   ########.fr       */
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
	radix2(swap, 'b');
	calc_tab_distance_b1_2(swap, 0, 0);
	if (*res - swap->total_distance_b2 > 0)
		i += 5;
	sb2(swap);
	radix2(swap, 'b');
	calc_tab_distance_b1_2(swap, 0, 0);
	swap->check_act2 = res2;
	return (i);
}

int				is_ss_3(t_swap *swap, int i, int res, int res2)
{
	res2 = absolue(swap->val_a->pos_current - swap->val_a->next->pos_final);
	if (res2 > swap->mid_a)
		res2 = swap->length_a - absolue(swap->val_a->pos_current -
				swap->val_a->next->pos_final);
	res = res2;
	res2 = absolue(swap->val_a->next->pos_current - swap->val_a->pos_final);
	if (res2 > swap->mid_a)
		res2 = swap->length_a - absolue(swap->val_a->next->pos_current -
				swap->val_a->pos_final);
	res += res2;
	if ((swap->tab_distance_a[0] + swap->tab_distance_a[1]) - res > 0)
		i++;
	return (i);
}

int				is_ss_2(t_swap *swap, int i, int res, int res2)
{
	res = swap->total_distance_a2;
	res2 = swap->check_act2;
	sa2(swap);
	radix2(swap, 'a');
	calc_tab_distance_a1_2(swap, 0, 0);
	if (res - swap->total_distance_a2 > 0)
		i++;
	sa2(swap);
	radix2(swap, 'a');
	calc_tab_distance_a1_2(swap, 0, 0);
	swap->check_act2 = res2;
	return (i);
}

int				is_ss(t_swap *swap)
{
	int		res;
	int		res2;
	int		i;

	i = 0;
	res = 0;
	if (swap->check_act != SA && swap->val_a->next && swap->val_a->pos_final !=
			swap->length_a && swap->val_a->next->pos_final == 1)
		i = is_ss_2(swap, i, 0, 0);
	else if (swap->check_act != SA && swap->val_a->next)
		i = is_ss_3(swap, i, 0, 0);
	if (swap->check_act != SB && swap->val_b && swap->val_b->next &&
swap->val_b->pos_final != swap->length_b && swap->val_b->next->pos_final == 1)
		i = is_ss_4(swap, i, &res, 0);
	else if (swap->check_act != SB && swap->val_b && swap->val_b->next)
		i = is_ss_5(swap, i, &res, 0);
	if (swap->check_act != SB && i < 5 && swap->val_b && swap->val_b->next &&
			swap->val_b->pos_current != 1  && swap->val_b->next->pos_current !=
			1 && swap->val_b->val < swap->val_b->next->val &&
			(swap->tab_distance_b[0] + swap->tab_distance_b[1]) - res == 0)
		i += 5;
	i = is_ss_6(swap, i);
	return (i);
}

void			do_ss(t_val *val, int *tab, int len, t_swap *swap)
{
	int		nb;
	int		total;
	int		i;

	i = 0;
	nb = val->pos_current;
	val->pos_current = val->next->pos_current;
	val->next->pos_current = nb;
	if (val && val->next && (val->pos_current == 1 || val->next->pos_current == 1))
	{
		if (val == swap->val_a)
			calc_tab_distance_a1(swap, 0, 0);
		if (val == swap->val_b)
			calc_tab_distance_b1(swap, 0, 0);
		return ;
	}
	if (val == swap->val_a)
		total = swap->total_distance_a;
	if (val == swap->val_b)
		total = swap->total_distance_b;
	while (val)
	{
		tab[i] = absolue(val->pos_current - val->pos_final);
		if (tab[i] > len / 2)
			tab[i] = len - absolue(val->pos_current - val->pos_final);
		total += tab[i];
		val = val->next;
		i++;
	}
	while (i < swap->nb_numb)
		tab[i++] = -1;
}

void			is_radix(t_swap *swap)
{
	if (swap->check_act == RR || swap->check_act == RRR)
	{
		calc_tab_distance_a1(swap, 0, 1);
		calc_tab_distance_b1(swap, 0, 1);
	}
	else if (swap->check_act == RA || swap->check_act == RRA)
		calc_tab_distance_a1(swap, 0, 1);
	else if (swap->check_act == RB || swap->check_act == RRB)
		calc_tab_distance_b1(swap, 0, 1);
	else if (swap->check_act == SA)
		do_ss(swap->val_a, swap->tab_distance_a, swap->length_a, swap);
	else if (swap->check_act == SB)
		do_ss(swap->val_b, swap->tab_distance_b, swap->length_b, swap);
	else if (swap->check_act == SS)
	{
		do_ss(swap->val_a, swap->tab_distance_a, swap->length_a, swap);
		do_ss(swap->val_b, swap->tab_distance_b, swap->length_b, swap);
	}
	else
	{
		radix(swap, 'a');
		calc_tab_distance_a1(swap, 0, 0);
		if (swap->val_b)
		{
			radix(swap, 'b');
			calc_tab_distance_b1(swap, 0, 0);
		}
	}
	is_radix2(swap);
}

void			is_rr_or_rrr3(t_swap *swap)
{
	if (swap->point_next >= swap->point_back)
		swap->rr = swap->length_a / 2 + swap->length_a % 2;
	else
		swap->rrr = swap->length_a / 2;
}

void			is_rr_or_rrr2(t_swap *swap)
{
	int		mid;

	mid = swap->length_a / 2;
	while (mid > 0)
	{
		if (swap->check_act2 != PB && swap->val_b2 && is_pa2(swap))
		{
			pa2(swap);
			swap->point_back += 2;
		}
		else if (swap->check_act2 != PA && is_pb2(swap))
			swap->point_back += 1;
		else if (is_ss2(swap))
			swap->c = swap->c;
		else if (swap->check_act2 != RB && is_rrb2(swap))
			swap->c = swap->c;
		else if (swap->check_act2 != RRB && is_rb2(swap))
			swap->c = swap->c;
		else
		{
			rrr2(swap);
			mid--;
		}
		is_radix2(swap);
	}
	calc_tab_distance_a1_2(swap, 0, 1);
	calc_tab_distance_b1_2(swap, 0, 1);
	mid = swap->total_distance_a - swap->total_distance_a2;
	if (mid > 0)
		swap->point_back += mid;
	mid = (swap->total_distance_b - swap->total_distance_b2) / 2;
	if (mid > 0)
		swap->point_back += mid;
	write_clone(swap, swap->val_a_last2);
	is_rr_or_rrr3(swap);
}

void			is_rr_or_rrr(t_swap *swap)
{
	int		mid;

	mid = swap->length_a / 2 + swap->length_a % 2;
	swap->point_next = 0;
	swap->point_back = 0;
	swap->length_a2 = swap->length_a;
	swap->length_b2 = swap->length_b;
	while (mid > 0)
	{
		if (swap->check_act2 != PB && swap->val_b2 && is_pa2(swap))
		{
			pa2(swap);
			swap->point_next += 2;
		}
		else if (swap->check_act2 != PA && is_pb2(swap))
			swap->point_next += 2;
		else if (is_ss2(swap))
			swap->c = swap->c;
		else if (swap->check_act2 != RB && is_rrb2(swap))
			swap->c = swap->c;
		else if (swap->check_act2 != RRB && is_rb2(swap))
			swap->c = swap->c;
		else
		{
			rr2(swap);
			mid--;
		}
		is_radix2(swap);
	}
	calc_tab_distance_a1_2(swap, 0, 1);
	calc_tab_distance_b1_2(swap, 0, 1);
	mid = swap->total_distance_a - swap->total_distance_a2;
	if (mid > 0)
		swap->point_next += mid;
	mid = (swap->total_distance_b - swap->total_distance_b2) / 2;
	if (mid > 0)
		swap->point_next += mid;
	write_clone(swap, swap->val_a_last2);
	is_rr_or_rrr2(swap);
}

void			algo(t_swap *swap)
{
	if (swap->val_a->next->pos_final_sort == 1 && swap->val_a->pos_final != swap->length_a  && is_ss(swap))
		swap->c = swap->c;
	else if (swap->check_act != PB && swap->val_b && is_pa(swap))
	{
		pa(swap);
		swap->line = ft_strncpy(swap->line, "pa", 3);
	}
	else if (swap->check_act != PA && is_pb(swap))
		swap->line = ft_strncpy(swap->line, "pb", 3);
	else if (test_pile2(swap->sort_final_a, swap->val_a))
		algo3(swap);
	else if (is_ss(swap))
		swap->c = swap->c;
	else if (swap->check_act != RB && is_rrb(swap))
		swap->line = ft_strncpy(swap->line, "rrb", 3);
	else if (swap->check_act != RRB && is_rb(swap))
		swap->line = ft_strncpy(swap->line, "rb", 3);
	else
	{
		if (swap->rr == 0 && swap->rrr == 0)
			is_rr_or_rrr(swap);
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
	}
	is_radix(swap);
}
