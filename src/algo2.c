
#include "../includes/push_swap.h"
/*
int				is_rr2(t_swap *swap)
{
	t_val	*val;
	int		i;

	i = 0;
	val = swap->val_b2;
	if (test_pile2(swap->sort_final_b2, swap->val_b2))
	{
		if (swap->sort_final_b2 == swap->val_b2)
			return (FALSE);
		while (val && i != swap->mid_b2)
		{
			val = val->next;
			if (val == val->sort_final_b2;
				return (TRUE);
			i++;
		}
	}
				return (TRUE);

}
*/


int				is_rrb(t_swap *swap)
{
	int res;

	if (swap->val_b && swap->val_b->next)
	{
		res = swap->check_act;
		rrb(swap);
		calc_tab_distance_b1(swap, 0, 1);
		if (is_pa(swap))
			return (TRUE);
		rb(swap);
		swap->check_act = res;
		calc_tab_distance_b1(swap, 0, 1);
	}
	return (FALSE);
}

int				is_rb(t_swap *swap)
{
	int res;

	if (swap->val_b && swap->val_b->next)
	{
		res = swap->check_act;
		rb(swap);
		calc_tab_distance_b1(swap, 0, 1);
		if (is_pa(swap))
			return (TRUE);
		rrb(swap);
		swap->check_act = res;
		calc_tab_distance_b1(swap, 0, 1);
	}
	return (FALSE);
}

int				is_rrb2(t_swap *swap)
{
	int res;

	if (swap->val_b2 && swap->val_b2->next)
	{
		res = swap->check_act2;
		rrb2(swap);
		calc_tab_distance_b1_2(swap, 0, 1);
		if (is_pa2(swap))
			return (TRUE);
		rb2(swap);
		swap->check_act2 = res;
		calc_tab_distance_b1_2(swap, 0, 1);
	}
	return (FALSE);
}

int				is_rb2(t_swap *swap)
{
	int res;

	if (swap->val_b2 && swap->val_b2->next)
	{
		res = swap->check_act2;
		rb2(swap);
		calc_tab_distance_b1_2(swap, 0, 1);
		if (is_pa2(swap))
			return (TRUE);
		rrb2(swap);
		swap->check_act2 = res;
		calc_tab_distance_b1_2(swap, 0, 1);
	}
	return (FALSE);
}

int				is_pb2(t_swap *swap)
{
//	printf ("VAL = %d   SORT = %d   nb = %d\n", swap->val_a2->val, swap->val_a2->pos_final_sort, swap->nb_numb / 2);
	if (swap->tab_distance_a2[0] < 2 /* || swap->val_a2->pos_final_sort <= (swap->nb_numb / 3)*/)
		return (FALSE);
	pb2(swap);
	return (TRUE);
}

int				is_pa2(t_swap *swap)
{
	t_val	*val;
	int		pos;
	int		i;

	val = swap->val_a2;
	pos = 0;
	while (val)
	{
		if (swap->val_b2->val > val->val && pos <= val->pos_final)
			pos = val->pos_final + 1;
		val = val->next;
	}
	if (pos == 0)
		pos = swap->length_a2 + 1;
	if (swap->val_a2->pos_current == 1)
		i = swap->length_a2 + 1;
	else 
		i = swap->val_a2->pos_current;
	if (absolue(i - pos) == 0)
		return (TRUE);
	return (FALSE);
}

int				is_ss2(t_swap *swap)
{
	int		res;
	int		res2;
	int		i;

	i = 0;
	if (swap->check_act2 != SA && swap->val_a2->next && swap->val_a2->pos_final != swap->length_a2 && swap->val_a2->next->pos_final == 1)
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
	else if (swap->check_act2 != SA && swap->val_a2->next)
	{
		res2 = absolue(swap->val_a2->pos_current - swap->val_a2->next->pos_final);
		if (res2 > swap->mid_a2)
			res2 = swap->length_a2 - absolue(swap->val_a2->pos_current - swap->val_a2->next->pos_final);
		res = res2;
		res2 = absolue(swap->val_a2->next->pos_current - swap->val_a2->pos_final);
		if (res2 > swap->mid_a2)
			res2 = swap->length_a2 - absolue(swap->val_a2->next->pos_current - swap->val_a2->pos_final);
		res += res2;
		if ((swap->tab_distance_a2[0] + swap->tab_distance_a2[1]) - res > 0)
			i++;
	}
	if (swap->check_act2 != SA && i < 1 && swap->val_a2 && swap->val_a2->next && swap->val_a2->pos_current != 1  && swap->val_a2->next->pos_current != 1 && swap->val_a2->val < swap->val_a2->next->val && (swap->tab_distance_a2[0] + swap->tab_distance_a2[1]) - res == 0)
		i ++;
	if (swap->check_act2 != SB && swap->val_b2 && swap->val_b2->next && swap->val_b2->pos_final != swap->length_b2 && swap->val_b2->next->pos_final == 1)
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
	else if (swap->check_act2 != SB && swap->val_b2 && swap->val_b2->next)
	{
		res2 = absolue(swap->val_b2->pos_current - swap->val_b2->next->pos_final);
		if (res2 > swap->mid_b2)
			res2 = swap->length_b2 - absolue(swap->val_b2->pos_current - swap->val_b2->next->pos_final);
		res = res2;
		res2 = absolue(swap->val_b2->next->pos_current - swap->val_b2->pos_final);
		if (res2 > swap->mid_b2)
			res2 = swap->length_b2 - absolue(swap->val_b2->next->pos_current - swap->val_b2->pos_final);
		res += res2;
		if ((swap->tab_distance_b2[0] + swap->tab_distance_b2[1]) - res > 0)
			i += 5;
	}
	if (swap->check_act2 != SB && i < 5 && swap->val_b2 && swap->val_b2->next && swap->val_b2->pos_current != 1  && swap->val_b2->next->pos_current != 1 && swap->val_b2->val < swap->val_b2->next->val && (swap->tab_distance_b2[0] + swap->tab_distance_b2[1]) - res == 0)
		i += 5;
	if (i == 6)
		ss2(swap);
	else if (i == 5)
		sb2(swap);
	else if (i == 1)
		sa2(swap);
/*
int j = 0;
t_val	*val2 = swap->val_a2;
printf("dst a = %d      dst b = %d    dst a2 = %d     dst b2 = %d  numb = %d \n", swap->total_distance_a, swap->total_distance_b, swap->total_distance_a2, swap->total_distance_b2, swap->nb_numb);
while (j < swap->nb_numb)
{
	pb2(swap);
printf("val = %d   TAB_A[%d]=%d      TAB_B[%d]=%d    curr = %d    final = %d\n", val2->val, j, swap->tab_distance_a2[j], j, swap->tab_distance_b2[j], val2->pos_current, val2->pos_final);
j++;
void			algo(t_swap *swap)
val2 = val2->next;
}
exit(0);
*/
	return (i);
}

void			do_ss2(t_val *val, int *tab, int len, t_swap *swap)
{
	int		nb;
	int		total;
	int		i;

	i = 0;
	nb = val->pos_current;
	val->pos_current = val->next->pos_current;
	val->next->pos_current = nb;
	if (val == swap->val_a2)
		total = swap->total_distance_a2;
	if (val == swap->val_b2)
		total = swap->total_distance_b2;
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

void			is_radix2(t_swap *swap)
{
	if (swap->check_act2 == RR || swap->check_act2 == RRR)
	{
		calc_tab_distance_a1_2(swap, 0, 1);
		calc_tab_distance_b1_2(swap, 0, 1);
	}
	else if (swap->check_act2 == RA || swap->check_act2 == RRA)
		calc_tab_distance_a1_2(swap, 0, 1);
	else if (swap->check_act2 == RB || swap->check_act2 == RRB)
		calc_tab_distance_b1_2(swap, 0, 1);
	else if (swap->check_act2 == SA)
		do_ss2(swap->val_a2, swap->tab_distance_a2, swap->length_a2, swap);
	else if (swap->check_act2 == SB)
		do_ss2(swap->val_b2, swap->tab_distance_b2, swap->length_b2, swap);
	else if (swap->check_act2 == SS)
	{
		do_ss2(swap->val_a2, swap->tab_distance_a2, swap->length_a2, swap);
		do_ss2(swap->val_b2, swap->tab_distance_b2, swap->length_b2, swap);
	}
	else
	{
		radix2(swap, 'a');
		calc_tab_distance_a1_2(swap, 0, 0);
		if (swap->val_b2)
		{
			radix2(swap, 'b');
			calc_tab_distance_b1_2(swap, 0, 0);
		}
	}
}
