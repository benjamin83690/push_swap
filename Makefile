CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
HEADER	= include
SRCS	= srcs/algo.c \
		  srcs/decoupe.c \
		  srcs/groupe_id.c \
		  srcs/init_add.c \
		  srcs/move.c \
		  srcs/sort.c \
		  srcs/tab.c \
		  srcs/check_error.c \
		  srcs/ft_function.c \
		  srcs/index.c \
		  srcs/len_count.c \
		  srcs/push_swap.c \
		  srcs/suite_funcs.c
RM		= rm -f
NAME	= push_swap

OBJS 	= $(SRCS:.c=.o)

.c.o:
			$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) -o $@ $^ $(CFLAGS)

clean:
	$(RM) srcs/*.o

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY : all clean fclean re
