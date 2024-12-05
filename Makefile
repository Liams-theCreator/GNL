CC = cc
FLAGS = -Werror -Wall -Wextra
SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)
NAME = gnl

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean fclean all

.PHONY: clean fclean re all
