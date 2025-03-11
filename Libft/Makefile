# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaterna <mmaterna@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 17:38:07 by mmaterna          #+#    #+#              #
#    Updated: 2025/02/10 15:30:15 by mmaterna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the library file
NAME = libft.a

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Path to source files
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
      ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
      ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
      ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
      ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
      ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c

# Object files
OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# Default rule
all: $(NAME)

# Creating the libft.a library
$(NAME): $(OBJS)
	ar rcs $@ $^

# Compiling .c files into .o files
$(OBJ_DIR)/%.o: %.c libft.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Creating the object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
# Deleting object files and the library
clean:
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)

# Deleting object files and the library and preparing for a fresh compilation
fclean: clean
	rm -f $(NAME)

# Cleaning and recompiling
re: fclean all
