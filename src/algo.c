
#include "../includes/push_swap.h"

t_val		*list_copy(t_val *val)
{
	t_val	*elem;

	elem = memalloc_sterr(sizeof(t_val), "list_copy");
	elem->val = val->val;
	elem->pos_current = val->pos_current;
	elem->pos_final = val->pos_final;
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

int				is_pb(t_swap *swap)
{
	if (swap->tab_distance_a[0] <= 2)
		return (FALSE);
	pb(swap);
	return (TRUE);
}

int				is_pa(t_swap *swap)
{
	int		i;

	pa2(swap);
	radix2(swap, 'a');
	calc_tab_distance_a1_2(swap, 0);
	i = swap->val_a2->pos_current - swap->val_a2->pos_final;
//printf("VAL1 = %d     VAL2 = %d    RES = %d \n",  swap->val_a2->pos_current, swap->val_a2->pos_final , i);
//exit(0);
	pb2(swap);
	if (i != 0)
		return (FALSE);
	pa(swap);
	return (TRUE);
}

int				is_ss(t_swap *swap)
{
	int		i;

	i = 0;
	ss2(swap);
	radix2(swap, 'a');
	calc_tab_distance_a1_2(swap, 0);
	if (swap->val_b2)
	{
		radix2(swap, 'b');
		calc_tab_distance_b1_2(swap, 0);
	}
/*
int j = 0;
t_val	*val2 = swap->val_a2;
printf("dst a = %d      dst b = %d    dst a2 = %d     dst b2 = %d  numb = %d \n", swap->total_distance_a, swap->total_distance_b, swap->total_distance_a2, swap->total_distance_b2, swap->nb_numb);
while (j < swap->nb_numb)
{
printf("val = %d   TAB_A[%d]=%d      TAB_B[%d]=%d    curr = %d    final = %d\n", val2->val, j, swap->tab_distance_a2[j], j, swap->tab_distance_b2[j], val2->pos_current, val2->pos_final);
j++;
val2 = val2->next;
}

exit(0);
*/

	ss2(swap);
	if (swap->total_distance_a - swap->total_distance_a2 > 0)
		i++;
	if (swap->total_distance_b - swap->total_distance_b2 > 0)
		i += 5;
//printf("VAL1 = %d     VAL2 = %d    RES = %d \n",  swap->total_distance_a, swap->total_distance_a2 , swap->total_distance_a - swap->total_distance_a2 );
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
/*
int j = 0;
t_val	*val2 = swap->val_a2;
printf("dst a = %d      dst b = %d    dst a2 = %d     dst b2 = %d  numb = %d \n", swap->total_distance_a, swap->total_distance_b, swap->total_distance_a2, swap->total_distance_b2, swap->nb_numb);
while (j < swap->nb_numb)
{
printf("val = %d   TAB_A[%d]=%d      TAB_B[%d]=%d    curr = %d    final = %d\n", val2->val, j, swap->tab_distance_a2[j], j, swap->tab_distance_b2[j], val2->pos_current, val2->pos_final);
j++;
val2 = val2->next;
}
exit(0);
*/
	return (i);
}

void			algo(t_swap *swap)
{
//	radix2(swap, 'a');
//	radix2(swap, 'b');
//printf("numb = %d \n", swap->nb_numb);
//printf("dst a = %d      dst b = %d    dst a2 = %d     dst b2 = %d  numb = %d \n", swap->total_distance_a, swap->total_distance_b, swap->total_distance_a2, swap->total_distance_b2, swap->nb_numb);
	radix2(swap, 'a');
	calc_tab_distance_a1(swap, 0);
	if (swap->val_b2)
	{
		radix2(swap, 'b');
		calc_tab_distance_b1(swap, 0);
	}
	if (swap->val_b && is_pa(swap))
		swap->line = ft_strncpy(swap->line, "pa", 3);
	else if (is_ss(swap))
		return ;
	else if (swap->val_a && is_pb(swap))
		swap->line = ft_strncpy(swap->line, "pb", 3);
	else
	{
		rr(swap);
		swap->line = ft_strncpy(swap->line, "rr", 3);
	}
	radix(swap, 'a');
	if (swap->val_b)
		radix(swap, 'b');
}
