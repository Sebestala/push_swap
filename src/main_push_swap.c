
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
	if (nb == swap->nb_numb)
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
	radix_init(swap);
	radix(swap, 'a');
	check_val(swap, swap->sort_final_a, 0, 0);
	init_list_copy(swap);
	calc_tab_distance_a1(swap, 0, 0);
	write_clone(swap, swap->val_a_last2);
	if (swap->check_visu > 0)
	{
		init_windows_ps(swap);
		print_visu_ps(swap);
	}
	while (!list_is_valid(swap))
	{
		algo(swap);
		swap->nb_move++;
		if (swap->check_visu > 0)
			print_visu_ps(swap);
		else if (swap->check_speed == 0)
			ft_putendl(swap->line);
	}
	esc_visu(swap, 1);
	ft_printf("Move : %d\n", swap->nb_move);
	free_struct(swap);
	return (0);
}
