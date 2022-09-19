# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 16:21:35 by jeykim            #+#    #+#              #
#    Updated: 2022/09/19 16:38:07 by jeykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
 
NAME = so_long
 
SRCS_DIR = ./
SRCS_NAME = error_manage.c image_mod.c map_manage.c move.c play_manage.c so_long.c
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_NAME))
OBJS = $(SRCS:.c=.o)
 
LIB_NAME = ft
LIB_DIR = ./libft
LIB = $(addprefix $(LIB_DIR)/, libft.a)
 
MLX_NAME = mlx
MLX_DIR = ./mlx
MLX = $(addprefix $(MLX_DIR)/, libmlx.a)
 
 
$(NAME)	: $(OBJS)
	$(MAKE) -C $(LIB_DIR) all
	$(MAKE) -C $(MLX_DIR) all
	$(CC) $(CFLAGS) -L$(LIB_DIR) -l$(LIB_NAME) -L$(MLX_DIR) -l$(MLX_NAME) \
           -framework OpenGL -framework AppKit $^ -o $@

all : $(NAME)
 
clean :
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJS)
 
fclean :
	$(MAKE) -C $(LIB_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(NAME) $(OBJS)
 
re : fclean all
 
bonus : all

.PHONY : all clean fclean re bonus
