# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 17:09:09 by kchaouki          #+#    #+#              #
#    Updated: 2023/02/09 13:00:52 by kchaouki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -I.

CCe = cc $(FLAGS)

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c \
	   ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	   ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	   ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
	   ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	   ft_tolower.c ft_toupper.c \
	   ft_substr.c ft_strjoin.c ft_strtrim.c \
	   ft_split.c ft_itoa.c \
	   ft_strmapi.c ft_striteri.c \
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
	  
SRCS_B = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		 ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		 ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

$(NAME): $(OBJS) libft.h
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	$(CCe) -c $< -o $@

all: $(NAME)

bonus: $(NAME) $(OBJS_B)
	ar rcs $(NAME) $(OBJS_B)

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus