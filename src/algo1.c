
#include "../includes/push_swap.h"

int			absolue(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}

static void		make_value_a2(t_swap *swap, t_val *va)
{
	if (va->next)
	{
		swap->a1 = va->next->pos_final;
		swap->xa1 = va->next->pos_final + 10;
		if (va->next->next)
		{
			swap->a2 = va->next->next->pos_final;
			swap->xa2 = va->next->next->pos_final + 10;
		}
		else
		{
			swap->a2 = 0;
			swap->xa2 = 0;
		}
	}
	else
	{
		swap->a1 = 0;
		swap->xa1 = 0;
		swap->a2 = 0;
		swap->xa2 = 0;
	}
}

static void		make_value_a(t_swap *swap, t_val *va, t_val *vla)
{
	if (va)
	{
		swap->a9 = vla->pos_final;
		swap->xa9 = (vla->pos_final + 10) % swap->nb_numb;
		swap->a0 = va->pos_final;
		swap->xa0 = (va->pos_final + 10) % swap->nb_numb;
		make_value_a2(swap, va);
		if (vla->back)
		{
			swap->a8 = vla->back->pos_final;
			swap->xa8 = (vla->back->pos_final + 10) % swap->nb_numb;
		}
		else
		{
			swap->a8 = 0;
			swap->xa8 = 0;
		}
	}
}

static void		make_value_b2(t_swap *swap, t_val *vb)
{
	swap->b1 = vb->next->pos_final;
	swap->xb1 = vb->next->pos_final + 10;
	if (vb->next->next)
	{
		swap->b2 = vb->next->next->pos_final;
		swap->xb2 = vb->next->next->pos_final + 10;
	}
	else
	{
		swap->b2 = 0;
		swap->xb2 = 0;
	}
}

void		make_value_b(t_swap *swap, t_val *vb, t_val *vlb)
{
	if (vb)
	{
		swap->b0 = vb->pos_final;
		swap->xb0 = (vb->pos_final + 10) % swap->nb_numb;
		swap->b9 = vlb->pos_final;
		swap->xb9 = (vlb->pos_final + 10) % swap->nb_numb;
		if (vb->next)
			make_value_b2(swap, vb);
		else
		{
			swap->b1 = 0;
			swap->xb1 = 0;
			swap->b2 = 0;
			swap->xb2 = 0;
		}
	}
	make_value_a(swap, swap->val_a, swap->val_a_last);
}
