NAME	=	libftprintf.a

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -Iincludes

S_PTF	=	$(wildcard src/printf/*.c)
O_PTF	=	$(patsubst src/printf/%.c, obj/printf/%.o, $(S_PTF))
S_STR	=	$(wildcard src/string/*.c)
O_STR	=	$(patsubst src/string/%.c, obj/string/%.o, $(S_STR))
S_NUM	=	$(wildcard src/number/*.c)
O_NUM	=	$(patsubst src/number/%.c, obj/number/%.o, $(S_NUM))
S_MEM	=	$(wildcard src/memory/*.c)
O_MEM	=	$(patsubst src/memory/%.c, obj/memory/%.o, $(S_MEM))
S_LST	=	$(wildcard src/list/*.c)
O_LST	=	$(patsubst src/list/%.c, obj/list/%.o, $(S_LST))
S_GNL	=	$(wildcard src/get_next_line/*.c)
O_GNL	=	$(patsubst src/get_next_line/%.c, obj/get_next_line/%.o, $(S_GNL))
S_FD	=	$(wildcard src/file_descriptor/*.c)
O_FD	=	$(patsubst src/file_descriptor/%.c, obj/file_descriptor/%.o, $(S_FD))
S_CHK	=	$(wildcard src/checking/*.c)
O_CHK	=	$(patsubst src/checking/%.c, obj/checking/%.o, $(S_CHK))

SRCS	=	$(S_PTF)	$(S_STR)	$(S_NUM)	$(S_MEM)	$(S_LST)	$(S_GNL)	$(S_FD)	$(S_CHK)
OBJS	=	$(O_PTF)	$(O_STR)	$(O_NUM)	$(O_MEM)	$(O_LST)	$(O_GNL)	$(O_FD)	$(O_CHK)

all		:	$(NAME)

obj		:
			@mkdir obj
			@mkdir obj/printf
			@mkdir obj/string
			@mkdir obj/number
			@mkdir obj/memory
			@mkdir obj/list
			@mkdir obj/get_next_line
			@mkdir obj/file_descriptor
			@mkdir obj/checking

obj/%.o	: 	src/%.c
			@$(CC) $(CFLAGS) $(OPTION) -c -o $@ $<

$(NAME)	: 	obj $(OBJS)
			@ar rc $(NAME) $(OBJS)
			@ranlib $(NAME)
			@echo "libftprintf.a has been made"

clean	:
			-rm -rf obj

fclean	: 	clean
			-rm -f $(NAME)

re		: 	fclean $(NAME)

.PHONY	: 	clean fclean re
