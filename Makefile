
NAME_CHECKER = checker

NAME_PUSH_SWAP = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIB = libft.a

DLIB = libft/

DSRC = src/

SRC = 		main_checker.c\
			pp.c\
			rr.c\
			rrr.c\
			ss.c\
			radix.c\
			visu.c\
			algo1.c\
			algo2.c\
			algo3.c

OBJ = $(addprefix $(DSRC), $(SRC:.c=.o))

all: $(NAME_CHECKER)

$(NAME_CHECKER) : $(LIB) $(OBJ)
	@$(CC) $(OBJ) $(DLIB)$(LIB) -lncurses -o $@

$(DSRC)%.o : $(DSRC)%.c includes/$(NAME_CHECKER).h
	@echo "compilation de $< \033[32m ok \033[0m"
	@$(CC) $(FLAGS) -o $@ -c $<

$(LIB) : 
	@make -C $(DLIB)

clean :
	@make -C $(DLIB) clean
	@rm -r $(OBJ)

fclean : clean
	@make -C $(DLIB) fclean
	@rm -r $(NAME_CHECKER)
	@rm -r $(NAME_CHECKER).a

re : fclean all
