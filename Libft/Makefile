# **************************************************************************** #
#                                                          LE - /              #
#                                                              /               #
#   Makefile                                         .::    .:/ .      .::     #
#                                                 +:+:+   +:    +:  +:+:+      #
#   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+       #
#                                                 #+#   #+    #+    #+#        #
#   Created: 2017/11/13 18:17:26 by lelajour     #+#   ##    ##    #+#         #
#   Updated: 2017/12/04 13:35:09 by lelajour    ###    #+. /#+    ###.fr       #
#                                                         /                    #
#                                                        /                     #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = libft.a

SRCS= ft_atoi.c ft_memcpy.c ft_strrev.c ft_strlcat.c ft_lstnew.c ft_lstdelone.c\
	ft_bzero.c ft_memdel.c ft_strcat.c ft_strlen.c ft_strsplit.c ft_isalnum.c\
	ft_memmove.c ft_strchr.c ft_strmap.c ft_strstr.c ft_isalpha.c ft_memset.c\
	ft_strclr.c ft_strmapi.c ft_strsub.c ft_isascii.c ft_putchar.c ft_strcmp.c\
	ft_strncat.c ft_strtrim.c ft_isdigit.c ft_putchar_fd.c ft_strcpy.c\
	ft_strncmp.c ft_tolower.c ft_isprint.c ft_putendl.c ft_strdel.c ft_strncpy.c\
	ft_toupper.c ft_itoa.c ft_putendl_fd.c  ft_strdup.c ft_strnequ.c\
	ft_memalloc.c ft_putnbr.c ft_strequ.c ft_strnew.c ft_memccpy.c ft_lstdel.c\
	ft_putnbr_fd.c ft_striter.c ft_strnstr.c ft_memchr.c ft_putstr.c\
	ft_striteri.c ft_strrch.c ft_memcmp.c ft_putstr_fd.c ft_strjoin.c\
	ft_lstadd.c ft_strrchr.c ft_lstiter.c ft_lstmap.c ft_fail.c ft_strndup.c\
	ft_strlentab.c ft_swap.c ft_colchr.c ft_swap_line.c ft_swap_col.c\

OBJ= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

./%.o: ./%.c
	gcc -Wall -Wextra -Werror -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
