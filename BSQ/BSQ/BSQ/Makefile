CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = srcs
INCDIR = includes

NAME = BSQ

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ -I $(INCDIR)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
