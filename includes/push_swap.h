
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
# define COLOR_GREEN1			10   // 106
//# define COLOR_PLAYER_4			88
# define COLOR_WIN_1			10
# define COLOR_WIN_2			11
# define COLOR_GOOD_PLACE		12
# define SIZE_WIN_X				50

typedef	struct		s_val
{
	int				val;
	int				pos_final;
	struct s_val	*back;
	struct s_val	*next;
	struct s_val	*radix_next;
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
	t_val			*val_b;
	t_val			*val_b_last;
	t_val			*sort_final;
	char			*line;
	int				nb_move;
	int				axe_x;
	int				axe_y;
	int				biggest;
	int				smallest;
	int				nb_numb;
	int				speed;
	int				check_visu;
	int				a8;
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
void				radix(t_swap *swap);
void				print_visu(t_swap *swap);
void				esc_visu(t_swap *swap, int i);
void				init_windows(t_swap *swap);
void				algo(t_swap *swap);
int					absolue(int nb);
void				make_value_b(t_swap *swap, t_val *vb, t_val *vlb);
int					is_sb(t_swap *swap);
void				is_rr(t_swap *swap, t_val *element, int check, int i);
void				command(t_swap *swap);

#endif
