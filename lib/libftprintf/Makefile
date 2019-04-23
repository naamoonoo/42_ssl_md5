NAME=libftprintf.a

SRC=$(wildcard src/*.c)
LIBFT=lib/libft
LRC=$(wildcard $(LIBFT)/src/*.c)
CC=gcc
CFLAGS=-Wall -Wextra -Werror -Iincludes
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))
LOBJ = $(patsubst $(LIBFT)/src/%.c, $(LIBFT)/obj/%.o, $(LRC))

all: $(NAME)

$(NAME): obj $(OBJ)
	cd lib/libft && make pre
	ar rc $(NAME) $(OBJ) $(LOBJ)
	ranlib $(NAME)

obj:
	mkdir obj

obj/%.o: src/%.c
	gcc $(CFLAGS) $(OPTION) -c -o $@ $<

clean:
	-cd lib/libft && make clean
	-rm -rf obj

fclean: clean
	-rm -f $(NAME)
	-rm -f libft.a

re: fclean $(NAME)

.PHONY: clean fclean re
