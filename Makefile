# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 20:13:25 by stena-he          #+#    #+#              #
#    Updated: 2022/10/13 03:47:07 by stena-he         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation
NAME = 	push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
DEBUG = -fsanitize=address

# Libraries
LIBFT = libraries/ft_printf/libft/libft.a
PRINTF = libraries/ft_printf/libftprintf.a

# Paths
SRC_PATH = src/
OBJ_PATH = obj/
LIBFT_PATH = libraries/ft_printf/libft
PRINTF_PATH = libraries/ft_printf

# Source and object files
SRC =	main.c \
		parse_args.c \
		ft_sort.c \
		ft_sort_cont.c \
		exec_actions.c \
		final_sort.c \
		ft_sort_utils.c \
		linked_lists.c \
		utils.c \
		push.c \
		swap.c \
		rotate.c \
		reverse_rotate.c

# Add prefixes
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRCS:.c=.o)

# Objects
PRINTF_OBJ = libraries/ft_printf/*.o
LIBFT_OBJ = libraries/ft_printf/libft/*.o
SRC_OBJ = src/*.o

# Rules
all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJ)
	$(MAKE) -C $(PRINTF_PATH)
	mv $(PRINTF_OBJ) $(OBJ_PATH)
	$(MAKE) -C $(LIBFT_PATH)
	mv $(LIBFT_OBJ) $(OBJ_PATH)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)
	mv $(SRC_OBJ) $(OBJ_PATH)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re