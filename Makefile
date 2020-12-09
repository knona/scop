# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 11:51:46 by krambono          #+#    #+#              #
#    Updated: 2020/12/09 09:46:06 by krambono         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# EXECUTABLE
NAME = scop

# SOURCES
SRCS_FILES			= error.c events_2.c events.c globals.c object.c parse_2.c parse.c program.c program_uniform.c render_loop.c scop.c shader.c texture.c utils.c
SRCS_MAIN_DIR		= main/src/
SRCS				= $(addprefix $(SRCS_MAIN_DIR), $(SRCS_FILES))

# OBJETS
OBJS_FILES		= $(SRCS_FILES:.c=.o)
OBJS_MAIN_DIR 	= main/obj/
OBJS 			= $(addprefix $(OBJS_MAIN_DIR), $(OBJS_FILES))

# HEADERS
HEADERS_FILES 			= scop.h structs.h
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

.PHONY: clean fclean ffclean re clean-glfw clean-glad clean-libft clean-libmgl clean-libs force

# REGLES
all: $(NAME)

$(OBJS_MAIN_DIR):
	@mkdir -p $@

$(NAME): $(GLFW_DIR) $(GLAD_DIR) $(GLAD_DIR)/src/glad.o $(OBJS_MAIN_DIR) $(OBJS)
	@printf "\033[2K\r$(BLUE)>>Linking...$(DEFAULT) "
	@$(CC)	-o $@ $(OBJS)\
			$(GLAD_DIR)/src/glad.o\
			-L$(GLFW_DIR)/lib -lglfw3\
			-L$(FT_DIR) -lft\
			-L$(MGL_DIR) -lmgl\
			-framework Cocoa -framework OpenGL -framework IOKit -ldl -lm
	@printf "\033[2K\r$(NAME) has been created $(GREEN)[OK]$(DEFAULT)\n"

$(OBJS_MAIN_DIR)%.o: $(SRCS_MAIN_DIR)%.c $(FT_DIR)/libft.a $(MGL_DIR)/libmgl.a $(HEADERS)
	@printf "\033[2K\r$(BLUE)>>Compiling $(DEFAULT)$< "
	@$(CC) $(CFLAGS)\
		-I $(GLFW_DIR)/include\
		-I $(GLAD_DIR)/include\
		-I $(FT_DIR)/include\
		-I $(MGL_DIR)/include\
		-I $(HEADERS_MAIN_DIR)\
		-o $@ -c $<

$(GLAD_DIR)/src/glad.o: $(GLAD_DIR)/src/glad.c
	@printf "\033[2K\r$(BLUE)>>Compiling $(DEFAULT)$< "
	@clang -I $(GLAD_DIR)/include -o $@ -c $<

$(GLFW_DIR):
	@echo "$(BLUE)Installing glfw...$(DEFAULT)"
	@./scripts/install-glfw.bash

$(GLAD_DIR):
	@echo "$(BLUE)Installing glad...$(DEFAULT)"
	@./scripts/install-glad.bash

$(FT_DIR)/libft.a: $(shell cd $(FT_DIR) && make -q || echo force)
	@make -sC $(FT_DIR)

$(MGL_DIR)/libmgl.a: $(shell cd $(MGL_DIR) && make -q || echo force)
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

clean-libs: clean-glfw clean-glad clean-libft clean-libmgl
	@rm -rf libs

ffclean: clean-libs fclean

re: fclean all
