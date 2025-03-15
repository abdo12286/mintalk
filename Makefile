CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = minitalk
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_M)
	@$(CC) $(CFLAGS) $(OBJ) $(OBJ_M) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_M) $(OBJ_BNS)

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all