#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hflohil- <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2023/03/09 14:00:44 by hflohil-      #+#    #+#                  #
#    Updated: 2023/03/09 13:07:39 by hflohil-      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

SRCS		=	push_swap.c
OBJS		=	push_swap.o

NAME	= program.o
GCC		= gcc
CFLAGS	= -Werror -Wextra -Wall

$(NAME):
	$(GCC) $(CFLAGS) -c $(SRCS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	clean fclean all

.PHONY: all clean fclean re