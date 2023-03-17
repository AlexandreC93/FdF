CC = clang
NAME = lgnl
AR = ar crs
SRC = \
	get_next_line_bonus.c \
	get_next_line_utils_bonus.c \


CFLAGS = -Wall -Wextra -Werror
RM = rm -f
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
