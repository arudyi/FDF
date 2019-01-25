# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arudyi <arudyi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/19 15:06:37 by arudyi            #+#    #+#              #
#    Updated: 2019/01/21 13:57:45 by arudyi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INCLUDE_DIR = ./include/
LIB_DIR = ./lib/
SRC = brezen.c check_key.c check_key1.c check_mouse_button.c coordinates.c draw_and_prepare.c free_programm.c main.c validation.c
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR := $(LIB_DIR)libft/
LIBFT_INC := $(LIBFT_DIR)includes/
LIBFT_FLAGS := -lft -L $(LIBFT_DIR)
CC_FLAGS = -Wall -Werror -Wextra
LINK_FLAGS := $(LIBFT_FLAGS)
HEADER_FLAGS := -I $(INCLUDE_DIR) -I $(LIBFT_INC) 
CC := gcc
FRAMEWORK = -lmlx -framework OpenGl -framework Appkit

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(FRAMEWORK) $(LINK_FLAGS)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)	

$(OBJ_DIR)%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@ $(HEADER_FLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)
fclean:	clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

vpath %.c $(SRC_DIR)
