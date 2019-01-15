/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_both2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:46:03 by sgarcia           #+#    #+#             */
/*   Updated: 2019/01/15 15:41:57 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		color_the_deep(t_swap *swap)
{
	int		y;
	int		x;
	char	*str;

	y = 0;
	x = 0;
	str = ft_strnew(swap->axe_y);
	while (x <= swap->axe_y)
		str[x++] = ' ';
	init_pair(COLOR_DEEP, COLOR_BASIC, COLOR_GREY_MEDIUM);
	attrset(COLOR_PAIR(COLOR_DEEP));
	while (y <= swap->axe_x)
	{
		printw("%s", str);
		y++;
	}
}

void		init_visu(void)
{
	initscr();
	start_color();
	init_color(COLOR_WHITE, 999, 999, 999);
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(FALSE);
	keypad(stdscr, TRUE);
}

WINDOW		*init_win_player(t_swap *swap, WINDOW *player, int check, int i)
{
	int		j;

	if (swap->axe_y > swap->nb_numb + 8)
		j = swap->axe_y / 2;
	else
		j = swap->nb_numb + 8;
	if (check == 1)
	{
		init_pair(COLOR_WIN_1, COLOR_PILE_1, COLOR_GREY_MEDIUM);
		player = newwin(swap->nb_numb, swap->nb_numb, i + 1, 4);
		wattrset(player, COLOR_PAIR(COLOR_WIN_1));
		wrefresh(player);
	}
	else if (check == 2)
	{
		init_pair(COLOR_WIN_2, COLOR_PILE_2, COLOR_GREY_MEDIUM);
		player = newwin(swap->nb_numb, swap->nb_numb, i + 1, j);
		wattrset(player, COLOR_PAIR(COLOR_WIN_2));
		wrefresh(player);
	}
	return (player);
}

WINDOW		*init_win_instruction(WINDOW *instruction, t_swap *swap)
{
	char	str[SIZE_WIN_X];
	int		i;

	i = 0;
	init_pair(COLOR_STATS, COLOR_BASIC, COLOR_GREY_LIGHT);
	instruction = newwin(1, SIZE_WIN_X, swap->axe_x - 3, 4);
	while (i <= SIZE_WIN_X)
		str[i++] = ' ';
	wattrset(instruction, COLOR_PAIR(COLOR_STATS));
	wprintw(instruction, "%s", str);
	wrefresh(instruction);
	return (instruction);
}
