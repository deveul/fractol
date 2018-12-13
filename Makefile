# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrenaudi <urenaudi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/26 14:25:25 by vrenaudi          #+#    #+#              #
#    Updated: 2018/12/13 17:54:29 by vrenaudi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = fractol

SRC_PATH = ./src

OBJ_PATH = ./obj

HEAD = -I include

LDFLAGS = -L libft

LDLIBS = -lft

SRC_NAME = main.c \
		   ft_mandelbrot.c \
		   ft_julia.c \
		   ft_loop.c \
		   ft_key.c \
		   ft_commands.c \
		   ft_commands2.c \
		   ft_event.c \
		   ft_burning_ship.c \
		   ft_bs_julia.c \
		   ft_put_infos.c \
		   ft_switch_colors.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

RM = rm -f

all: $(NAME)

$(NAME) : $(OBJ)
	Make -C libft
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $@ -lmlx -framework OpenGL -framework AppKit

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(HEAD) -o $@ -c $<

clean:
	Make clean -C ./libft
	$(RM) $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	make fclean -C ./libft
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE)

.PHONY: clean, re, fclean, all
