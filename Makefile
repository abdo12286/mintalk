SERVER =  server.c
CLIENT =  client.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME_S = server
NAME_C = client
OBJ_S = $(SERVER:.c=.o)
OBJ_C = $(CLIENT:.c=.o)
all: $(NAME_C) $(NAME_S)

$(NAME_S): $(OBJ_S)
	@$(CC) $(CFLAGS) $(OBJ_S) -o $(NAME_S)

$(NAME_C): $(OBJ_C)
	@$(CC) $(CFLAGS) $(OBJ_C) -o $(NAME_C)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_S) $(OBJ_C)
fclean: clean
	@rm -f $(NAME_C) $(NAME_S)
re: fclean all