CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCS = main.c exec.c path.c status.c redirs.c builtins.c
OBJS    = $(SRCS:.c=.o)

NAME    = minishell

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
