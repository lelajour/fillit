# **************************************************************************** #
#                                                          LE - /              #
#                                                              /               #
#   Makefile                                         .::    .:/ .      .::     #
#                                                 +:+:+   +:    +:  +:+:+      #
#   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+       #
#                                                 #+#   #+    #+    #+#        #
#   Created: 2018/01/09 21:16:38 by lelajour     #+#   ##    ##    #+#         #
#   Updated: 2018/01/10 16:00:16 by lelajour    ###    #+. /#+    ###.fr       #
#                                                         /                    #
#                                                        /                     #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc

CFLAGS = -Werror -Wextra -Wall

NAME = fillit

D_SRC = fillit_src/src/

D_LIBFT = libft/

SRC1 =     fillit_file_check.c fillit_store.c ft_fail.c little_fonction.c \
           main.c new_tab.c resolve.c valid_tetri.c \

SRC2=     ft_strchr.c ft_putendl.c ft_strsplit.c ft_strnew.c ft_colchr.c\
        ft_memcpy.c ft_putchar.c ft_putstr.c ft_memdel.c ft_memset.c \
        ft_strlen.c ft_swap_line.c ft_bzero.c ft_swap_col.c\
		ft_strcpy.c ft_strdup.c \

SRC_FILL = $(addprefix $(D_SRC), $(SRC1))

SRC_LIB = $(addprefix $(D_LIBFT), $(SRC2))

OBJ = $(SRC_FILL:.c=.o) $(SRC_LIB:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[0;32m✅️    Fillit executable created."

./%.o: ./%.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo "\033[0;32m✅️    $@ created."

clean:
	@rm -f $(OBJ)
	@echo "\033[0;31m🗑️    Deleting object files."

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;31m🗑️    Deleting fillit executable."

re: fclean all
