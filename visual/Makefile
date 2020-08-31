# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/02 13:56:52 by esnowpea          #+#    #+#              #
#    Updated: 2020/08/28 17:56:51 by esnowpea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Visual_Filler
NAME_EXEC = vs
TABS = \t

CC = gcc
FLAGS = -O2 -Wall -Werror -Wextra
LIB_FLAGS = -L$(LIBFT_DIR) -lft -L$(LIBVISUAL_DIR) -lvisual -L$(LIBMLX_DIR) -lmlx -framework OpenGL -framework AppKit

INCLUDES = -I$(HEADERS_DIR) -I$(LIBFT_HEADERS) -I$(LIBVISUAL_HEADERS) -I$(LIBMLX_HEADERS)

LIBFT = Lib_FT
LIBFT_EXEC = $(LIBFT_DIR)libft.a
LIBFT_DIR = ../lib/Libft/
LIBFT_HEADERS = $(LIBFT_DIR)inc/

LIBMLX = Lib_MLX
LIBMLX_EXEC = $(LIBMLX_DIR)libmlx.a
LIBMLX_DIR = $(LIBVISUAL_DIR)minilibx_macos/
LIBMLX_HEADERS = $(LIBMLX_DIR)

LIBVISUAL = Lib_Visual
LIBVISUAL_EXEC = $(LIBVISUAL_DIR)libvisual.a
LIBVISUAL_DIR = ../lib/LibVisual/
LIBVISUAL_HEADERS = $(LIBVISUAL_DIR)inc/

HEADERS_LIST = $(NAME).h
HEADERS_DIR = ./inc/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SRC_DIR = src/
SRC_LIST =	visual.c \
			parcing.c \
			print_map.c \
			status_bar.c \
			event_handler.c
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR = obj/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ	= $(addprefix $(OBJ_DIR), $(OBJ_LIST))

# COLORS

GRN = \033[0;32m
RED = \033[0;31m
YEL = \033[1;33m
END = \033[0m

.PHONY: all clean fclean re

all: $(NAME_EXEC)

$(NAME_EXEC): $(LIBFT_EXEC) $(LIBVISUAL_EXEC) $(OBJ_DIR) $(OBJ)
	@$(CC) $(FLAGS) $(LIB_FLAGS) $(INCLUDES) $(OBJ) -o ../$(NAME_EXEC)
	@echo "\n$(NAME):$(TABS)$(GRN)*.o files created$(END)"
	@echo "$(NAME):$(TABS)$(GRN)$(NAME_EXEC) created$(END)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(NAME):$(TABS)$(GRN)$(OBJ_DIR) created$(END)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GRN).$(END)\c"

$(LIBFT_EXEC):
	@echo "$(NAME):$(TABS)$(GRN)Creating $(LIBFT)...$(END)"
	@$(MAKE) -C $(LIBFT_DIR)

$(LIBVISUAL_EXEC):
	@echo "$(NAME):$(TABS)$(GRN)Creating $(LIBVISUAL)...$(END)"
	@$(MAKE) -C $(LIBVISUAL_DIR)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(LIBVISUAL_DIR) clean
	@rm -rf $(OBJ_DIR)
ifneq ($(strip $(wildcard $(OBJ))),)
	@echo "$(NAME):$(TABS)$(RED)*.o files deleted$(END)"
	@echo "$(NAME):$(TABS)$(RED)$(OBJ_DIR) deleted$(END)"
endif

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(LIBVISUAL_DIR) fclean
	@rm -f ../$(NAME_EXEC)
ifneq ($(strip $(wildcard $(NAME_EXEC))),)
	@echo "$(NAME):$(TABS)$(RED)$(NAME_EXEC) deleted$(END)"
endif

re: fclean all
