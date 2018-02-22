# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbataini <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 19:11:14 by bbataini          #+#    #+#              #
#    Updated: 2018/02/22 15:49:30 by bbataini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = -I ./
CC = gcc
CFLAGS = -Werror -Wall -Wextra
OBJS_DIR = objs/
SRC = ft_isalnum.c ft_putchar.c ft_strchr.c ft_strlen.c ft_strnstr.c \
ft_toupper.c ft_isalpha.c ft_putnbr.c ft_strcmp.c ft_strncat.c ft_strrchr.c \
ft_isdigit.c ft_putstr.c ft_strcpy.c ft_strncmp.c ft_strstr.c \
ft_isprint.c ft_strcat.c ft_strlcat.c ft_strncpy.c ft_tolower.c \
ft_putendl.c ft_strclr.c ft_striter.c ft_strnew.c ft_strdel.c \
ft_strmap.c ft_strdup.c ft_striteri.c \
ft_isascii.c ft_atoi.c ft_memchr.c ft_memmove.c \
ft_bzero.c ft_memcmp.c ft_memset.c ft_memcpy.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_strsub.c ft_strjoin.c ft_strtrim.c \
ft_strequ.c ft_strnequ.c \
ft_strsplit.c ft_memccpy.c ft_itoa.c \
ft_memalloc.c ft_memdel.c ft_strmapi.c \
ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
ft_strrev.c ft_strupcase.c ft_strlowcase.c ft_strcapitalize.c ft_str_is_alpha.c \
ft_strnjoin.c

OBJ = ft_isalnum.o ft_putchar.o ft_strchr.o ft_strlen.o ft_strnstr.o \
ft_toupper.o ft_isalpha.o ft_putnbr.o ft_strcmp.o ft_strncat.o ft_strrchr.o \
ft_isdigit.o ft_putstr.o ft_strcpy.o ft_strncmp.o ft_strstr.o \
ft_isprint.o ft_strcat.o ft_strlcat.o ft_strncpy.o ft_tolower.o \
ft_putendl.o ft_strclr.o ft_striter.o ft_strnew.o ft_strdel.o \
ft_strmap.o ft_strdup.o ft_striteri.o \
ft_isascii.o ft_atoi.o ft_memchr.o ft_memmove.o \
ft_bzero.o ft_memcmp.o ft_memset.o ft_memcpy.o \
ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o \
ft_strsub.o ft_strjoin.o ft_strtrim.o \
ft_strequ.o ft_strnequ.o \
ft_strsplit.o ft_memccpy.o ft_itoa.o \
ft_memalloc.o ft_memdel.o ft_strmapi.o \
ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstmap.o \
ft_strrev.o ft_strupcase.o ft_strlowcase.o ft_strcapitalize.o ft_str_is_alpha.o \
ft_strnjoin.o \

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): $(SRC)
	gcc -c $(CFLAGS) $(HEADER) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
