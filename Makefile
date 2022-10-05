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

troubleshoot: troubleshoot.c libft.o
	gcc -Wall -Wextra -Werror troubleshoot.c

libft.o: libft.h ft_bzero.c ft_memset.c ft_strlen.c ft_isprint.c ft_isascii.c ft_isalnum.c ft_isdigit.c ft_isalpha.c

	gcc -Wall -Werror -Wextra ft_bzero.c
	gcc -Wall -Werror -Wextra ft_memset.c
	gcc -Wall -Werror -Wextra ft_strlen.c
	gcc -Wall -Werror -Wextra ft_isprint.c
	gcc -Wall -Werror -Wextra ft_isascii.c
	gcc -Wall -Werror -Wextra ft_isalnum.c
	gcc -Wall -Werror -Wextra ft_isdigit.c
	gcc -Wall -Werror -Wextra ft_isalpha.c
