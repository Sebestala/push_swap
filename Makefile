
NAME_CHECKER = checker

NAME_PUSH_SWAP = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIB = libft.a

DLIB = libft/

DSRC = src/

SRC = 		main_checker.c\
			visu.c

SRC2 =		main_push_swap.c\
			visu_ps.c\
			calc_distance2.c\
			algo.c\
			algo2.c\
			algo3.c\
			algo4.c\
			algo5.c\
			algo6.c\
			radix2.c


SRC3 = 		check.c\
			pp.c\
			rr.c\
			rrr.c\
			ss.c\
			radix.c\
			visu_both.c\
			visu_both2.c\
			calc_distance.c\
			radix_shared.c

OBJ = $(addprefix $(DSRC), $(SRC:.c=.o))

OBJ2 = $(addprefix $(DSRC), $(SRC2:.c=.o))

OBJ3 = $(addprefix $(DSRC), $(SRC3:.c=.o))

all: $(NAME_CHECKER) $(NAME_PUSH_SWAP)

$(NAME_CHECKER) : $(LIB) $(OBJ) $(OBJ3)
	@$(CC) $(OBJ) $(OBJ3) $(DLIB)$(LIB) -lncurses -o $@

$(NAME_PUSH_SWAP) : $(LIB) $(OBJ2) $(OBJ3)
	@echo "creation de $@ \033[32m ok \033[0m"
	@$(CC) $(OBJ2) $(OBJ3) $(DLIB)$(LIB) -lncurses -o $@

$(DSRC)%.o : $(DSRC)%.c includes/$(NAME_CHECKER).h
	@echo "compilation de $< \033[32m ok \033[0m"
	@$(CC) $(FLAGS) -o $@ -c $<

$(LIB) : 
	@make -C $(DLIB)

clean :
	@make -C $(DLIB) clean
	@rm -r $(OBJ)
	@rm -r $(OBJ2)
	@rm -r $(OBJ3)

fclean : clean
	@make -C $(DLIB) fclean
	@rm -r $(NAME_CHECKER)
	@rm -r $(NAME_PUSH_SWAP)

re : fclean all
