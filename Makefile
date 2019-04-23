NAME	=	ssl

CC		=	gcc
DEBUG	=	-g -fsanitize=address
CFLAGS	=	-Wall -Wextra -Werror -Iincludes  $(DEBUG)

SRC		=	$(wildcard src/*.c)
O_SRC	=	$(patsubst src/%.c, obj/%.o, $(SRC))
MD		=	$(wildcard src/md/*.c)
O_MD	=	$(patsubst src/md/%.c, obj/md/%.o, $(MD))
SHA		=	$(wildcard src/sha/*.c)
O_SHA	=	$(patsubst src/sha/%.c, obj/sha/%.o, $(SHA))

SRCS	=	$(SRC)		$(MD)		$(SHA)
OBJS	=	$(O_SRC)	$(O_MD)		$(O_SHA)

all		:	$(NAME)

obj		:
			mkdir obj
			mkdir obj/md
			mkdir obj/sha

obj/%.o	: 	src/%.c
			$(CC) $(CFLAGS) $(OPTION) -c -o $@ $<

$(NAME)	: 	obj $(OBJS)
			cd lib/libftprintf && make
			mv lib/libftprintf/libftprintf.a .
			$(CC) -o $(NAME) $(CFLAGS) $(SRCS) libftprintf.a

clean	:
			-cd lib/libftprintf && make clean
			-rm -rf obj

fclean	: 	clean
			-rm -f $(NAME)
			-rm -f libftprintf.a

re		: 	fclean $(NAME)

.PHONY	: 	clean fclean re
