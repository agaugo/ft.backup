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

NAME    = so_long
CC		= gcc
CFLAGS	= -Werror -Wextra -Wall MLX42/libmlx42.a -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw 

SRC_PATH    =   src/
OBJ_PATH    =   obj/

SRC         =	so_long.c
SRCS        =   $(addprefix, $(SRC_PATH), $(SRC))

OBJ         =   $(SRC:.c=.o)
OBJS		=	$(addprefix $(OBJ_PATH), $(OBJ))

INC         =   -I ./include/

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
