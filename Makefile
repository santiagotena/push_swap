# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 20:13:25 by stena-he          #+#    #+#              #
#    Updated: 2022/09/28 00:48:22 by stena-he         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation
NAME = 	push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
DEBUG = -fsanitize=address

# Removal
RM = rm -f

# Libraries
LIBFT = libraries/ft_printf/libft/libft.a
PRINTF = libraries/ft_printf/libftprintf.a

# Source and object files
SRC =	src/main.c \
		src/parse_args.c \
		src/ft_atoi_mod.c \
		src/actions/push.c \
		src/actions/swap.c \
		src/actions/rotate.c \
		src/actions/reverse_rotate.c
			
OBJ = $(SRC:%.c=%.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libraries/ft_printf
	$(MAKE) -C libraries/ft_printf/libft
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	$(MAKE) clean -C libraries/ft_printf
	$(MAKE) clean -C libraries/ft_printf/libft
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(MAKE) fclean -C libraries/ft_printf
	$(MAKE) fclean -C libraries/ft_printf/libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re