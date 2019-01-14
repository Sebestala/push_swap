/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:45:51 by sgarcia           #+#    #+#             */
/*   Updated: 2019/01/14 17:45:57 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

WINDOW	*init_win_player(t_swap *swap, WINDOW *player, int check, int i)
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

WINDOW	*init_win_instruction(WINDOW *instruction, t_swap *swap)
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

void		esc_visu(t_swap *swap, int i)
{
	if (i == 1)
	{
		nodelay(stdscr, FALSE);
		while (1)
			if (getch())
				break ;
	}
	delwin(swap->pile1);
	delwin(swap->pile2);
	delwin(swap->instruction);
	endwin();
	if (i == 0)
		exit(0);
}

static void		print_player2(t_swap *swap, int j, int k, t_val *val)
{
	while (val)
	{
		swap->c = getch();
		j = 0;
		while (j <= swap->nb_numb)
		{
			if (swap->nb_numb - j > val->pos_final_sort)
				mvwprintw(swap->pile2, j, k, " ");
			else
				mvwprintw(swap->pile2, j, k, "|");
			j++;
		}
		val = val->next;
		k++;
	}
	while (k <= swap->nb_numb)
	{
		swap->c = getch();
		j = 0;
		while (j <= swap->nb_numb)
		{
			mvwprintw(swap->pile2, j, k, " ");
			j++;
		}
		k++;
	}
	wrefresh(swap->pile2);
}

void			print_player(t_swap *swap, int i, int j, int k)
{
	t_val	*val;

	val = swap->val_a;
	while (val)
	{
		swap->c = getch();
		j = 0;
		if (val->pos_final == val->pos_current/*i*/)
			wattron(swap->pile1, COLOR_PAIR(COLOR_GOOD_PLACE));
		while (j <= swap->nb_numb)
		{
			if (swap->nb_numb - j > val->pos_final_sort)
				mvwprintw(swap->pile1, j, k, " ");
			else
				mvwprintw(swap->pile1, j, k, "|");
			j++;
		}
		wattron(swap->pile1, COLOR_PAIR(COLOR_WIN_1));
		val = val->next;
		k++;
	}
	while (k <= swap->nb_numb)
	{
		swap->c = getch();
		j = 0;
		while (j <= swap->nb_numb)
		{
			mvwprintw(swap->pile1, j, k, " ");
			j++;
		}
		k++;
	}
	wrefresh(swap->pile1);
	print_player2(swap, 0, 0, swap->val_b);
}
