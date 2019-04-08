.PHONY: clean fclean re
.SUFFIXES:
.SUFFIXES: .c .o

SHELL := /bin/sh 

INCDIR := includes

# BUILD OPTIONS
CC = gcc
LINK = gcc
AR = ar
ARFLAGS = rcvs
CFLAGS += -Wall -Wextra -Werror
CFLAGS += -I $(INCDIR)/

# Target
name = libft.a

# SOURCES
SRC += ft_atoi.c ft_bzero.c ft_isalnum ft_isalpha.c
SRC += ft_isascii.c ft_isdigit.c ft_isprint.c ft_lstadd.c
SRC += ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c
SRC += ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c
SRC += ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c
SRC += ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c
SRC += ft_putnbr_fd.c ft_putnbr.c ft_putstr.c ft_putstr_fd.c
SRC += ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c
SRC += ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c
SRC += ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c
SRC += ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c
SRC += ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c
SRC += ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c
SRC += ft_strsub.c ft_strrev.c ft_strtrim.c ft_tolower.c
SRC += ft_toupper.c ft_countwords.c get_next_line.c ft_strsplit_space.c
SRC += ft_sortwordtab.c

OBJ = $(SRC:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
		@$(AR) $(ARFLAGS) $@ $?

ft_%.o: ft_%.c
		@$(CC) $(CFLAGS) -o $@ -c $^

clean:
		@$(RM) $(OBJ)
		@echo "Objects from libft remove"

fclean:
		@$(RM) $(NAME)
		@echo "$(NAME) removed"

re: fclean $(NAME)
