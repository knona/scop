# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 13:02:16 by krambono          #+#    #+#              #
#    Updated: 2020/11/24 17:18:24 by krambono         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# Lib
NAME =	libft

# SOURCES
# FT_PRINTF
FT_PRINTF_FILES = buf.c ft_printf.c is.c params.c parse.c utilities.c utilities_buf.c versions.c versions2.c write_arg.c write_arg2.c write_arg_nb.c
FT_PRINTF_DIR 	= ft_printf/
FT_PRINTF 		= $(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF_FILES))

# GNL
GNL_FILES 		= get_next_line.c list.c 
GNL_DIR 		= gnl/
GNL 			= $(addprefix $(GNL_DIR), $(GNL_FILES))

# MEM
MEM_FILES 		= ft_bzero.c ft_memalloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memprint.c ft_memset.c
MEM_DIR 		= mem/
MEM 			= $(addprefix $(MEM_DIR), $(MEM_FILES))

# STRING
STRING_FILES	= ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strchr_i.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strncat.c ft_strnchr.c ft_strnchr_i.c ft_strncmp.c ft_strncpy.c ft_strndup.c ft_strnew.c ft_strnstr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c
STRING_DIR 		= string/
STRING 			= $(addprefix $(STRING_DIR), $(STRING_FILES))

# OTHER
OTHER_FILES 	= ft_max.c ft_min.c ft_options.c
OTHER_DIR 		= other/
OTHER 			= $(addprefix $(OTHER_DIR), $(OTHER_FILES))

# TOUTES LES SOURCES
SRCS_FILES 		= $(FT_PRINTF) $(GNL) $(MEM) $(STRING) $(OTHER)
SRCS_MAIN_DIR 	= src/
SRCS_DIRS 		= $(FT_PRINTF_DIR) $(GNL_DIR) $(MEM_DIR) $(STRING_DIR) $(OTHER_DIR)
SRCS 			= $(addprefix $(SRCS_MAIN_DIR), $(SRCS_FILES))

# HEADERS
HEADERS_FILES 	= libft.h ft_printf.h
HEADERS_DIR 	= ./include/
HEADERS 		= $(addprefix $(HEADERS_DIR), $(HEADERS_FILES))

# OBJETS
OBJS_MAIN_DIR 	= objs/
OBJS_DIRS 		= $(addprefix $(OBJS_MAIN_DIR), $(SRCS_DIRS))
OBJS_ALL_DIRS 	= $(OBJS_MAIN_DIR) $(OBJS_DIRS)
OBJS_FILES 		= $(SRCS_FILES:.c=.o)
OBJS 			= $(addprefix $(OBJS_MAIN_DIR), $(OBJS_FILES))

# COMPILATEUR
CC 				= clang
CFLAGS			= -Wall -Wextra -Werror -fPIC

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

$(NAME).a: $(OBJS_ALL_DIRS) $(SRCS) $(OBJS) $(HEADERS)
	@ar rc $(NAME).a $(OBJS)
	@ranlib $(NAME).a
	@printf "\033[2K\r$(NAME).a has been created  $(GREEN)[OK]$(DEFAULT)\n"

$(NAME).so: $(OBJS_ALL_DIRS) $(SRCS) $(OBJS) $(HEADERS)
	@$(CC) -shared $(OBJS) -o $(NAME).so
	@printf "\033[2K\r$(NAME).so has been created $(GREEN)[OK]$(DEFAULT)\n"

$(OBJS_MAIN_DIR)%.o: $(SRCS_MAIN_DIR)%.c $(HEADERS)
	@printf "\033[2K\r$(BLUE)>>Compiling $(DEFAULT)$<"
	@$(CC) -c $(CFLAGS) -I $(HEADERS_DIR) $< -o $@

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
