
#include "../includes/push_swap.h"

void		pa(t_swap *swap)
{
	t_val	*element1;
	t_val	*element2;

	if (swap->val_b)
	{
		element1 = swap->val_b;
		if (swap->val_b_last == swap->val_b)
		{
			swap->val_b_last = NULL;
			swap->val_b = NULL;
		}
		else
		{
			element2 = swap->val_b->next;
			element2->back = NULL;
			swap->val_b = element2;
		}
		element1->next = swap->val_a;
		if (swap->val_a)
			swap->val_a->back = element1;
		else
			swap->val_a_last = element1;
		swap->val_a = element1;
	}
}

void		pb(t_swap *swap)
{
	t_val	*element1;
	t_val	*element2;

	if (swap->val_a)
	{
		element1 = swap->val_a;
		if (swap->val_a_last == swap->val_a)
		{
			swap->val_a_last = NULL;
			swap->val_a = NULL;
		}
		else
		{
			element2 = swap->val_a->next;
			element2->back = NULL;
			swap->val_a = element2;
		}
		element1->next = swap->val_b;
		if (swap->val_b)
			swap->val_b->back = element1;
		else
			swap->val_b_last = element1;
		swap->val_b = element1;
	}
}
