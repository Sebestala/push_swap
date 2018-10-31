
#include "../includes/push_swap.h"

void	make_val_list(t_swap *swap, int nb)
{
	t_val	*val;

	val = memalloc_sterr(sizeof(t_val), "make_val_list");
	val->val = nb;
	if (nb > swap->biggest)
		swap->biggest = nb;
	else if (nb < swap->smallest)
		swap->smallest = nb;
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
	if (!ft_strcmp(av[i], "-v") && swap->check_visu == 0)
	{
		swap->check_visu = 1;
		i++;
	}
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
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
}

void	check_val(t_swap *swap, t_val *val, int j, int i)
{
	while (val)
	{
		j++;
		val->pos_final = j;
		i = val->val;
		val = val->radix_next;
		if (val && i == val->val)
			exit_str("Error : two number too are identical");
	}
	swap->nb_numb = j;
}
