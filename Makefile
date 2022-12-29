# libft

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libft.a

SOURCES = 	./get_next_line.c \
./get_next_line_utils.c



OBJETS = $(SOURCES:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJETS)
	ar rcs $(NAME) $(OBJETS)
bonus: $(BONUS)
	ar rcs $(NAME) $(BONUS)

clean:
	rm -f $(OBJETS) $(BONUS)
fclean: clean
	rm -f $(NAME)

re: fclean all

so: $(SOURCES) $(OBJETS) $(SOURCES_BONUS) $(BONUS)
	$(CC) -nostartfiles -fPIC $(FLAGS) $(SOURCES) $(SOURCES_BONUS)
	gcc -nostartfiles -shared -o libft.so $(OBJETS) $(BONUS)

.PHONY: all clean fclean re


