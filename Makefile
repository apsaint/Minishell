# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/09 20:57:32 by bboutoil          #+#    #+#              #
#    Updated: 2019/03/11 09:09:34 by apsaint-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


##### DEPENDENCIES #############################################################

LIB_DIR:= libft
LIBFT_DIR:= $(LIB_DIR)/libft
LIBFT_HEADERS:=$(LIBFT_DIR)/includes
LIBFT_NAME:= $(LIBFT_DIR)/libft.a

##### PROJECT & ASSETS #########################################################

NAME:=minishell
NAME_DIR:= .
INC_DIR:= inc
SRC_DIR:= src
OBJ_DIR:= obj

HEADERS+= $(INC_DIR)/minishell.h

SRC+= $(SRC_DIR)/param.c
SRC+= $(SRC_DIR)/path_utils.c
OBJ= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)


##### TOOLS ####################################################################

LINK = clang
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

$(LIB_DIR):
	@$(MKDIR) $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
