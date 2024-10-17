# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 11:22:27 by lpin              #+#    #+#              #
#    Updated: 2024/10/11 19:31:45 by lpin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
SRCS = src/push_swap.c src/orchestor.c src/check_entry.c src/check_list.c src/errors.c \
		src/linked_list_utils.c src/ps_utils.c src/list_init.c src/ft_swap.c src/sw_moves.c \
		src/ft_rotate.c src/rt_moves.c src/ft_reverse_rotate.c src/rrt_moves.c src/ft_push.c\
		src/ps_moves.c
LIBFT = ./libft/libft.a
OBJS = $(SRCS:.c=.o)

NAME = push_swap

RM = rm -f

HEADER = ./header/push_swap.h

%o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $(SRCS)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

$(LIBFT):
	@make all -C libft

.PHONY: clean fclean re

clean:
	@$(RM) $(OBJS)
	@make clean -C libft
	@echo "push_swap cleaning done."

fclean: clean
	@$(RM) $(OBJS) $(NAME)
	@make fclean -C libft
	@echo "push_swap full cleaning done."

re: fclean all
	@echo "push_swap rebuild done"
#re: Genera un rebuild del objetivo