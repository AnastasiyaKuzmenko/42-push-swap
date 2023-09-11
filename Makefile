# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 13:15:54 by akuzmenk          #+#    #+#              #
#    Updated: 2023/04/26 17:10:40 by akuzmenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
FLAGS := -Wall -Wextra -Werror
LIBFT_DIR := ./libft
LIBFT_LIB := $(LIBFT_DIR)/libft.a

SRCS := 			\
		main.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		swap.c \
		sort_small.c \
		find_index.c \
		check_errors.c \
		lst_helpers.c \
		sort_radix.c

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS)
	make -sC $(LIBFT_DIR)
	cc $(FLAGS) -c $(SRCS)
	cc $(FLAGS) $(SRCS) -o $(NAME) -L. $(LIBFT_LIB)

clean:
	make clean -sC $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -sC $(LIBFT_DIR)
	rm -f $(NAME)
	
re: fclean all

.PHONY: clean fclean re
