# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/02 13:56:52 by esnowpea          #+#    #+#              #
#    Updated: 2020/08/07 16:57:28 by esnowpea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = filler
NAME_EXEC = esnowpea.filler

CC = gcc
FLAGS = -Wall -Werror -Wextra -O2
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

INCLUDES = -I$(HEADERS_DIR) -I$(LIBFT_HEADERS)

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./Libft/
LIBFT_HEADERS = $(LIBFT_DIR)inc/

HEADERS_LIST = filler.h
HEADERS_DIR = ./inc/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SRC_LIST =	main.c \
			parcing.c \
			clear_malloc.c \
			init.c \
			find_place_piece.c
SRC_DIR = ./src/
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR = ./obj/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ	= $(addprefix $(OBJ_DIR), $(OBJ_LIST))

# COLORS

GRN = \033[0;32m
RED = \033[0;31m
YEL = \033[1;33m
END = \033[0m

.PHONY: all clean fclean re

all: $(NAME_EXEC)

$(NAME_EXEC): $(LIBFT) $(OBJ_DIR) $(OBJ)
	@$(CC) $(FLAGS) $(LIBFT_FLAGS) $(INCLUDES) $(OBJ) -o $(NAME_EXEC)
	@echo "\n$(NAME): $(GRN)*.o files created$(END)"
	@echo "$(NAME): $(GRN)$(NAME) created$(END)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(NAME): $(GRN)$(OBJ_DIR) created$(END)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GRN).$(END)\c"

$(LIBFT):
	@echo "$(NAME): $(GRN)Creating $(LIBFT)...$(END)"
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(NAME): $(RED)$(OBJ_DIR) deleted$(END)"
	@echo "$(NAME): $(RED)*.o files deleted$(END)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME_EXEC)
	@echo "$(NAME): $(RED)$(NAME_EXEC) deleted$(END)"

re: fclean all
