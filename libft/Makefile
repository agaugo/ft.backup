#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hflohil- <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/05 14:00:44 by hflohil-      #+#    #+#                  #
#    Updated: 2022/10/05 14:42:59 by hflohil-      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

SRCS	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c 		    ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft		_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c

#missing memcmp, strnstr and atoi. also calloc strdup and  part 2 functions.
#object target, calls sources ending with .c to compile to .o.
OBJS	= $(SRCS:.c=.o)

#compiler flags, -werror -wextra also include to include headerfiles
CC	= gcc
RM	= rm -f
CFLAGS += -Werror -Wextra -Wall -I.

all:	$(NAME)

#name of target
NAME = libft.a

#entry point
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

all: 	 $(NAME)
