/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:37:59 by sgarcia           #+#    #+#             */
/*   Updated: 2019/01/14 19:21:21 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/src/libft.h"
# include "../libft/src/ft_printf/include/ft_printf.h"
# include <curses.h>

# define PA 1
# define PB 2
# define SA 3
# define SB 4
# define SS 5
# define RA 6
# define RB 7
# define RR 8
# define RRB 9
# define RRA 10
# define RRR 11
# define TEN 10
# define COLOR_DEEP				1
# define COLOR_STATS			3
# define COLOR_BORDER			225
# define COLOR_BASIC			139
# define COLOR_GREY_LESS		232
# define COLOR_GREY_LOW			234
# define COLOR_GREY_MEDIUM		235
# define COLOR_GREY_LIGHT		237
# define COLOR_PILE_1			 24
# define COLOR_PILE_2			208
# define COLOR_GREEN1			10
# define COLOR_WIN_1			10
# define COLOR_WIN_2			11
# define COLOR_GOOD_PLACE		12
# define SIZE_WIN_X				50

typedef	struct		s_val
{
	int				val;
	int				pos_final;
	int				pos_final_sort;
	int				pos_current;
	struct s_val	*back;
	struct s_val	*next;
	struct s_val	*radix_next;
	struct s_val	*radix_back;
}					t_val;

typedef	struct		s_tab
{
	void			*tab[TEN];
	int				check;
}					t_tab;

typedef	struct		s_swap
{
	WINDOW			*pile1;
	WINDOW			*pile2;
	WINDOW			*instruction;
	t_tab			*tab_neg1;
	t_tab			*tab_neg2;
	t_tab			*tab_pos1;
	t_tab			*tab_pos2;
	t_val			*val_a;
	t_val			*val_a_last;
	t_val			*sort_final_a;
	t_val			*val_b;
	t_val			*val_b_last;
	t_val			*sort_final_b;
	t_val			*val_a2;
	t_val			*val_a_last2;
	t_val			*sort_final_a2;
	t_val			*val_b2;
	t_val			*val_b_last2;
	t_val			*sort_final_b2;
	t_val			*val;
	t_val			*val2;
	t_val			*elem;
	t_val			*elem2;
	int				*tab_distance_a;
	int				total_distance_a;
	int				*tab_distance_b;
	int				total_distance_b;
	int				*tab_distance_a2;
	int				total_distance_a2;
	int				*tab_distance_b2;
	int				total_distance_b2;
	int				mid_a;
	int				mid_b;
	int				length_a;
	int				length_b;
	int				point_next;
	int				point_back;
	int				length_a2;
	int				length_b2;
	int				mid_a2;
	int				mid_b2;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				res1;
	int				a;
	int				b;
	int				is_sort;
	char			*line;
	int				last_b;
	int				first_b;
	int				nb_move;
	int				axe_x;
	int				axe_y;
	int				biggest;
	int				smallest;
	int				nb_numb;
	int				speed;
	int				check_part;
	int				check_visu;
	int				check_move;
	int				check_speed;
	int				check_act;
	int				check_act2;
	int				c;
}					t_swap;

void				pa(t_swap *swap);
void				pb(t_swap *swap);
void				sa(t_swap *swap);
void				sb(t_swap *swap);
void				ss(t_swap *swap);
void				ra(t_swap *swap);
void				rb(t_swap *swap);
void				rr(t_swap *swap);
void				rra(t_swap *swap);
void				rrb(t_swap *swap);
void				rrr(t_swap *swap);
void				pa2(t_swap *swap);
void				pb2(t_swap *swap);
void				sa2(t_swap *swap);
void				sb2(t_swap *swap);
void				ss2(t_swap *swap);
void				ra2(t_swap *swap);
void				rb2(t_swap *swap);
void				rr2(t_swap *swap);
void				rra2(t_swap *swap);
int					test_pile(t_val *val);
void				rrb2(t_swap *swap);
void				rrr2(t_swap *swap);
void				radix(t_swap *swap, char c);
void				print_visu(t_swap *swap);
void				print_visu_ps(t_swap *swap);
void				esc_visu(t_swap *swap, int i);
void				init_windows(t_swap *swap);
void				init_windows_ps(t_swap *swap);
void				algo(t_swap *swap);
int					absolue(int nb);
void				make_value_b(t_swap *swap, t_val *vb, t_val *vlb);
int					is_sb(t_swap *swap);
void				is_rr(t_swap *swap, t_val *element, int check, int i);
void				command(t_swap *swap);
void				check_val(t_swap *swap, t_val *val, int j, int i);
void				make_val_list(t_swap *swap, int nb);
void				make_tab_list(t_swap *swap, int ac, char **av);
void				check_list_int(t_swap *swap, int ac, char **av, int i);
void				print_player(t_swap *swap, int i, int j, int k);
WINDOW				*init_win_instruction(WINDOW *instruction, t_swap *swap);
WINDOW				*init_win_player(t_swap *swap, WINDOW *player, int check,
int i);
void				init_visu(void);
void				color_the_deep(t_swap *swap);
void				algo_part1(t_swap *swap);
void				algo_part2(t_swap *swap);
void				radix_sort_algo(t_tab *tab1, t_tab *tab2, int size);
void				radix_put_val_at_end_list(t_val *val, void **tab, int nb);
void				radix2(t_swap *swap, char c);
void				calc_tab_distance_b1(t_swap *swap, int i, int check);
void				calc_tab_distance_a1(t_swap *swap, int i, int check);
void				calc_tab_distance_b1_2(t_swap *swap, int i, int check);
void				calc_tab_distance_a1_2(t_swap *swap, int i, int check);
void				init_list_copy(t_swap *swap);
void				radix_init(t_swap *swap);
void				radix_zero(t_swap *swap);
void				test_radix(t_swap *swap, int nb, char c);
int					test_pile2(t_val *first, t_val *begin);
int					is_pa2(t_swap *swap);
int					is_pb2(t_swap *swap);
int					is_ss2(t_swap *swap);
void				do_ss(t_val *val, int *tab, int len, t_swap *swap);
void				is_radix2(t_swap *swap);
int					is_rrb2(t_swap *swap);
int					is_rb2(t_swap *swap);
int					is_pa(t_swap *swap);
int					is_rrb(t_swap *swap);
int					is_rb(t_swap *swap);
void				algo3(t_swap *swap);
void				write_clone(t_swap *swap, t_val *elem3);
void				test_list(t_swap *swap, int nb, char c);
void				free_struct(t_swap *swap);
void				find_rra_rb(t_swap *swap, t_val *el, t_val *el2,
		t_val *back);
void				find_rra_rrb(t_swap *swap, t_val *el, t_val *el2,
		t_val *back);
void				find_ra_rrb(t_swap *swap, t_val *el, t_val *el2,
		t_val *back);
void				find_ra_rb(t_swap *swap, t_val *el, t_val *el2,
		t_val *back);
void				clean_result(t_swap *swap);

#endif
