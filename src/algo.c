#include "../includes/push_swap.h"

void		write_clone2(t_val *val, t_val *val2)
{
	val2->val = val->val;
	val2->pos_current = val->pos_current;
	val2->pos_final = val->pos_final;
	val2->pos_final_sort = val->pos_final_sort;
}

void		write_clone(t_swap *swap, t_val *elem3)
{
	t_val	*val;
	t_val	*val2;
	t_val	*elem;
	t_val	*elem2;

	val = swap->val_a;
	val2 = swap->val_a2;
//	elem = swap->val_b2;
	elem2 = NULL;
//	test_list(swap, 2, 'a');
//	printf("val = %d   last = %d\n", val->val, swap->val_a_last->val);
//printf("TEST029  b = %p   b2 = %p  final = %p   final2 = %p\n\n", swap->val_b, swap->val_b2, swap->val_b_last, swap->val_b_last2);
//printf("*************************************************\n");
//printf("*************************************************\n");
	while (val)
	{
		write_clone2(val, val2);
//printf("-------------------------------\n");
//	printf("1 val = %d   curr = %d   final = %d    sort = %d    back = %p    next = %p   addr = %p\n2 val = %d   curr = %d   final = %d    sort = %d    back = %p    next = %p    addr = %p   val_b2 = %p   val_b = %p\n\n", val->val, val->pos_current, val->pos_final, val->pos_final_sort, val->back, val->next, val, val2->val, val2->pos_current, val2->pos_final, val2->pos_final_sort, val2->back, val2->next, val2, swap->val_b2, swap->val_b);

		if (val == swap->val_a_last)
		{
			swap->val_a_last2 = val2;
			if (swap->val_b)
			{
				val = swap->val_b;
				elem = val2;
				if (val2->next)
				{
					val2 = val2->next;
					elem->next = NULL;
					elem2 = swap->val_b2;
					swap->val_b2 = val2;
					val2->back = NULL;
				}
				else
					val2 = swap->val_b2;
			}
			else
			{
				val = val->next;
				swap->val_b_last2 = NULL;
				swap->val_b2 = NULL;
			}
		}
		else if (val2 == swap->val_a_last2)
		{
			val2->next = swap->val_b2;
			swap->val_b2->back = val2;
			val2 = val2->next;
			val = val->next;
		}
		else
		{
			val = val->next;
//printf("val2->next = %p   elem2 = %p\n", val2->next, elem2);
			if (val)
			{
				if (val2->next == NULL)
				{
					val2->next = elem2;
					elem2->back = val2;
					elem2 = NULL;
				}
				val2 = val2->next;
			}
		}
/*	test_list(swap, 1, 'a');
	test_list(swap, 1, 'b');
	test_list(swap, 2, 'a');
	test_list(swap, 2, 'b');
	if (val && val2)
	printf("1 val = %d   curr = %d   final = %d    sort = %d    back = %p    next = %p   addr = %p\n2 val = %d   curr = %d   final = %d    sort = %d    back = %p    next = %p    addr = %p\n\n", val->val, val->pos_current, val->pos_final, val->pos_final_sort, val->back, val->next, val, val2->val, val2->pos_current, val2->pos_final, val2->pos_final_sort, val2->back, val2->next, val2);
printf("-------------------------------\n");
*/	}
//printf("*************************************************\n");
//printf("*************************************************\n");
	if (swap->val_b2)
		swap->val_b_last2 = val2;
	swap->length_a2 = swap->length_a;
	swap->length_b2 = swap->length_b;
	swap->check_act2 = swap->check_act;
/*	if (!swap->val_b)
		swap->val_b2 = NULL;
	if (!swap->val_b_last)
		swap->val_b_last2 = NULL;
*///	test_list(swap, 2, 'a');
//	test_list(swap, 2, 'b');
/*printf("******************************\n");
	test_list(swap, 1, 'a');
	test_list(swap, 1, 'b');
	test_list(swap, 2, 'a');
	test_list(swap, 2, 'b');
printf("******************************\n");
*///printf("ELEM2 = %d\n", elem2->val);
//printf("TEST030  b = %p   b2 = %p  final = %p   final2 = %p\n\n", swap->val_b, swap->val_b2, swap->val_b_last, swap->val_b_last2);
//	swap->val_b_last2 = val2;
//printf("TEST031  b = %p   b2 = %p  final = %p   final2 = %p\n\n", swap->val_b, swap->val_b2, swap->val_b_last, swap->val_b_last2);
	radix2(swap, 'a');
	calc_tab_distance_a1_2(swap, 0, 0);
	if (swap->val_b2)
	{
		radix2(swap, 'b');
		calc_tab_distance_b1_2(swap, 0, 0);
	}
//printf("///////////////////////////////////////////////////////\n");
//	test_list(swap, 2, 'b');
//printf("///////////////////////////////////////////////////////\n");
}

int				is_pb(t_swap *swap)
{
	if (swap->tab_distance_a[0] < 2 /*|| swap->length_b >= (swap->nb_numb / 2)*/)
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

int				is_ss(t_swap *swap)
{
	int		res;
	int		res2;
	int		i;

	i = 0;
	if (swap->check_act != SA && swap->val_a->next && swap->val_a->pos_final != swap->length_a && swap->val_a->next->pos_final == 1)
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
	}
	else if (swap->check_act != SA && swap->val_a->next)
	{
		res2 = absolue(swap->val_a->pos_current - swap->val_a->next->pos_final);
		if (res2 > swap->mid_a)
			res2 = swap->length_a - absolue(swap->val_a->pos_current - swap->val_a->next->pos_final);
		res = res2;
		res2 = absolue(swap->val_a->next->pos_current - swap->val_a->pos_final);
		if (res2 > swap->mid_a)
			res2 = swap->length_a - absolue(swap->val_a->next->pos_current - swap->val_a->pos_final);
		res += res2;
		if ((swap->tab_distance_a[0] + swap->tab_distance_a[1]) - res > 0)
			i++;
	}
	if (swap->check_act != SA && i < 1 && swap->val_a && swap->val_a->next && swap->val_a->pos_current != 1  && swap->val_a->next->pos_current != 1 && swap->val_a->val < swap->val_a->next->val && (swap->tab_distance_a[0] + swap->tab_distance_a[1]) - res == 0)
		i++;
	if (swap->check_act != SB && swap->val_b && swap->val_b->next && swap->val_b->pos_final != swap->length_b && swap->val_b->next->pos_final == 1)
	{
		res = swap->total_distance_b2;
		res2 = swap->check_act2;
		sb2(swap);
		radix2(swap, 'b');
		calc_tab_distance_b1_2(swap, 0, 0);
		if (res - swap->total_distance_b2 > 0)
			i += 5;
		sb2(swap);
		radix2(swap, 'b');
		calc_tab_distance_b1_2(swap, 0, 0);
		swap->check_act2 = res2;
	}
	else if (swap->check_act != SB && swap->val_b && swap->val_b->next)
	{
		res2 = absolue(swap->val_b->pos_current - swap->val_b->next->pos_final);
		if (res2 > swap->mid_b)
			res2 = swap->length_b - absolue(swap->val_b->pos_current - swap->val_b->next->pos_final);
		res = res2;
		res2 = absolue(swap->val_b->next->pos_current - swap->val_b->pos_final);
		if (res2 > swap->mid_b)
			res2 = swap->length_b - absolue(swap->val_b->next->pos_current - swap->val_b->pos_final);
		res += res2;
		if ((swap->tab_distance_b[0] + swap->tab_distance_b[1]) - res > 0)
			i += 5;
	}
	if (swap->check_act != SB && i < 5 && swap->val_b && swap->val_b->next && swap->val_b->pos_current != 1  && swap->val_b->next->pos_current != 1 && swap->val_b->val < swap->val_b->next->val && (swap->tab_distance_b[0] + swap->tab_distance_b[1]) - res == 0)
		i += 5;
	if (i == 6)
	{
		ss(swap);
		swap->line = ft_strncpy(swap->line, "ss ", 3);
	}
	else if (i == 5)
	{
		sb(swap);
		swap->line = ft_strncpy(swap->line, "sb ", 3);
	}
	else if (i == 1)
	{
		sa(swap);
		swap->line = ft_strncpy(swap->line, "sa ", 3);
	}
	return (i);
}
/*
void			pile_a_valid(t_swap *swap)
{
	int		i;
	int		dist;
	t_val	*elem;

	i = 0;
	dist = 0;
	elem = swap->val_a;
	while (swap->check_move == 0 && elem && i < swap->length_a / 2 + swap->length_a % 2)
	{
		if (elem->next && 
		i++;
	}
}
*/

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
		else if (/*swap->check_act2 != SA && swap->check_act2 != SB && swap->check_act2 != SS &&*/ is_ss2(swap))
			swap->c = swap->c;
		else if (swap->check_act2 != RB && is_rrb2(swap))
			swap->c = swap->c;
		else if (swap->check_act2 != RRB && is_rb2(swap))
			swap->c = swap->c;
//		else if (is_rr2(swap))
//			mid--;
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
//	test_list(swap, 2, 'a');
//	test_list(swap, 2, 'b');
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
//	test_list(swap, 1, 'a');
	while (mid > 0)
	{
//printf("TEST00  b = %p   b2 = %p  final = %p   final2 = %p\n\n", swap->val_b, swap->val_b2, swap->val_b_last, swap->val_b_last2);
		if (swap->check_act2 != PB && swap->val_b2 && is_pa2(swap))
		{
			pa2(swap);
			swap->point_next += 2;
		}
		else if (swap->check_act2 != PA && is_pb2(swap))
			swap->point_next += 2;
		else if (/*swap->check_act2 != SA && swap->check_act2 != SB && swap->check_act2 != SS &&*/ is_ss2(swap))
			swap->c = swap->c;
		else if (swap->check_act2 != RB && is_rrb2(swap))
			swap->c = swap->c;
		else if (swap->check_act2 != RRB && is_rb2(swap))
			swap->c = swap->c;
//		else if (is_rr2(swap))
//			mid--;
		else
		{
			rr2(swap);
			mid--;
		}
		is_radix2(swap);
//	test_list(swap, 2, 'a');
//	test_list(swap, 2, 'b');
	}
	calc_tab_distance_a1_2(swap, 0, 1);
	calc_tab_distance_b1_2(swap, 0, 1);
	mid = swap->total_distance_a - swap->total_distance_a2;
	if (mid > 0)
		swap->point_next += mid;
	mid = (swap->total_distance_b - swap->total_distance_b2) / 2;
	if (mid > 0)
		swap->point_next += mid;
//printf("TEST001  b = %p   b2 = %p  final = %p   final2 = %p\n\n", swap->val_b, swap->val_b2, swap->val_b_last, swap->val_b_last2);
	write_clone(swap, swap->val_a_last2);
//printf("TEST002  b = %p   b2 = %p  final = %p   final2 = %p\n\n", swap->val_b, swap->val_b2, swap->val_b_last, swap->val_b_last2);
	is_rr_or_rrr2(swap);
}

int		test1(t_swap *swap)
{
/*	if (!ft_strcmp(swap->line, "ss") && swap->check_act != SS)
		ss(swap);
	else if (!ft_strcmp(swap->line, "sa") && swap->check_act != SA)
		sa(swap);
	else if (!ft_strcmp(swap->line, "sb") && swap->check_act != SB)
		sb(swap);
	else if (!ft_strcmp(swap->line, "pa") && swap->check_act != PA)
		pa(swap);
	else if (!ft_strcmp(swap->line, "pb") && swap->check_act != PB)
		pb(swap);
	else if (!ft_strcmp(swap->line, "ra") && swap->check_act != RA)
		ra(swap);
	else if (!ft_strcmp(swap->line, "rb") && swap->check_act != RB)
		rb(swap);
	else if (!ft_strcmp(swap->line, "rr") && swap->check_act != RR)
		rr(swap);
	else if (!ft_strcmp(swap->line, "rra") && swap->check_act != RRA)
		rra(swap);
	else if (!ft_strcmp(swap->line, "rrb") && swap->check_act != RRB)
		rra(swap);
	else if (!ft_strcmp(swap->line, "rrr") && swap->check_act != RRR)
		rra(swap);
*/
printf("\n");
	test_list(swap, 1, 'a');
	test_list(swap, 1, 'b');
	test_list(swap, 2, 'a');
	test_list(swap, 2, 'b');
/*
if (swap->check_act == PA)
printf("  PA");
fflush(stdout);swap->check_act != PB && 
if (swap->check_act == PB)
printf("  PB");
fflush(stdout);
if (swap->check_act == SA)
printf("  SA");
fflush(stdout);
if (swap->check_act == SB)
printf("  SB");
fflush(stdout);
if (swap->check_act == SS)
printf("  SS");
fflush(stdout);
if (swap->check_act == RA)
printf("  RA");
fflush(stdout);
if (swap->check_act == RB)
printf("  RB");
fflush(stdout);
if (swap->check_act == RR)
printf("  RR");
fflush(stdout);
if (swap->check_act == RRA)
printf("  RRA");
fflush(stdout);
if (swap->check_act == RRB)
printf("  RRB");
fflush(stdout);
if (swap->check_act == RRR)
printf("  RRR");
fflush(stdout);*/
return (0);
}

void			algo(t_swap *swap)
{
/*
printf("\n");
	test_list(swap, 1, 'a');
	test_list(swap, 1, 'b');
	test_list(swap, 2, 'a');
	test_list(swap, 2, 'b');
*/
	if (swap->val_a->next->pos_final_sort == 1 && swap->val_a->pos_final != swap->length_a  && is_ss(swap))
		swap->c = swap->c;
	else if (swap->check_act != PB && swap->val_b && is_pa(swap))
	{
		pa(swap);
		swap->line = ft_strncpy(swap->line, "pa ", 3);
	}
	else if (swap->check_act != PA && is_pb(swap))
		swap->line = ft_strncpy(swap->line, "pb", 3);
	else if (test_pile2(swap->sort_final_a, swap->val_a))
	{
		algo3(swap);
//printf("TEST\n");
	}
	else if (is_ss(swap))
		swap->c = swap->c;
	else if (swap->check_act != RB && is_rrb(swap))
		swap->line = ft_strncpy(swap->line, "rrb", 3);
	else if (swap->check_act != RRB && is_rb(swap))
		swap->line = ft_strncpy(swap->line, "rb ", 3);
	else
	{
		if (swap->rr == 0 && swap->rrr == 0)
			is_rr_or_rrr(swap);
		if (swap->rr > 0)
		{
			rr(swap);
			swap->line = ft_strncpy(swap->line, "rr ", 3);
			swap->rr--;
		}
		else if (swap->rrr > 0)
		{
			rrr(swap);
			swap->line = ft_strncpy(swap->line, "rrr", 3);
			swap->rrr--;
		}
	}
//printf("\t------------------ \n");
	is_radix(swap);
/*	if (swap->test == 50)
	{
printf("\n");
	test_list(swap, 1, 'a');
	test_list(swap, 1, 'b');
	test_list(swap, 2, 'a');
	test_list(swap, 2, 'b');
	}*/
swap->test++;
}
