
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/src/libft.h"
# include "../libft/src/ft_printf/include/ft_printf.h"
# include <curses.h>

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
	t_val			*sort_final_a2;//element le plus petit de a
	t_val			*val_b2;
	t_val			*val_b_last2;
	t_val			*sort_final_b2;//element le plus petit de b
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
	int				min_b;
	int				max_b;

	char			*line;
	int				check_part;
	int				last_b;
	int				first_b;
	int				nb_move;
	int				axe_x;
	int				axe_y;
	int				biggest;
	int				smallest;
	int				nb_numb;
	int				speed;
	int				check_visu;
/*	int				a8;
	int				a9;
	int				a0;
	int				a1;
	int				a2;
	int				b9;
	int				b0;
	int				b1;
	int				b2;
	int				xa8;
	int				xa9;
	int				xa0;
	int				xa1;
	int				xa2;
	int				xb9;
	int				xb0;
	int				xb1;
	int				xb2;
*/	int				c;
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
void				calc_tab_distance_b1(t_swap *swap, int i);
void				calc_tab_distance_a1(t_swap *swap, int i);
void				calc_tab_distance_b1_2(t_swap *swap, int i);
void				calc_tab_distance_a1_2(t_swap *swap, int i);
void				init_list_copy(t_swap *swap);

#endif
