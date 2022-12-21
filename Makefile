# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: synicole <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 14:10:25 by synicole          #+#    #+#              #
#    Updated: 2022/11/29 14:10:27 by synicole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES
NAME 		= push_swap
OBJS		= $(SRCS:.c=.o)
CC			= gcc
FLAGS 		= -Wall -Werror -Wextra
SANITIZE	= -fsanitize=address

# SOURCES
SRCS		= 	./srcs/push_swap.c \
				./srcs/ft_error.c \
				./srcs/manipulations/ft_push_a.c \
				./srcs/manipulations/ft_push_b.c \
				./srcs/manipulations/ft_rotate_a.c \
				./srcs/manipulations/ft_rotate_b.c \
				./srcs/manipulations/ft_rotate_rb.c \
				./srcs/manipulations/ft_rotate_ra.c \
				./srcs/manipulations/ft_rotate_rr.c \
				./srcs/manipulations/ft_rotate_rrr.c \
				./srcs/manipulations/ft_swap_a.c \
				./srcs/manipulations/ft_swap_b.c \
				./srcs/manipulations/ft_swap_ss.c

# COLORS
_END=$'\x1b[0m'
_SUCCESS=$'\x1b[42m'
_CLEANED=$'\x1b[44m'

# COMMANDS
$(NAME): 		$(OBJS)
				make -C libft
				$(CC) $(FLAGS) $(OBJS) libft/libft.a -o $(NAME)

all:			$(NAME)

%.o: %.c
				$(CC) -c $(FLAGS) -o $@ $^

clean:
				make clean -C libft
				/bin/rm -rf $(OBJS)
				@echo "$(_CLEANED)🧹Clean object files!$(_END)"

fclean: 		clean
				make fclean -C libft
				/bin/rm -rf $(NAME)
				@echo "$(_CLEANED)🧹Clean executable files!$(_END)"

re: 			fclean all
				@echo "$(_SUCCESS)🧹Clean + 🚀Build!$(_END)"

run:			all
				@$(CC) $(FLAGS) $(SANITIZE) $(OBJS) libft/libft.a -o $(NAME)
				@./$(NAME)

.PHONY:			all clean fclean re