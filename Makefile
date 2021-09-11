NAME=pushswap
GCC=gcc -Wall -Werror -Wextra
SOURCES=$(wildcard ./*.c)
S_OBJ=$(SOURCES:.c=.o)
UTILS=$(wildcard ./utils/*.c)
U_OBJ=$(patsubst ./utils/%.c,%.o,$(wildcard ./utils/*.c))

all: $(NAME)

$(NAME):
	cd libft; make re; cp libft.a ../; make clean
	$(GCC) -c $(SOURCES) $(UTILS)
	$(GCC) -o push_swap $(S_OBJ) $(U_OBJ) -L. -lft

clean:
	rm -rf $(S_OBJ) $(U_OBJ)

fclean: clean
	rm -rf $(NAME) libft.a

re: fclean all

test:
	@echo $(S_OBJ)
	@echo $(U_OBJ)