# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaterna <mmaterna@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 14:58:53 by mmaterna          #+#    #+#              #
#    Updated: 2025/03/07 18:30:22 by mmaterna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            =   push_swap

CC              =   cc
CFLAGS          =   -Wall -Wextra -Werror
AR              =   ar
ARFLAGS         =   rcs
RM              =   rm -rf

SRC             =   push_swap push revrotate rotate sort_stack sort_three stack_init swap turk_sort utilis find error_handles
SRCS            =   $(addsuffix .c, $(SRC))

OBJ_DIR         =   obj
OBJS            =   $(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH      =   ./Libft
LIBFT           =   $(LIBFT_PATH)/libft.a

PRINTF_PATH		=	./Printf
PRINTF			=	$(PRINTF_PATH)/libftprintf.a

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: all

$(NAME): $(LIBFT) $(PRINTF) $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(PRINTF):
	make -C $(PRINTF_PATH) all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(PRINTF_PATH) clean
	$(RM) $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	make -C $(PRINTF_PATH) fclean
	$(RM) $(NAME)

re: fclean all