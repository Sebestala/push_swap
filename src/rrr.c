
#include "../includes/push_swap.h"

void		rra(t_swap *swap)
{
	t_val	*element1;

	if (swap->val_a)
	{
		swap->val_a->back = swap->val_a_last;
		swap->val_a_last->next = swap->val_a;
		element1 = swap->val_a_last->back;
		element1->next = NULL;
		swap->val_a = swap->val_a_last;
		swap->val_a_last = element1;
		swap->val_a->back = NULL;
	}
}

void		rrb(t_swap *swap)
{
	t_val	*element1;

	if (swap->val_b)
	{
		swap->val_b->back = swap->val_b_last;
		swap->val_b_last->next = swap->val_b;
		element1 = swap->val_b_last->back;
		element1->next = NULL;
		swap->val_b = swap->val_b_last;
		swap->val_b_last = element1;
		swap->val_b->back = NULL;
	}
}

void		rrr(t_swap *swap)
{
	rra(swap);
	rrb(swap);
}
