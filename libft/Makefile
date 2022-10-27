#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hflohil- <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/05 14:00:44 by hflohil-      #+#    #+#                  #
#    Updated: 2022/10/07 13:07:39 by hflohil-      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

SRCS 	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c ft_striteri.c ft_strtrim.c

#add memcmp, strnstr, atoi, calloc, strdup + part 2.
#object target, calls sources ending with .c to .o
OBJS	= $(SRCS:.c=.o)

#compilation flags
CC		= gcc
RM		= rm -f *.o 
CFLAGS	+= -Werror -Wextra -Wall -I.

all:	$(NAME)

#name of target
NAME	= libft.a

#entry point
$(NAME):	$(OBJS)
				ar rcs $(NAME) $(OBJS)
fclean:
			$(RM) $(NAME)

clean: fclean
			$(RM) $(OBJS)

re:		fclean $(NAME)

all:	$(NAME)

.PHONY: all