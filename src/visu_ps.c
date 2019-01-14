/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:46:09 by sgarcia           #+#    #+#             */
/*   Updated: 2019/01/14 17:46:11 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			init_windows_ps(t_swap *swap)
{
	int		i;

	init_visu();
	getmaxyx(stdscr, swap->axe_x, swap->axe_y);
	color_the_deep(swap);
	if (swap->axe_x - 6 > swap->nb_numb)
		i = swap->axe_x - 6 - swap->nb_numb;
	else
		i = 1;
	swap->c = getch();
	swap->pile1 = init_win_player(swap, swap->pile1, 1, i);
	swap->c = getch();
	swap->pile2 = init_win_player(swap, swap->pile2, 2, i);
	swap->c = getch();
	init_pair(COLOR_GOOD_PLACE, COLOR_GREEN1, COLOR_GREY_MEDIUM);
	swap->c = getch();
	swap->instruction = init_win_instruction(swap->instruction, swap);
	swap->c = getch();
	mvprintw(swap->axe_x - 3, 75, "Touch 'esc' for escape, '+' and '-' for the speed, 'space' for pause.");
	mvprintw(swap->axe_x - 3, 150, "Speed : 20/20");
	mvprintw(swap->axe_x - 3, 58, "Move : %4d", swap->nb_move);
	refresh();
	swap->c = getch();
}

static void		print_instruction(t_swap *swap, WINDOW *instruction)
{
	int		i;

	if (swap->check_visu == 1)
		nodelay(stdscr, FALSE);
	mvwprintw(instruction, 0, 46, "%s", swap->line);
	i = 0;
	wmove(instruction, 0, 0);
	while (i < 4)
	{
		wdelch(instruction);
		i++;
	}
	mvwprintw(instruction, 0, 45, "     ");
	wrefresh(instruction);
	mvprintw(swap->axe_x - 3, 58, "Move : %4d", swap->nb_move);
	refresh();
	swap->c = getch();
	nodelay(stdscr, TRUE);
}

static void		visu_pause(t_swap *swap)
{
	mvprintw(swap->axe_x - 3, 166, "\tPAUSE");
	while (1)
	{
		swap->c = getch();
		if (swap->c == 32 || swap->c == '=')
			break ;
		if (swap->c == 27)
			esc_visu(swap, 0);
	}
	mvprintw(swap->axe_x - 3, 166, "\t     ");
}

void			print_visu_ps(t_swap *swap)
{
	int		j;

	j = 1;
	print_player(swap, 0, 0, 0);
	print_instruction(swap, swap->instruction);
	swap->c = getch();
	if (swap->c == 27)
		esc_visu(swap, 0);
	else if (swap->c == '-' || swap->c == '+')
	{
		if (swap->c == '+' && swap->speed > 1)
			swap->speed -= 1000000;
		else if (swap->c == '-' && swap->speed < 19000001)
			swap->speed += 1000000;
		mvprintw(swap->axe_x - 3, 150, "Speed : %02d/20"
		, 20 - (swap->speed / 1000000));
	}
	else if (swap->c == 32 || swap->c == '=')
		visu_pause(swap);
	j = 1;
	while (j < swap->speed)
	{
		swap->c = getch();
		j++;
	}
}
