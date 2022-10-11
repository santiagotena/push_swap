# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 20:13:25 by stena-he          #+#    #+#              #
#    Updated: 2022/10/11 22:32:40 by stena-he         ###   ########.fr        #
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

# Source and object files
SRC =	main.c \
		parse_args.c \
		ft_sort.c \
		ft_sort_cont.c \
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
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))			

# Rules
all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJ)
	$(MAKE) -C libraries/ft_printf
	mv libraries/ft_printf/*.o obj/
	$(MAKE) -C libraries/ft_printf/libft
	mv libraries/ft_printf/libft/*.o obj/
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)
	mv src/*.o obj/

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re