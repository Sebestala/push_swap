
#include "../includes/push_swap.h"

void		ra2(t_swap *swap)
{
	t_val	*element1;

	if (swap->val_a2)
	{
		swap->val_a2->back = swap->val_a_last2;
		swap->val_a_last2->next = swap->val_a2;
		element1 = swap->val_a2->next;
		element1->back = NULL;
		swap->val_a_last2 = swap->val_a2;
		swap->val_a2 = element1;
		swap->val_a_last2->next = NULL;
	}
}

void		ra(t_swap *swap)
{
	t_val	*element1;

	if (swap->val_a)
	{
		swap->val_a->back = swap->val_a_last;
		swap->val_a_last->next = swap->val_a;
		element1 = swap->val_a->next;
		element1->back = NULL;
		swap->val_a_last = swap->val_a;
		swap->val_a = element1;
		swap->val_a_last->next = NULL;
	}
	ra2(swap);
}

void		rb2(t_swap *swap)
{
	t_val	*element1;

	if (swap->val_b2)
	{
		swap->val_b2->back = swap->val_b_last2;
		swap->val_b_last2->next = swap->val_b2;
		element1 = swap->val_b2->next;
		element1->back = NULL;
		swap->val_b_last2 = swap->val_b2;
		swap->val_b2 = element1;
		swap->val_b_last2->next = NULL;
	}
}

void		rb(t_swap *swap)
{
	t_val	*element1;

	if (swap->val_b)
	{
		swap->val_b->back = swap->val_b_last;
		swap->val_b_last->next = swap->val_b;
		element1 = swap->val_b->next;
		element1->back = NULL;
		swap->val_b_last = swap->val_b;
		swap->val_b = element1;
		swap->val_b_last->next = NULL;
	}
	rb2(swap);
}

void		rr(t_swap *swap)
{
	ra(swap);
	rb(swap);
}

void		rr2(t_swap *swap)
{
	ra2(swap);
	rb2(swap);
}
