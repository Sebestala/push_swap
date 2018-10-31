
#include "../includes/push_swap.h"

void			init_visu(void)
{
	initscr();
	start_color();
	init_color(COLOR_WHITE, 999, 999, 999);
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(FALSE);
	keypad(stdscr, TRUE);
}

static void		color_the_deep(t_swap *swap)
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
	mvprintw(swap->axe_x - 3, 60, "Write 'esc' for valid et escape.");
	mvprintw(swap->axe_x - 3, 150, "Speed : 20/20");
}

static WINDOW	*init_win_player(t_swap *swap, WINDOW *player, int check, int i)
{
	int		j;

	if (swap->axe_y > swap->nb_numb + 8)
		j = swap->axe_y / 2;
	else
		j = swap->nb_numb + 8;
	if (check == 1)
	{
		init_pair(COLOR_WIN_1, COLOR_PILE_1, COLOR_GREY_MEDIUM);
		player = newwin(swap->nb_numb, swap->nb_numb, i, 4);
		wattrset(player, COLOR_PAIR(COLOR_WIN_1));
		wrefresh(player);
	}
	else if (check == 2)
	{
		init_pair(COLOR_WIN_2, COLOR_PILE_2, COLOR_GREY_MEDIUM);
		player = newwin(swap->nb_numb, swap->nb_numb, i, j);
		wattrset(player, COLOR_PAIR(COLOR_WIN_2));
		wrefresh(player);
	}
	return (player);
}

static WINDOW	*init_win_instruction(WINDOW *instruction, t_swap *swap)
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
//	mvprintw(swap->axe_x - 3, 100, "numb = %d   line = %d   col = %d   i = %d", swap->nb_numb, swap->axe_x, swap->axe_y, i);
	getch();
	swap->pile2 = init_win_player(swap, swap->pile2, 2, i);
	getch();
	init_pair(COLOR_GOOD_PLACE, COLOR_GREEN1, COLOR_GREY_MEDIUM);
	getch();
	swap->instruction = init_win_instruction(swap->instruction, swap);
	getch();
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


static void		print_instruction(t_swap *swap, WINDOW *instruction, int check)
{
	char	str[30];
	int		i;

	if (check == 1)
	{
		echo();
		nodelay(stdscr, FALSE);
		curs_set(TRUE);
		mvwgetnstr(instruction, 0, 46, str, 3);
	}
	if (check == 1)
	{
		nodelay(stdscr, TRUE);
		curs_set(FALSE);
		noecho();
	}
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

void		visu_pause(t_swap *swap)
{
	int		c;

	mvprintw(65, 226, "\tPAUSE");
	while (1)
	{
		c = getch();
		if (c == 32 || c == '=')
			break ;
		if (c == 27)
			esc_visu(swap, 0);
	}
	mvprintw(65, 226, "\t     ");
}

void		print_player2(t_swap *swap, int j, int k)
{
	t_val	*val;

	val = swap->val_b;
	while (val)
	{
		j = 0;
		while (j <= swap->nb_numb)
		{
			if (swap->nb_numb - j > val->pos_final)
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

void		print_player(t_swap *swap, int i, int j, int k)
{
	t_val	*val;

	val = swap->val_a;
	while (val)
	{
		j = 0;
		if (i > 0 || val->pos_final == 1)
			i++;
		if (i == val->pos_final)
			wattron(swap->pile1, COLOR_PAIR(COLOR_GOOD_PLACE));
//		nodelay(stdscr, FALSE);
//	mvprintw(swap->axe_x - 3, 100, "numb = %d   line = %d   col = %d   k = %d   j = %d  val = %d", swap->nb_numb, swap->axe_x, swap->axe_y, k, j, val->val);
//		getch();
		while (j <= swap->nb_numb)
		{
			if (swap->nb_numb - j > val->pos_final)
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
		j = 0;
		while (j <= swap->nb_numb)
		{
			mvwprintw(swap->pile1, j, k, " ");
			j++;
		}
		k++;
	}
	wrefresh(swap->pile1);
	print_player2(swap, 0, 0);
}

void			print_visu(t_swap *swap)
{
	int		j;
	int		c;

	j = 1;
	print_player(swap, 0, 0, 0);
	print_instruction(swap, swap->instruction, swap->check_visu);
	command(swap);
	swap->nb_move++;
	mvprintw(swap->axe_x - 3, 105, "Move : %4d", swap->nb_move);
	c = getch();
	if (c == 27)
		esc_visu(swap, 0);
	else if (c == '-' || c == '+')
	{
		if (c == '+' && swap->speed > 1)
			swap->speed -= 1000000;
		else if (c == '-' && swap->speed < 19000001)
			swap->speed += 1000000;
		mvprintw(swap->axe_x - 3, 150, "Speed : %02d/20"
		, 20 - (swap->speed / 1000000));
	}
	else if (c == 32 || c == '=')
		visu_pause(swap);
	j = 1;
	while (j < swap->speed)
		j++;
}
