
#include "../includes/push_swap.h"

void		radix_merge(t_tab *tab1, t_tab *tab2, t_swap *swap)
{
//printf("radix_merge\n");
//fflush(stdout);
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
	swap->sort_final = tab2->tab[0];
}

void		radix_put_val_at_end_of_list(t_val *val, void **tab, int nb)
{
//printf("radix_put_val_at_end_of_list NB = %d\n", nb);
//fflush(stdout);
	t_val	*element;

	if (nb < 0)
		nb = -nb;
	element = tab[nb];
	if (!element)
		tab[nb] = val;
	else
	{
		while (element->radix_next != NULL)
			element = element->radix_next;
		element->radix_next = val;
	}
}

void		radix_sort_algo2(t_tab *tab1, t_tab *tab2, int nb1, int nb2)
{
//printf("radix_sort_algo2\n");
//fflush(stdout);
	t_val	*val;
	t_val	*element;
	int		i;
	int		res;

	i = 0;
	while (i < 10)
	{
		val = tab1->tab[i];
		while (val)
		{
			res = (val->val % nb1) / nb2;
//printf(" val = %d  res = %d   nb1 = %d     nb2 = %d\n", val->val, res, nb1, nb2);
//fflush(stdout);
			element = val->radix_next;
			radix_put_val_at_end_of_list(val, tab2->tab, res);
			val->radix_next = NULL;
			tab1->tab[i] = element;
			val = tab1->tab[i];
		}
		i++;
	}
//printf("\n");
//fflush(stdout);
	tab1->check = 0;
	tab2->check = 1;
}

void		radix_sort_algo(t_tab *tab1, t_tab *tab2, int size)
{
//printf("radix_sort_algo\n");
//fflush(stdout);
	int		nb1;
	int		nb2;
	int		i;

	nb1 = 10;
	nb2 = 1;
	i = 0;
	while (i <= size)
	{
		if (tab1->check == 1)
			radix_sort_algo2(tab1, tab2, nb1, nb2);
		else
			radix_sort_algo2(tab2, tab1, nb1, nb2);
		nb1 *= 10;
		nb2 *= 10;
		i++;
	}
}

void		radix_init(t_swap *swap)
{
//printf("radix_init\n");
//fflush(stdout);
	swap->tab_neg1 = memalloc_sterr(sizeof(t_tab), "radix   code : 1");
	swap->tab_neg2 = memalloc_sterr(sizeof(t_tab), "radix   code : 2");
	swap->tab_pos1 = memalloc_sterr(sizeof(t_tab), "radix   code : 3");
	swap->tab_pos2 = memalloc_sterr(sizeof(t_tab), "radix   code : 4");
	swap->tab_neg1->check = 1;
	swap->tab_pos1->check = 1;
}

void		radix_sort_pos_and_neg(t_swap *swap)
{
//printf("radix_sort_pos_and_neg\n");
//fflush(stdout);
	t_val	*val;

	val = swap->val_a;
	while (val)
	{
//printf(" val = %d \n", val->val);
//fflush(stdout);
		if (val->val < 0)
			radix_put_val_at_end_of_list(val, swap->tab_neg1->tab, val->val % 10);
		else
			radix_put_val_at_end_of_list(val, swap->tab_pos1->tab, val->val % 10);
		val = val->next;
	}
}

void		radix(t_swap *swap)
{
//printf("radix\n");
//fflush(stdout);
	int		i;

	i = 0;
	radix_init(swap);
	radix_sort_pos_and_neg(swap);
	while (swap->smallest != 0)
	{
		swap->smallest /= 10;
		i++;
	}
	radix_sort_algo(swap->tab_neg1, swap->tab_neg2, i);
	i = 0;
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
		radix_merge(swap->tab_neg1, swap->tab_pos1, swap);
	else if (swap->tab_pos2->check == 1 && i == 1)
		radix_merge(swap->tab_neg1, swap->tab_pos2, swap);
	else if (swap->tab_pos1->check == 1 && i == 0)
		radix_merge(swap->tab_neg2, swap->tab_pos1, swap);
	else if (swap->tab_pos2->check == 1 && i == 0)
		radix_merge(swap->tab_neg2, swap->tab_pos2, swap);
}
