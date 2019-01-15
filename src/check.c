/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:43:40 by sgarcia           #+#    #+#             */
/*   Updated: 2019/01/15 18:40:30 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		make_val_list(t_swap *swap, int nb)
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

void		check_list_int(t_swap *swap, int ac, char **av, int i)
{
	int		j;

	j = 0;
	while (av[i][j])
	{
		if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != '-' && av[i][j] !=
				'+' && av[i][j] != ' ' && av[i][j] != '\t' && av[i][j] != '\n')
			exit_str("Error : bad input \tcode : 1");
		if ((av[i][j] == '-' || av[i][j] == '+')
					&& (av[i][j + 1] < '0' || av[i][j + 1] > '9'))
			exit_str("Error : bad input \tcode : 2");
		j++;
	}
}

void		make_tab_list_2(t_swap *swap, int ac, char **av, int i)
{
	intmax_t	nb;
	int			j;

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
			while (av[i][j] &&
					(av[i][j] == ' ' || av[i][j] == '\t' || av[i][j] == '\n'))
				j++;
		}
		i++;
	}
	if (!swap->val_a)
		exit(1);
}

void		make_tab_list(t_swap *swap, int ac, char **av)
{
	int			i;

	i = 1;
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
	make_tab_list_2(swap, ac, av, i);
}

void		check_val(t_swap *swap, t_val *val, int j, int i)
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
	j++;
	swap->length_a = swap->nb_numb;
	swap->tab_distance_a = memalloc_sterr(sizeof(int) * j, "check_val   code1");
	swap->tab_distance_b = memalloc_sterr(sizeof(int) * j, "check_val   code2");
	swap->tab_distance_a2 = memalloc_sterr(sizeof(int) * j, "check_val  code3");
	swap->tab_distance_b2 = memalloc_sterr(sizeof(int) * j, "check_val  code4");
}
