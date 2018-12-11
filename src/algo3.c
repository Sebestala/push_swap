
#include "../includes/push_swap.h"

void		clean_result(t_swap *swap)
{
	swap->ra = 0;
	swap->rb = 0;
	swap->rr = 0;
	swap->rra = 0;
	swap->rrb = 0;
	swap->rrr = 0;
}

static void		find_rra_rb2(t_swap *swap)
{
	clean_result(swap);
	swap->res1 = swap->b + swap->a;
	swap->rra = swap->a;
	swap->rb = swap->b;
}

static void		find_rra_rb(t_swap *swap, t_val *el, t_val *el2, t_val *back)
{
	while (swap->a < swap->res1 || swap->res1 == 0)
	{
		if (!el2 || (swap->b >= swap->res1 && swap->res1 != 0))
		{
			back = el;
			el = el->back;
			el2 = swap->val_b;
			swap->b = 0;
			swap->a++;
		}
/*		if (el)
			printf("A = %d", el->val);
		if (back)
			printf("   A2 = %d", back->val);
		if (el2)
			printf("   B = %d", el2->val);
		printf("   a = %d   b = %d\n", swap->a, swap->b);
*/		if (!el || !el2)
			break ;
		if ((el2->val < back->val || back->pos_final_sort == 1) &&
					el2->val > el->val && swap->a + swap->b < swap->res1)
			find_rra_rb2(swap);
		el2 = el2->next;
		swap->b++;
	}
}

static void		find_rra_rrb2(t_swap *swap)
{
	clean_result(swap);
	if (swap->a < swap->b)
	{
		swap->res1 = swap->b;
		swap->rrr = swap->a;
		swap->rrb = swap->b - swap->a;
	}
	else
	{
		swap->res1 = swap->a;
		swap->rrr = swap->b;
		swap->rra = swap->a - swap->b;
	}
}

static void		find_rra_rrb(t_swap *swap, t_val *el, t_val *el2, t_val *back)
{
	while (swap->a < swap->res1 || swap->res1 == 0)
	{
		if (!el2 || (swap->b >= swap->res1 && swap->res1 != 0))
		{
			back = el;
			el = el->back;
			el2 = swap->val_b;
			swap->b = 0;
			swap->a++;
		}
/*		if (el)
			printf("A = %d", el->val);
		if (back)
			printf("   A2 = %d", back->val);
		if (el2)
		if (el)
			printf("A = %d", el->val);
			printf("   B = %d", el2->val);
		printf("   a = %d   b = %d\n", swap->a, swap->b);
		if (el)
			printf("A = %d", el->val);
*/		if (!el || !el2)
			break ;
		if ((el2->val < back->val || back->pos_final_sort == 1) &&
	el2->val > el->val && (swap->a < swap->res1 && swap->b < swap->res1))
			find_rra_rrb2(swap);
		if (el2 == swap->val_b && swap->val_b_last != el2)
			el2 = swap->val_b_last;
		else
			el2 = el2->back;
		swap->b++;
	}
}

static void		find_ra_rrb2(t_swap *swap)
{
	clean_result(swap);
	swap->res1 = swap->b + swap->a;
	swap->ra = swap->a;
	swap->rrb = swap->b;
}

static void		find_ra_rrb(t_swap *swap, t_val *el, t_val *el2, t_val *back)
{
	while (swap->a < swap->res1 || swap->res1 == 0)
	{
		if (!el2 || (swap->b + swap->a >= swap->res1 && swap->res1 != 0))
		{
			back = el;
			el = el->next;
			el2 = swap->val_b;
			swap->b = 0;
			swap->a++;
		}
/*		if (el)
			printf("A = %d", el->val);
		if (back)
			printf("   A2 = %d", back->val);
		if (el2)
			printf("   B = %d", el2->val);
		printf("   a = %d   b = %d\n", swap->a, swap->b);
*/		if (!el || !el2)
			break ;
		if (el2->val > back->val && (el2->val < el->val || el->pos_final_sort == 1) &&
				swap->a + swap->b < swap->res1)
			find_ra_rrb2(swap);
		if (el2 == swap->val_b && swap->val_b_last != el2)
			el2 = swap->val_b_last;
		else
			el2 = el2->back;
		swap->b++;
	}
}

static void		find_ra_rb2(t_swap *swap)
{
	clean_result(swap);
	if (swap->a < swap->b)
	{
		swap->res1 = swap->b;
		swap->rr = swap->a;
		swap->rb = swap->b - swap->a;
	}
	else
	{
		swap->res1 = swap->a;
		swap->rr = swap->b;
		swap->ra = swap->a - swap->b;
	}
}

static void		find_ra_rb(t_swap *swap, t_val *el, t_val *el2, t_val *back)
{
	while (swap->a < swap->res1 || swap->res1 == 0)
	{
		if (!el2 || (swap->b >= swap->res1 && swap->res1 != 0))
		{
			back = el;
			el = el->next;
			el2 = swap->val_b;
			swap->b = 0;
			swap->a++;
		}
/*		if (el)
			printf("A = %d", el->val);
		if (back)
			printf("   A2 = %d", back->val);
		if (el2)
			printf("   B = %d", el2->val);
		printf("   a = %d   b = %d\n", swap->a, swap->b);
*/		if (!el || !el2)
			break ;
		if (el2->val > back->val && (el2->val < el->val ||
	el->pos_final_sort == 1) && (swap->a < swap->res1 && swap->b < swap->res1))
			find_ra_rb2(swap);
		el2 = el2->next;
		swap->b++;
	}
}

void		find_end(t_swap *swap)
{
	t_val	*el;
	int		i;

	el = swap->val_a;
	i = 0;
	while (el && el->pos_final_sort != 1)
	{
		el = el->next;
		i++;
	}
	if (i <= swap->length_a / 2 + swap->length_a % 2)
	{
		swap->ra = i - 1;
		ra(swap);
		swap->line = ft_strncpy(swap->line, "ra2", 3);
	}
	else
	{
		swap->rra = i - 1;
		rra(swap);
		swap->line = ft_strncpy(swap->line, "rra", 3);
	}
}

void		algo3(t_swap *swap)
{
	if (swap->is_sort == 0 || (swap->is_sort == 1 && !swap->val_b))
	{
		clean_result(swap);
		swap->is_sort++;
	}
	if (swap->ra == 0 && swap->rb == 0 && swap->rr == 0 && swap->rra == 0 && swap->rrb == 0 && swap->rrr == 0)
	{
		swap->res1 = 9999;
		swap->a = 0;
		swap->b = 0;
//		printf("ra = %d rb = %d rr = %d rra = %d rrb = %d rrr = %d  swap->res1 = %d\n", swap->ra, swap->rb, swap->rr, swap->rra, swap->rrb, swap->rrr, swap->res1);
		find_ra_rb(swap, swap->val_a, swap->val_b, swap->val_a_last);
		swap->a = 0;
		swap->b = 0;
//		printf("ra = %d rb = %d rr = %d rra = %d rrb = %d rrr = %d  swap->res1 = %d\n", swap->ra, swap->rb, swap->rr, swap->rra, swap->rrb, swap->rrr, swap->res1);
		find_rra_rrb(swap, swap->val_a_last, swap->val_b, swap->val_a);
		swap->a = 0;
		swap->b = 0;
//		printf("ra = %d rb = %d rr = %d rra = %d rrb = %d rrr = %d  swap->res1 = %d\n", swap->ra, swap->rb, swap->rr, swap->rra, swap->rrb, swap->rrr, swap->res1);
		find_ra_rrb(swap, swap->val_a, swap->val_b, swap->val_a_last);
		swap->a = 0;
		swap->b = 0;
//		printf("ra = %d rb = %d rr = %d rra = %d rrb = %d rrr = %d  swap->res1 = %d\n", swap->ra, swap->rb, swap->rr, swap->rra, swap->rrb, swap->rrr, swap->res1);
		find_rra_rb(swap, swap->val_a_last, swap->val_b, swap->val_a);
//		printf("ra = %d rb = %d rr = %d rra = %d rrb = %d rrr = %d  swap->res1 = %d\n", swap->ra, swap->rb, swap->rr, swap->rra, swap->rrb, swap->rrr, swap->res1);
	}
	if (swap->rr > 0)
	{
		rr(swap);
		swap->line = ft_strncpy(swap->line, "rr ", 3);
		swap->rr--;
	}
	else if (swap->rrr > 0)
	{
		rrr(swap);
		swap->line = ft_strncpy(swap->line, "rrr", 3);
		swap->rrr--;
	}
	else if (swap->ra > 0)
	{
		ra(swap);
		swap->line = ft_strncpy(swap->line, "ra ", 3);
		swap->ra--;
	}
	else if (swap->rb > 0)
	{
		rb(swap);
		swap->line = ft_strncpy(swap->line, "rb ", 3);
		swap->rb--;
	}
	else if (swap->rra > 0)
	{
		rra(swap);
		swap->line = ft_strncpy(swap->line, "rra", 3);
		swap->rra--;
	}
	else if (swap->rrb > 0)
	{
		rrb(swap);
		swap->line = ft_strncpy(swap->line, "rrb", 3);
		swap->rrb--;
	}
	else
		find_end(swap);
}
