
#include "../includes/push_swap.h"

void		rra2(t_swap *swap)
{
	t_val	*element1;

	if (swap->val_a2)
	{
		swap->val_a2->back = swap->val_a_last2;
		swap->val_a_last2->next = swap->val_a2;
		element1 = swap->val_a_last2->back;
		element1->next = NULL;
		swap->val_a2 = swap->val_a_last2;
		swap->val_a_last2 = element1;
		swap->val_a2->back = NULL;
	}
	swap->check_act2 = RRA;
}

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
	swap->check_act = RRA;
	rra2(swap);
}

void		rrb2(t_swap *swap)
{
	t_val	*element1;

	if (swap->val_b2)
	{
//printf("TEST1  b = %p   b2 = %p  final = %p   final2 = %p\n\n", swap->val_b, swap->val_b2, swap->val_b_last, swap->val_b_last2);
		swap->val_b2->back = swap->val_b_last2;
		swap->val_b_last2->next = swap->val_b2;
		element1 = swap->val_b_last2->back;
		element1->next = NULL;
		swap->val_b2 = swap->val_b_last2;
		swap->val_b_last2 = element1;
		swap->val_b2->back = NULL;
	}
	swap->check_act2 = RRB;
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
	swap->check_act = RRB;
	rrb2(swap);
}

void		rrr2(t_swap *swap)
{
	rra2(swap);
	rrb2(swap);
	swap->check_act2 = RRR;
}

void		rrr(t_swap *swap)
{
	rra(swap);
	rrb(swap);
	swap->check_act = RRR;
}
