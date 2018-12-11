
#include "../includes/push_swap.h"

int			test_pile2(t_val *first, t_val *begin)
{
	t_val	*val;
	t_val	*val2;

	val = first;
	while (val)
	{
		val2 = val;
		val = val->next;
		if (val && val2->pos_final > val->pos_final)
			return (FALSE);
	}
	val = begin;
	if (val && val2->pos_final > val->pos_final)
		return (FALSE);
	while (val && val != first)
	{
//		printf("val = %d   current = %d   final = %d\n", val->val, val->pos_current, val->pos_final);
		val2 = val;
		val = val->next;
		if (val && val != first && val2->pos_final > val->pos_final)
			return (FALSE);
	}
	return (TRUE);
}

void		test_radix(t_swap *swap, int nb, char c)
{
	t_val	*val;

	if (nb == 1 && c == 'a')
		val = swap->sort_final_a;
	else if (nb == 1 && c == 'b')
		val = swap->sort_final_b;
	else if (nb == 2 && c == 'a')
		val = swap->sort_final_a2;
	else if (nb == 2 && c == 'b')
		val = swap->sort_final_b2;
	printf("\n");
	while (val)
	{
		printf("RADIX %d%c    val = %d   current = %d   final = %d\n", nb, c, val->val, val->pos_current, val->pos_final);
		val = val->radix_next;
	}
}

void		test_list(t_swap *swap, int nb, char c)
{
	t_val	*val;
	int		i;
	int		*tab;

	i = 0;
	if (nb == 1 && c == 'a')
	{
		val = swap->val_a;
		tab = swap->tab_distance_a;
	}
	else if (nb == 1 && c == 'b')
	{
		val = swap->val_b;
		tab = swap->tab_distance_b;
	}
	else if (nb == 2 && c == 'a')
	{
		val = swap->val_a2;
		tab = swap->tab_distance_a2;
	}
	else if (nb == 2 && c == 'b')
	{
		val = swap->val_b2;
		tab = swap->tab_distance_b2;
	}
	printf("\n");
	while (val)
	{
		printf("LIST %d%c    val = %d   current = %d   final = %d   sort = %d   Tab[%d] = %d\n", nb, c, val->val, val->pos_current, val->pos_final, val->pos_final_sort, i, tab[i]);
		val = val->next;
		i++;
	}
}

t_val		*list_copy(t_val *val)
{
	t_val	*elem;

	elem = memalloc_sterr(sizeof(t_val), "list_copy");
	elem->val = val->val;
	elem->pos_current = val->pos_current;
	elem->pos_final = val->pos_final;
	elem->pos_final_sort = val->pos_final_sort;
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

int			absolue(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}

void	make_val_list(t_swap *swap, int nb)
{
	t_val	*val;

	val = memalloc_sterr(sizeof(t_val), "make_val_list");
	val->val = nb;
	if (!swap->val_a)
	{
		swap->val_a = val;
		swap->val_a_last = val;
	}
	else
	{
		swap->val_a_last->next = val;
		val->back = swap->val_a_last;
		swap->val_a_last = val;
	}
}

void	check_list_int(t_swap *swap, int ac, char **av, int i)
{
	int		j;

	j = 0;
	while (av[i][j])
	{
		if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != '-'
&& av[i][j] != '+' && av[i][j] != ' ' && av[i][j] != '\t' && av[i][j] != '\n')
			exit_str("Error : bad input \tcode : 1");
		if ((av[i][j] == '-' || av[i][j] == '+')
					&& (av[i][j + 1] < '0' || av[i][j + 1] > '9'))
			exit_str("Error : bad input \tcode : 2");
		j++;
	}
}

void	make_tab_list(t_swap *swap, int ac, char **av)
{
	int			i;
	int			j;
	intmax_t	nb;

	i = 1;
//printf("AC = %d\n", ac);
	if (!ft_strcmp(av[i], "-v") && swap->check_visu == 0)
	{
		swap->check_visu = 1;
		i++;
	}
	else if (!ft_strcmp(av[i], "-s") && swap->check_visu == 0)
	{
		swap->check_speed = 1;
		i++;
	}
	else if (!ft_strcmp(av[i], "-vs") && swap->check_visu == 0)
	{
		swap->check_visu = 2;
		i++;
	}
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
//printf("AV[%d][%d] = %c\n", i, j, av[i][j]);
			check_list_int(swap, ac, av, i);
			j = 0;
			nb = atoi_end_index(&av[i]);
			if (nb < INT_MIN || nb > INT_MAX)
				exit_str("Error : number too big");
			make_val_list(swap, nb);
			while (av[i][j] && (av[i][j] == ' ' || av[i][j] == '\t' || av[i][j] == '\n'))
				j++;
		}
		i++;
	}
	if (!swap->val_a)
		exit(1);
}

void	check_val(t_swap *swap, t_val *val, int j, int i)
{
	while (val)
	{
		j++;
		val->pos_final = j;
		val->pos_final_sort = j;
		i = val->val;
		val = val->radix_next;
		if (val && i == val->val)
			exit_str("Error : two number too are identical");
	}
	swap->nb_numb = j;
//printf("numb1 = %d TOTAL = %ld  \n", swap->nb_numb, sizeof(int) * j);
	j++;
	swap->length_a = swap->nb_numb;
	swap->tab_distance_a = memalloc_sterr(sizeof(int) * j, "check_val   code1");
	swap->tab_distance_b = memalloc_sterr(sizeof(int) * j, "check_val   code2");
	swap->tab_distance_a2 = memalloc_sterr(sizeof(int) * j, "check_val  code3");
	swap->tab_distance_b2 = memalloc_sterr(sizeof(int) * j, "check_val  code4");
}
