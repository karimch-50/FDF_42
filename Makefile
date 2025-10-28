# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 16:57:50 by kchaouki          #+#    #+#              #
#    Updated: 2025/10/28 19:38:46 by kchaouki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
NAME_B = fdf_bonus

LIBFT = libft/libft.a

LOAD_MAP = load_map/get_next_line_utils.c \
		   load_map/get_next_line.c \
	   	   load_map/load_map_utils.c \
	   	   load_map/load_map.c

SRCS = fdf.c \
	   $(LOAD_MAP) \
	   responsive.c \
	   get_color.c \
	   draw_line.c \
	   draw_map.c \
	   print_error.c \
	   ft_free.c \

SRCS_B = bonus/fdf_bonus.c \
		 $(LOAD_MAP) \
	     responsive.c \
		 bonus/draw_manu.c \
		 controle_hooks_utils.c \
		 control_hooks.c \
	     get_color.c \
	     draw_line.c \
	     draw_map.c \
	     print_error.c \
	     ft_free.c \

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

MLXFLAGS = -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit

FLAGS = -Wall -Wextra -Werror -Iminilibx_macos

CCe = cc

all: $(LIBFT) minilibx_macos/libmlx.a $(NAME)

$(LIBFT):
	make -C libft && make clean -C libft 

minilibx_macos/libmlx.a:
	make -C minilibx_macos

%.o : %.c
	$(CCe) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) fdf.h
	$(CCe) $(FLAGS) $(MLXFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(NAME_B)

$(NAME_B) : $(OBJS_B) fdf.h
	$(CCe) $(FLAGS) $(MLXFLAGS) $(OBJS_B) $(LIBFT) -o $(NAME_B)

clean:
	rm -rf $(OBJS) $(OBJS_B)
	make clean -C minilibx_macos

fclean: clean
	rm -rf $(NAME) $(NAME_B) $(LIBFT)
	make clean -C minilibx_macos

re : fclean all

.PHONY: all clean fclean re bonus