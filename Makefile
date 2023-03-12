# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 16:57:50 by kchaouki          #+#    #+#              #
#    Updated: 2023/03/12 17:05:58 by kchaouki         ###   ########.fr        #
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

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

FLAGS = -Wall -Wextra -Werror

CCe = cc

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft && make clean -C libft 

%.o : %.c
	$(CCe) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) fdf.h
	$(CCe) $(FLAGS) $(MLXFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(NAME_B)

$(NAME_B) : $(OBJS_B) fdf.h
	$(CCe) $(FLAGS) $(MLXFLAGS) $(OBJS_B) $(LIBFT) -o $(NAME_B)

clean:
	rm -rf $(OBJS) $(OBJS_B)

fclean: clean
	rm -rf $(NAME) $(NAME_B) $(LIBFT)

re : fclean all

.PHONY: all clean fclean re bonus