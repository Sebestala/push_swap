
#include "../includes/push_swap.h"

static void		radix_merge(t_tab *tab1, t_tab *tab2, t_swap *swap, char c)
{
//printf("radix_merge\n");
//fflush(stdout);
	t_val	*val;
	t_val	*element;

	val = tab1->tab[0];
	while (val)
	{
		element = val->radix_next;
		val->radix_next = tab2->tab[0];
		tab2->tab[0] = val;
		tab1->tab[0] = element;
		val = tab1->tab[0];
	}
	if (c == 'a')
		swap->sort_final_a = tab2->tab[0];
	else
		swap->sort_final_b = tab2->tab[0];
	element = tab2->tab[0];
	element->radix_back = NULL;
}

static void		radix_init(t_swap *swap)
{
//printf("radix_init\n");
//fflush(stdout);
	swap->tab_neg1 = memalloc_sterr(sizeof(t_tab), "radix   code : 1");
	swap->tab_neg2 = memalloc_sterr(sizeof(t_tab), "radix   code : 2");
	swap->tab_pos1 = memalloc_sterr(sizeof(t_tab), "radix   code : 3");
	swap->tab_pos2 = memalloc_sterr(sizeof(t_tab), "radix   code : 4");
	swap->tab_neg1->check = 1;
	swap->tab_pos1->check = 1;
}

static void		radix_sort_pos_and_neg(t_swap *swap, char c)
{
//printf("radix_sort_pos_and_neg\n");
//fflush(stdout);
	t_val	*val;

	if (c == 'a')
		val = swap->val_a;
	else
		val = swap->val_b;
	while (val)
	{
//printf(" val = %d \n", val->val);
//fflush(stdout);
		if (val->val < 0)
			radix_put_val_at_end_list(val, swap->tab_neg1->tab, val->val % 10);
		else
			radix_put_val_at_end_list(val, swap->tab_pos1->tab, val->val % 10);
		val = val->next;
	}
}

static void		make_pos_final2(t_swap *swap, char c, t_val *elem)
{
	t_val	*elem2;
	int		i;

	i = 1;
	elem->pos_final = i;
printf("val = %d  back = %p  next = %p \n", elem->val, elem->radix_back, elem->next);
	while (elem->radix_back)
	{
		elem2 = elem;
		elem->radix_next = elem->radix_back;
		elem = elem->radix_next;
		elem->radix_back = elem2;
		i++;
		elem->pos_final = i;
	}
}

static void		make_pos_final(t_swap *swap, char c)
{
	t_val	*elem;
	t_val	*elem2;
	int		i;

	i = 1;
printf("C = %c\n", c);
/*	if (c == 'b')
printf("val = %d  back = %p  next = %p \n", swap->val_b->val, swap->val_b->radix_back, swap->val_b->radix_next);
*/	if (c == 'b')
		elem = swap->sort_final_b;
	else
		elem = swap->sort_final_a;
	elem->pos_final = i;
printf("val = %d  back = %p  next = %p  val_next = %d \n", elem->val, elem->radix_back, elem->radix_next, elem->radix_next->val);
	while (elem->radix_next != NULL)
	{
//printf("A\n");
//fflush(stdout)
if (c == 'a')
printf("A : val = %d \n", elem->val);
if (c == 'b')
printf("B : val = %d \n", elem->val);
		elem2 = elem;
		elem = elem->radix_next;
//printf("elem = %p   elem2 = %p  val = %d\n", elem, elem2, elem->val);
//fflush(stdout);
//printf("B\n");
//fflush(stdout);
		elem->radix_back = elem2;
//printf("C\n");
//fflush(stdout);
		i++;
		elem->pos_final = i;
	}
/*	if (c == 'b')
printf("val = %d  back = %p  next = %p val_final = %d \n", swap->val_b->val, swap->val_b->radix_back, swap->val_b->radix_next, swap->sort_final_b->val);
printf("val = %d  back = %p  next = %p \n", elem->val, elem->radix_back, elem->next);
*/	if (c == 'b')
		make_pos_final2(swap, c, elem);
}

void		radix(t_swap *swap, char c)
{
printf("radix\n");
fflush(stdout);
	int		i;
	int		nb;

	i = 0;
	radix_init(swap);
	radix_sort_pos_and_neg(swap, c);
	nb = swap->smallest;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	radix_sort_algo(swap->tab_neg1, swap->tab_neg2, i);
	i = 0;
	nb = swap->biggest;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	radix_sort_algo(swap->tab_pos1, swap->tab_pos2, i);
	if (swap->tab_neg1->check == 1)
		i = 1;
	else
		i = 0;
	if (swap->tab_pos1->check == 1 && i == 1)
		radix_merge(swap->tab_neg1, swap->tab_pos1, swap, c);
	else if (swap->tab_pos2->check == 1 && i == 1)
		radix_merge(swap->tab_neg1, swap->tab_pos2, swap, c);
	else if (swap->tab_pos1->check == 1 && i == 0)
		radix_merge(swap->tab_neg2, swap->tab_pos1, swap, c);
	else if (swap->tab_pos2->check == 1 && i == 0)
		radix_merge(swap->tab_neg2, swap->tab_pos2, swap, c);
	make_pos_final(swap, c);
}
