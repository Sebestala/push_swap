/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:45:51 by sgarcia           #+#    #+#             */
/*   Updated: 2019/01/15 15:35:11 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

static void	print_player2_2(t_swap *swap, int j, int k, t_val *val)
{
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

static void	print_player2(t_swap *swap, int j, int k, t_val *val)
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
	print_player2_2(swap, j, k, val);
}

static void	print_player_2(t_swap *swap, int i, int j, int k)
{
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

void		print_player(t_swap *swap, int i, int j, int k)
{
	t_val	*val;

	val = swap->val_a;
	while (val)
	{
		swap->c = getch();
		j = 0;
		if (val->pos_final == val->pos_current)
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
	print_player_2(swap, i, j, k);
}
