
#include "../includes/push_swap.h"

void		sa(t_swap *swap)
{
	t_val	*element1;
	t_val	*element2;

	if (swap->val_a && swap->val_a->next)
	{
		element2 = swap->val_a->next;
		if (element2->next)
		{
			element1 = element2->next;
			element1->back = swap->val_a;
			swap->val_a->next = element1;
		}
		else
		{
			swap->val_a_last = swap->val_a;
			swap->val_a->next = NULL;
		}
		element2->back = NULL;
		element2->next = swap->val_a;
		swap->val_a->back = element2;
		swap->val_a = element2;
	}
}

void		sb(t_swap *swap)
{
	t_val	*element1;
	t_val	*element2;

	if (swap->val_b && swap->val_b->next)
	{
		element2 = swap->val_b->next;
		if (element2->next)
		{
			element1 = element2->next;
			element1->back = swap->val_b;
			swap->val_b->next = element1;
		}
		else
		{
			swap->val_b_last = swap->val_b;
			swap->val_b->next = NULL;
		}
		element2->back = NULL;
		element2->next = swap->val_b;
		swap->val_b->back = element2;
		swap->val_b = element2;
	}
}

void		ss(t_swap *swap)
{
	sa(swap);
	sb(swap);
}
