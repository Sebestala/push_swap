
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
