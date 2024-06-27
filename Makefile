NAME = pipex

SRC	=	pipex.c


OBJ = $(SRC:.c=.o)

CC = gcc -g

CFLAGS = -Wall -Wextra -Werror -g

LIBFTPRINTF = ./sources/printf/libftprintf.a
LIBFTPRINTF_DIR = ./sources/printf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(MLX) $(LIBFTPRINTF) -lX11 -lXext

$(LIBFTPRINTF):
	make -C $(LIBFTPRINTF_DIR)

clean:
	rm -f $(OBJ)
	make -C $(LIBFTPRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTPRINTF_DIR) fclean
	
re: fclean $(NAME)

val:
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes -s ./pipex infile "ls -l" "grep 'july'" outfile.txt

.PHONY:	all clean fclean re 