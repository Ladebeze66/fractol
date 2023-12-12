# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgras-ca <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 12:19:21 by fgras-ca          #+#    #+#              #
#    Updated: 2023/02/24 10:58:49 by fgras-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES =	ft_atoi.c \
		ft_isalpha.c \
		ft_memchr.c \
		ft_memset.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_toupper.c \
		ft_bzero.c \
		ft_isascii.c \
		ft_memcmp.c \
		ft_strchr.c \
		ft_strlcpy.c \
		ft_strrchr.c \
		ft_calloc.c \
		ft_isdigit.c \
		ft_memcpy.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_substr.c \
		ft_isalnum.c \
		ft_isprint.c \
		ft_memmove.c \
		ft_strjoin.c \
		ft_strncmp.c \
		ft_tolower.c\
		ft_strtrim.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_split.c \
		ft_itoa.c \

SRCBONUS =	ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstiter.c \
		ft_lstmap.c \

OBJECTS = $(SOURCES:.c=.o)

BONUS_OBJ = $(SRCBONUS:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

all:	$(NAME)

$(NAME):	$(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

bonus:	$(OBJECTS) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJECTS) $(BONUS_OBJ)

main.o:
	gcc -c main.c

ccmainlib:
	$(CC) $(CFLAGS) main.c -L -lft

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all  
