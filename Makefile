# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgras-ca <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/08 15:58:04 by fgras-ca          #+#    #+#              #
#    Updated: 2023/09/09 18:35:45 by ladebeze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LOGO = @echo " __,     ____, ____,  ____,  ____   ____,  ___,   ____,";\
	echo "(-|     (-/_| (-|  \ (-|_,  (-|__) (-|_,  (- /   (-|_,";\
        echo " _|__,  _/  |, _|__/  _|__,  _|__)  _|__,  _/__,  _|__,";\
        echo "(      (      (      (      (      (      (      ("

DEF_COLOR		= \033[0m
GRAY			= \033[0;90m
RED				= \033[0;91m
GREEN			= \033[0;92m
YELLOW			= \033[0;93m
BLUE			= \033[0;94m
MAGENTA			= \033[0;95m
CYAN			= \033[0;96m
WHITE			= \033[0;97m
ORANGE			= \033[38;5;214m

NAME = fractol
NAME_BONUS = fractol_b
LIBFT = libft.a
MINILIB = libmlx.a

SRC = 	fractol.c \
	check_arguments.c \
	fractol_utils.c \
	hook.c \
	julia.c \
	mandelbrot.c \
	color.c \

SRC_BONUS = fractol_bonus.c \
	    check_arguments_bonus.c \
	    fractol_utils_bonus.c \
	    hook_bonus.c \
	    julia_bonus.c \
	    mandelbrot_bonus.c \
	    burning_bonus.c \
	    color_bonus.c \

SRC_DIR_LIBFT = libft/
SRC_DIR_MINILIB = minilibx-linux/
SRC_LIBFT = $(addprefix $(SRC_DIR_LIBFT), $(LIBFT))
SRC_MINILIB = $(addprefix $(SRC_DIR_MINILIB), $(MINILIB))

OBJS = ${SRC:.c=.o}
OBJSB = ${SRC_BONUS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -lX11 -lXext -lXrandr -lm
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "$(RED)Loading minilibX... $(DEF_COLOR)"
	@make -C minilibx-linux
	@echo "$(GREEN)minilibX...Done. $(DEF_COLOR)"
	@echo "$(RED)Loading Libft... $(DEF_COLOR)"
	@make -C libft
	@echo "$(GREEN)Libft...Done. $(DEF_COLOR)"
	@echo "$(RED)Compilation fractol... $(DEF_COLOR)"
	$(CC) $(CFLAGS) $(OBJS) $(SRC_MINILIB) $(SRC_LIBFT) $(MLX) -o $(NAME)
	@echo "$(GREEN)Compilation complete. $(ORANGE)Type "./fractol" for the menu!!$(DEF_COLOR)"
	$(LOGO)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJSB)
	@echo "$(RED)Loading minilibX... $(DEF_COLOR)"
	@make -C minilibx-linux
	@echo "$(GREEN)minilibX...Done. $(DEF_COLOR)"
	@echo "$(RED)Loading Libft... $(DEF_COLOR)"
	@make -C libft
	@echo "$(GREEN)Libft...Done. $(DEF_COLOR)"
	@echo "$(RED)Compilation fractol with bonus... $(DEF_COLOR)"
	$(CC) $(CFLAGS) $(OBJSB) $(SRC_MINILIB) $(SRC_LIBFT) $(MLX) -o $(NAME_BONUS)
	@echo "$(GREEN)Compilation complete. $(ORANGE)Type "./fractol_b" for the menu!!$(DEF_COLOR)"
	$(LOGO)

clean :
	@echo "$(RED)Cleaning Libft... $(DEF_COLOR)"
	@make -C libft clean 
	@echo "$(GREEN)Libft cleaned!! $(DEF_COLOR)"
	@echo "$(RED)Cleaning MinilibX... $(DEF_COLOR)"
	@make -C minilibx-linux clean
	@echo "$(GREEN)MinilibX cleaned!! $(DEF_COLOR)"
	@echo "$(RED)Deleating files objects... $(DEF_COLOR)"
	$(RM) $(OBJS) $(OBJSB)
	@echo "$(GREEN)files deleted!! $(DEF_COLOR)"
	$(LOGO)

fclean : clean
	@echo "$(RED)fclean Libft... $(DEF_COLOR)"
	@make -C ./libft fclean
	@echo "$(GREEN)Libft cleaned!! $(DEF_COLOR)"
	@echo "$(RED)Delete program name... $(DEF_COLOR)"
	$(RM) $(NAME) $(NAME_BONUS)
	@echo "$(GREEN)File program deleted!! $(DEF_COLOR)"
	$(LOGO)

re : fclean all

rebonus : fclean bonus

.PHONY : all bonus clean fclean re rebonus
