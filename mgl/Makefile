# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 13:02:16 by krambono          #+#    #+#              #
#    Updated: 2020/11/25 19:45:08 by krambono         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# Lib
NAME =	libmgl

# SOURCES
SRCS_FILES_WILDCARD	= $(wildcard src/*.c)
SRCS_FILES			= $(SRCS_FILES_WILDCARD:src/%=%)
SRCS_MAIN_DIR 	= src/
SRCS 			= $(addprefix $(SRCS_MAIN_DIR), $(SRCS_FILES))

# HEADERS
HEADERS_FILES 	= mgl.h
HEADERS_DIR 	= ./include/
HEADERS 		= $(addprefix $(HEADERS_DIR), $(HEADERS_FILES))

# OBJETS
OBJS_MAIN_DIR 	= objs/
OBJS_DIRS 		= $(addprefix $(OBJS_MAIN_DIR), $(SRCS_DIRS))
OBJS_ALL_DIRS 	= $(OBJS_MAIN_DIR) $(OBJS_DIRS)
OBJS_FILES 		= $(SRCS_FILES:.c=.o)
OBJS 			= $(addprefix $(OBJS_MAIN_DIR), $(OBJS_FILES))

# LIBRARIES
FT_DIR = ../libft

# COMPILATEUR
CC 				= clang
CFLAGS			= -Wall -Wextra -Werror -fPIC -g3

# TEXT
RED = \033[31m
WHITE = \033[0;29m
YELLOW = \033[33m
PINK = \033[35m
GREEN = \033[32m
BLUE = \033[36m
DEFAULT = \033[0m

.PHONY: all directories clean clean_exe fclean re

# REGLES
all: $(NAME).a $(NAME).so

$(OBJS_ALL_DIRS):
	@mkdir -p $@

$(NAME).a: $(OBJS_ALL_DIRS) $(FT_DIR)/libft.so $(OBJS) $(HEADERS)
	@ar rc $(NAME).a $(OBJS)
	@ranlib $(NAME).a
	@printf "\033[2K\r$(NAME).a has been created  $(GREEN)[OK]$(DEFAULT)\n"

$(NAME).so: $(OBJS_ALL_DIRS) $(FT_DIR)/libft.so $(OBJS) $(HEADERS)
	@$(CC) -shared $(OBJS) -o $(NAME).so -L$(FT_DIR) -lft
	@printf "\033[2K\r$(NAME).so has been created $(GREEN)[OK]$(DEFAULT)\n"

$(OBJS_MAIN_DIR)%.o: $(SRCS_MAIN_DIR)%.c $(HEADERS)
	@printf "\033[2K\r$(BLUE)>>Compiling $(DEFAULT)$<"
	@$(CC) -c $(CFLAGS) -I $(FT_DIR)/include -I $(HEADERS_DIR) $< -o $@

$(FT_DIR)/libft.so:
	@make -sC $(FT_DIR)

clean:
	@rm -rf $(OBJS_MAIN_DIR)
	@echo "$(YELLOW)$(NAME):\t$(RED)rm $(YELLOW)objects\t  $(GREEN)[OK]$(DEFAULT)"

clean_exe:
	@rm -f $(NAME).a
	@rm -f $(NAME).so
	@echo "$(YELLOW)$(NAME):\t$(RED)rm $(YELLOW)$(NAME).a\t  $(GREEN)[OK]$(DEFAULT)"
	@echo "$(YELLOW)$(NAME):\t$(RED)rm $(YELLOW)$(NAME).so\t  $(GREEN)[OK]$(DEFAULT)"

fclean: clean clean_exe

re: fclean all
