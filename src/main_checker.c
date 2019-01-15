/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:43:47 by sgarcia           #+#    #+#             */
/*   Updated: 2019/01/15 20:24:39 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		list_is_valid(t_swap *swap)
{
	t_val	*element;
	int		i;

	if (swap->val_b != NULL)
	{
		esc_visu(swap, 1);
		ft_putendl("KO");
		return ;
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
	else if (ft_strncmp(swap->line, "Move :", 6))
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
		pa(swap, NULL, NULL);
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

int				main(int ac, char **av)
{
	t_swap	*swap;
	int		i;

	if (ac < 2)
		return (0);
	swap = memalloc_sterr(sizeof(t_swap), "main");
	make_tab_list(swap, ac, av);
	radix_init(swap);
	radix(swap, 'a', 0);
	check_val(swap, swap->sort_final_a, 0, 0);
	init_list_copy(swap);
	if (swap->check_visu > 0)
		init_windows(swap);
	while (swap->check_visu == 0 && (i = get_next_line(0, &swap->line)))
	{
		if (i == -1)
			exit_str("Error : in get_next_line, return (-1)");
		command(swap);
		swap->nb_move++;
	}
	while (swap->check_visu >= 1)
		print_visu(swap);
	list_is_valid(swap);
	free_struct(swap);
	return (0);
}
