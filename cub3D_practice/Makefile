# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 04:11:59 by jihykim2          #+#    #+#              #
#    Updated: 2023/11/19 23:21:53 by jihykim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLIB		= -L$(MLX_DIR) -lmlx -Imlx -framework Cocoa -framework Metal -framework MetalKit -framework QuartzCore
# MLIB		= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
RM			= rm -f

# LIB_DIR		= ./libft/
MLX_DIR		= ./mlx/

PARSE_DIR	=
SRCS_PARSE	=
OBJS_PARSE	= $(addprefix $(PARSE_DIR), $(SRCS_PARSE:.c=.o))

EXEC_DIR	= ./
SRCS_EXEC	= ray_cating.c
OBJS_EXEC	= $(addprefix $(EXEC_DIR), $(SRCS_EXEC:.c=.o))

SRCS		= cub3d.c $(SRCS_PARSE) $(SRCS_EXEC) $(SRCS_BUILT) $(SRCS_UTILS)
OBJS		= cub3d.o $(OBJS_PARSE) $(OBJS_EXEC) $(OBJS_BUILT) $(OBJS_UTILS)

all		: $(NAME)

%.o		: %.c
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME)	: $(OBJS)
	@$(MAKE) -j 1 -C $(MLX_DIR) 2>/dev/null
	@echo $(YELLOW) "✭	[ mlx ]		Ready to use MiniLibX" $(RESET)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIB_DIR) -lft $(MLIB)
	@install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)
	@echo $(GREEN) "⚡︎	[ cub3D ]	Ready to run cub3D" $(RESET)

clean	:
	@$(MAKE) -C $(MLX_DIR) clean
	@echo $(YELLOW) "✭	[ mlx ]		Removed Object files" $(RESET)
	@$(RM) $(OBJS)
	@echo $(GREEN) "⚡︎	[ cub3D ]	Removed Object files" $(RESET)

fclean	:
	@$(MAKE) clean
	@echo $(YELLOW) "✭	[ mlx ]		Removed mlx" $(RESET)
	@$(RM) $(NAME)
	@echo $(GREEN) "⚡︎	[ cub3D ]	Removed cub3D" $(RESET)

re		:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY	: all clean fclean re

RESET	= "\x1b[0m"
GREY	= "\x1b[30m"
RED		= "\x1b[31m"
GREEN	= "\x1b[32m"
YELLOW	= "\x1b[33m"
BLUE	= "\x1b[34m"
PURPLE	= "\x1b[35m"
CYAN	= "\x1b[36m"
WHITE	= "\x1b[37m"
