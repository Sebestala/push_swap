
#include "../includes/push_swap.h"

static int		list_is_valid(t_swap *swap)
{
	t_val	*element;
	int		i;
	int		nb;

	nb = 0;
	if (swap->val_b != NULL)
		return (FALSE);
	element = swap->val_a;
	while (element)
	{
		i = element->val;
		element = element->next;
		if (element && i >= element->val)
			return (FALSE);
		nb++;
	}
//printf("nb = %d   numb = %d\n", nb, swap->nb_numb);
	if (nb = swap->nb_numb)
		return (TRUE);
	return (FALSE);
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
	radix(swap, 'a');
	check_val(swap, swap->sort_final_a, 0, 0);
	init_list_copy(swap);
	if (swap->check_visu == 1)
		init_windows_ps(swap);


/*
t_val *el = swap->sort_final;
while (el)
{
printf("val = %d   pos_final = %d   pos_current = %d\n", el->val, el->pos_final, el->pos_current);
el = el->radix_next;
}
printf("\n\n Part 2:\n");
*/


	while (!list_is_valid(swap))
	{
		algo(swap);
		swap->nb_move++;
		if (swap->check_visu == 1)
			print_visu_ps(swap);
		else
			ft_putendl(swap->line);
	}
	esc_visu(swap, 1);
	ft_printf("Move : %d\n", swap->nb_move);
	return (0);
}
