# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguillie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/14 13:37:13 by pguillie          #+#    #+#              #
#*   Updated: 2016/11/28 15:16:47 by pbourlet         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCF = 	\
		main.c \
		ft_check.c \
		ft_checkbeside.c\
		ft_errors.c \
		ft_solve.c\
		ft_space.c\
		ft_append.c\
		ft_disp.c \
		ft_erase.c \
		ft_sizemin.c\
		ft_init.c \

SRCL = \
	   libft/ft_putendl.c\
	   libft/ft_putendl_fd.c\
	   libft/ft_sqrt.c\
	   libft/ft_strnew.c\
	   libft/ft_memset.c\
	   libft/ft_strdup.c\
	   libft/ft_strcpy.c\
	   libft/ft_putchar.c\
	   libft/ft_putstr.c\
	   libft/ft_strclr.c\
	   libft/ft_strlen.c\

OBJ = \
	  $(SRCF:.c=.o)\
	  ft_putendl.o\
	  ft_putendl_fd.o\
	  ft_sqrt.o\
	  ft_strnew.o\
	  ft_memset.o\
	  ft_strdup.o\
	  ft_strcpy.o\
	  ft_putchar.o\
	  ft_putstr.o\
	  ft_strclr.o\
	  ft_strlen.o\

all: $(NAME)

$(NAME): 
	gcc -c -Wall -Werror -Wextra $(SRCF) $(SRCL)
	gcc -Wall -Werror -Wextra -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
