NAME=pushswap
GCC=gcc -Wall -Werror -Wextra
SOURCES=$(wildcard ./*.c)

NAME:
	cd libft; make re; cp libft.a ../; make clean
	$(GCC) $(SOURCES) push_swap.h libft.a

all: $(NAME)

clean:
	rm -rf $(COMPOBJECTS) $(BONUSOBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

