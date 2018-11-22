
#include "../includes/push_swap.h"

void		sa2(t_swap *swap)
{
	t_val	*element1;
	t_val	*element2;

	if (swap->val_a2 && swap->val_a2->next)
	{
		element2 = swap->val_a2->next;
		if (element2->next)
		{
			element1 = element2->next;
			element1->back = swap->val_a2;
			swap->val_a2->next = element1;
		}
		else
		{
			swap->val_a_last2 = swap->val_a2;
			swap->val_a2->next = NULL;
		}
		element2->back = NULL;
		element2->next = swap->val_a2;
		swap->val_a2->back = element2;
		swap->val_a2 = element2;
	}
}

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
	sa2(swap);
}

void		sb2(t_swap *swap)
{
	t_val	*element1;
	t_val	*element2;

	if (swap->val_b2 && swap->val_b2->next)
	{
		element2 = swap->val_b2->next;
		if (element2->next)
		{
			element1 = element2->next;
			element1->back = swap->val_b2;
			swap->val_b2->next = element1;
		}
		else
		{
			swap->val_b_last2 = swap->val_b2;
			swap->val_b2->next = NULL;
		}
		element2->back = NULL;
		element2->next = swap->val_b2;
		swap->val_b2->back = element2;
		swap->val_b2 = element2;
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
	sb2(swap);
}

void		ss(t_swap *swap)
{
	sa(swap);
	sb(swap);
}

void		ss2(t_swap *swap)
{
	sa2(swap);
	sb2(swap);
}
