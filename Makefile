# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 11:51:46 by krambono          #+#    #+#              #
#    Updated: 2020/11/27 11:22:49 by krambono         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# EXECUTABLE
NAME = scop

# SOURCES
SRCS_FILES_WILDCARD	= $(wildcard main/src/*.c)
SRCS_FILES			= $(SRCS_FILES_WILDCARD:main/src/%=%)
SRCS_MAIN_DIR		= main/src/
SRCS				= $(addprefix $(SRCS_MAIN_DIR), $(SRCS_FILES))

# OBJETS
OBJS_FILES		= $(SRCS_FILES:.c=.o)
OBJS_MAIN_DIR 	= main/obj/
OBJS 			= $(addprefix $(OBJS_MAIN_DIR), $(OBJS_FILES))

# HEADERS
HEADERS_FILES_WILDCARD	= $(wildcard main/include/*.h)
HEADERS_FILES 			= $(HEADERS_FILES_WILDCARD:main/include/%=%)
HEADERS_MAIN_DIR		= main/include/
HEADERS					= $(addprefix $(HEADERS_MAIN_DIR), $(HEADERS_FILES))

# LIBRARIES
GLFW_DIR = libs/glfw
GLAD_DIR = libs/glad
FT_DIR = libft
MGL_DIR = libmgl

# COMPILATEUR
CC		= clang
CFLAGS	= -Wall -Wextra -g3

# TEXT
RED = \033[31m
WHITE = \033[0;29m
YELLOW = \033[33m
PINK = \033[35m
GREEN = \033[32m
BLUE = \033[36m
DEFAULT = \033[0m

.PHONY: clean fclean ffclean re clean-glfw clean-glad clean-libft clean-mgl clean-libs $(FT_DIR)/libft.so $(MGL_DIR)/libmgl.so

# REGLES
all: $(FT_DIR)/libft.so $(NAME)

$(OBJS_MAIN_DIR):
	@mkdir -p $@

$(NAME): $(GLFW_DIR) $(GLAD_DIR) $(GLAD_DIR)/src/glad.o $(OBJS_MAIN_DIR) $(OBJS)
	@printf "\033[2K\r$(BLUE)>>Linking...$(DEFAULT)"
	@$(CC)	-o $@ $(OBJS)\
			$(GLAD_DIR)/src/glad.o\
			-L$(GLFW_DIR)/lib -lglfw\
			-L$(FT_DIR) -lft\
			-L$(MGL_DIR) -lmgl\
			-lGL -lX11 -lpthread -lXrandr -lXi -ldl -lm
	@printf "\033[2K\r$(NAME) has been created $(GREEN)[OK]$(DEFAULT)\n"

$(OBJS_MAIN_DIR)%.o: $(SRCS_MAIN_DIR)%.c $(MGL_DIR)/libmgl.so $(HEADERS)
	@printf "\033[2K\r$(BLUE)>>Compiling $(DEFAULT)$<"
	@$(CC) $(CFLAGS)\
		-I $(GLFW_DIR)/include\
		-I $(GLAD_DIR)/include\
		-I $(FT_DIR)/include\
		-I $(MGL_DIR)/include\
		-I $(HEADERS_MAIN_DIR)\
		-o $@ -c $<

$(GLAD_DIR)/src/glad.o: $(GLAD_DIR)/src/glad.c
	@printf "\033[2K\r$(BLUE)>>Compiling $(DEFAULT)$<"
	@clang -I $(GLAD_DIR)/include -o $@ -c $<

$(GLFW_DIR):
	@echo "$(BLUE)Installing glfw...$(DEFAULT)"
	@./scripts/install-glfw.bash

$(GLAD_DIR):
	@echo "$(BLUE)Installing glad...$(DEFAULT)"
	@./scripts/install-glad.bash

$(FT_DIR)/libft.so:
	@make -sC $(FT_DIR)

$(MGL_DIR)/libmgl.so:
	@make -sC $(MGL_DIR)

clean:
	@echo "$(YELLOW)$(NAME):\t$(RED)rm $(YELLOW)objects\t  $(GREEN)[OK]$(DEFAULT)"
	@rm -rf $(OBJS_MAIN_DIR)

fclean:	clean
	@echo "$(YELLOW)$(NAME):\t$(RED)rm $(YELLOW)binaries\t  $(GREEN)[OK]$(DEFAULT)"
	@rm -f $(NAME)

clean-glfw:
	@echo "$(RED)Removing glfw...$(DEFAULT)"
	@rm -rf $(GLFW_DIR)

clean-glad:
	@echo "$(RED)Removing glad...$(DEFAULT)"
	@rm -rf $(GLAD_DIR)

clean-libft:
	@echo "$(RED)Removing libft...$(DEFAULT)"
	@make -sC $(FT_DIR) fclean

clean-libmgl:
	@echo "$(RED)Removing mgl...$(DEFAULT)"
	@make -sC $(MGL_DIR) fclean

clean-libs: clean-glfw clean-glad clean-libft clean-mgl
	@rm -rf libs

ffclean: clean-libs fclean

re: fclean all
