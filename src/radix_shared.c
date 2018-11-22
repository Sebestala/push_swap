
#include "../includes/push_swap.h"

void			radix_put_val_at_end_list(t_val *val, void **tab, int nb)
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

static void		radix_sort_algo2(t_tab *tab1, t_tab *tab2, int nb1, int nb2)
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
			element = val->radix_next;
			radix_put_val_at_end_list(val, tab2->tab, res);
			val->radix_next = NULL;
			tab1->tab[i] = element;
			val = tab1->tab[i];
		}
		i++;
	}
	tab1->check = 0;
	tab2->check = 1;
}

void			radix_sort_algo(t_tab *tab1, t_tab *tab2, int size)
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
