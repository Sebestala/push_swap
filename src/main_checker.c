
#include "../includes/push_swap.h"

static void		list_is_valid(t_swap *swap)
{
	t_val	*element;
	int		i;

	if (swap->val_b != NULL)
	{
		esc_visu(swap, 1);
		ft_putendl("KO");
		return;
	}
	element = swap->val_a;
	while (element)
	{
		i = element->val;
		element = element->next;
		if (element && i >= element->val)
		{
			esc_visu(swap, 1);
			ft_putendl("KO");
			return ;
		}
	}
	esc_visu(swap, 1);
	ft_putendl("OK");
}

static void		command2(t_swap *swap)
{
	if (!ft_strcmp(swap->line, "rrb"))
		rrb(swap);
	else if (!ft_strcmp(swap->line, "rrr"))
		rrr(swap);
	else if (!ft_strcmp(swap->line, "esc") && swap->check_visu == 1)
		swap->check_visu = 0;
	else if (!ft_strcmp(swap->line, "v") && swap->check_visu == 0)
	{
		swap->check_visu = 1;
		init_windows(swap);
	}
	else
	{
		esc_visu(swap, 1);
		exit_str("Error : operation doesn't exist");
	}
}

void			command(t_swap *swap)
{
	if (!ft_strcmp(swap->line, "ss"))
		ss(swap);
	else if (!ft_strcmp(swap->line, "sa"))
		sa(swap);
	else if (!ft_strcmp(swap->line, "sb"))
		sb(swap);
	else if (!ft_strcmp(swap->line, "pa"))
		pa(swap);
	else if (!ft_strcmp(swap->line, "pb"))
		pb(swap);
	else if (!ft_strcmp(swap->line, "ra"))
		ra(swap);
	else if (!ft_strcmp(swap->line, "rb"))
		rb(swap);
	else if (!ft_strcmp(swap->line, "rr"))
		rr(swap);
	else if (!ft_strcmp(swap->line, "rra"))
		rra(swap);
	else
		command2(swap);
}

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

int		main(int ac, char **av)
{
	t_swap	*swap;
	int		i;

	if (ac < 2)
		return (0);
	swap = memalloc_sterr(sizeof(t_swap), "main");
	make_tab_list(swap, ac, av);
	radix(swap);
	check_val(swap, swap->sort_final, 0, 0);
	while ((i = get_next_line(0, &swap->line)))
	{
		if (i == -1)
			exit_str("Error : in get_next_line, return (-1)");
		command(swap);
	if (swap->check_visu == 1)
		break ;
	swap->nb_move++;
	}
	while (swap->check_visu == 1)
		print_visu(swap);
	list_is_valid(swap);
	return (0);
}
