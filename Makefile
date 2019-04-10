# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/09 20:57:32 by bboutoil          #+#    #+#              #
#    Updated: 2019/04/09 11:35:51 by apsaint-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


##### DEPENDENCIES #############################################################

LIBFT_DIR:= libft
LIBFT_HEADERS:=$(LIBFT_DIR)/includes
LIBFT_NAME:= $(LIBFT_DIR)/libft.a

##### PROJECT & ASSETS #########################################################

NAME:=minishell
NAME_DIR:= .
INC_DIR:= inc
SRC_DIR:= src
OBJ_DIR:= obj

HEADERS+= $(INC_DIR)/minishell.h

SRC+= $(SRC_DIR)/main.c
SRC+= $(SRC_DIR)/get_cmd.c
SRC+= $(SRC_DIR)/gestion_signal.c
SRC+= $(SRC_DIR)/gestion_env.c
SRC+= $(SRC_DIR)/builtin_echo.c
SRC+= $(SRC_DIR)/builtin_cd.c
SRC+= $(SRC_DIR)/builtin_setenv.c
SRC+= $(SRC_DIR)/builtin_env.c
SRC+= $(SRC_DIR)/execute_switch.c
SRC+= $(SRC_DIR)/utils.c
SRC+= $(SRC_DIR)/switch.c
SRC+= $(SRC_DIR)/utils_cd.c
SRC+= $(SRC_DIR)/utils_env.c
SRC+= $(SRC_DIR)/input_parsing.c
OBJ= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)


##### TOOLS ####################################################################

LINK = gcc
CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -Wextra
CFLAGS += -I $(INC_DIR)/ -I $(LIBFT_HEADERS)/
CLIBS += -L $(LIBFT_DIR)
MKDIR:= mkdir -p
MAKE:= make -C


################################################################################
################################################################################

.PHONY: all clean fclean re test debug configure
.SUFFIXES:
.SUFFIXES: .c .o

all : $(OBJ_DIR) $(LIBFT_NAME) $(NAME) $(HEADERS)

$(NAME): $(OBJ) $(HEADERS)
	$(LINK) $(CFLAGS) $(CLIBS) $(OBJ) -o $@ -lft

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(LIBFT_NAME): $(LIBFT_DIR)
	@make -C $^

$(OBJ_DIR):
	@$(MKDIR) $@

$(LIBFT_DIR):
	@$(MKDIR) $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
