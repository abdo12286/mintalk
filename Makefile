SERVER =  server.c
CLIENT =  client.c
SRC = ft_atoi.c  ft_putnbr.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME_S = server
NAME_C = client
OBJ_SRC = $(SRC:.c=.o)
OBJ_S = $(SERVER:.c=.o)
OBJ_C = $(CLIENT:.c=.o)
all: $(NAME_C) $(NAME_S)

$(NAME_S): $(OBJ_S) $(OBJ_SRC)
	@$(CC) $(CFLAGS) $(OBJ_S) $(OBJ_SRC) -o $(NAME_S)

$(NAME_C): $(OBJ_C) $(OBJ_SRC)
	@$(CC) $(CFLAGS) $(OBJ_C) $(OBJ_SRC) -o $(NAME_C)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_S) $(OBJ_C) $(OBJ_SRC)
fclean: clean
	@rm -f $(NAME_C) $(NAME_S)
re: fclean all
