
#include "../includes/push_swap.h"

static int		list_is_valid(t_swap *swap)
{
	t_val	*element;
	int		i;

	if (swap->val_b != NULL)
		return (FALSE);
	element = swap->val_a;
	while (element)
	{
		i = element->val;
		element = element->next;
		if (element && i >= element->val)
			return (FALSE);
	}
	return (TRUE);
}

int		main(int ac, char **av)
{
	t_swap	*swap;
	int		i;

	if (ac < 2)
		return (0);
	swap = memalloc_sterr(sizeof(t_swap), "main");
	swap->line = memalloc_sterr(sizeof(char) * 5, "main");
	make_tab_list(swap, ac, av);
	radix(swap);
	check_val(swap, swap->sort_final, 0, 0);
	if (swap->check_visu == 1)
		init_windows(swap);
	while (!list_is_valid(swap))
	{
		algo(swap);
		swap->nb_move++;
		if (swap->check_visu == 1)
			print_visu(swap);
		else
			ft_putendl(swap->line);
	}
	esc_visu(swap, 1);
	return (0);
}
