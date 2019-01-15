/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:45:46 by sgarcia           #+#    #+#             */
/*   Updated: 2019/01/15 18:27:52 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			init_windows(t_swap *swap)
{
	int		i;

	init_visu();
	getmaxyx(stdscr, swap->axe_x, swap->axe_y);
	color_the_deep(swap);
	if (swap->axe_x - 6 > swap->nb_numb)
		i = swap->axe_x - 6 - swap->nb_numb;
	else
		i = 1;
	getch();
	swap->pile1 = init_win_player(swap, swap->pile1, 1, i);
	getch();
	swap->pile2 = init_win_player(swap, swap->pile2, 2, i);
	getch();
	init_pair(COLOR_GOOD_PLACE, COLOR_GREEN1, COLOR_GREY_MEDIUM);
	getch();
	swap->instruction = init_win_instruction(swap->instruction, swap);
	getch();
	mvprintw(swap->axe_x - 3, 105, "Move : %4d", swap->nb_move);
	mvprintw(swap->axe_x - 3, 60, "Write 'esc' for valid and escape.");
	mvprintw(swap->axe_x - 3, 125,
			"Commands : pa pb sa sb ss ra rb rr rra rrb rrr");
	getch();
}

static void		print_instruction(t_swap *swap, WINDOW *instruction)
{
	char	str[30];
	int		i;

	echo();
	curs_set(TRUE);
	mvwgetnstr(instruction, 0, 46, str, 3);
	curs_set(FALSE);
	noecho();
	i = 0;
	wmove(instruction, 0, 0);
	while (i < 4)
	{
		wdelch(instruction);
		i++;
	}
	mvwprintw(instruction, 0, 45, "     ");
	swap->line = ft_strdup(str);
}

void			print_visu(t_swap *swap)
{
	print_player(swap, 0, 0, 0);
	print_instruction(swap, swap->instruction);
	command(swap);
	swap->nb_move++;
	mvprintw(swap->axe_x - 3, 105, "Move : %4d", swap->nb_move);
	getch();
}
