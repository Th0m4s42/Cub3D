SRCS = \
          ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_strlen.c \
          ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strncmp.c \
          ft_strnstr.c ft_strrchr.c ft_substr.c ft_tolower.c ft_toupper.c \
          ft_isprint.c ft_memset.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
          ft_memmove.c ft_atoi.c ft_bzero.c ft_calloc.c ft_strtrim.c \
          ft_split.c ft_itoa.c ft_strjoin.c ft_strmapi.c ft_striteri.c \
          ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		  ft_printf/ft_printf.c ft_printf/ft_putchar_fd.c ft_printf/ft_putnbr_fd.c \
		  ft_printf/ft_unsigned_putnbr_fd.c ft_printf/ft_putnbr_base_fd.c ft_printf/ft_putstr_fd.c \
		  ft_printf/ft_pointeur_base_fd.c \
		  GNL/get_next_line.c \

BONUS_SRCS = \
           ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	   ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
	   ft_lstmap.c

HEADERS = /libft.h
OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}
NAME    = libft.a
CC    = gcc
CFLAGS    = -Wall -Wextra -Werror
RM    = rm -rf

all: ${NAME}

.c.o :
	@${CC} -c ${CFLAGS} -I ${HEADERS} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	@ar rcs ${NAME} ${OBJS}
	@ranlib ${NAME}

bonus: ${OBJS} ${BONUS_OBJS}
	@ar rcs ${NAME} ${OBJS} ${BONUS_OBJS}

clean:
	@${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	@${RM} ${NAME}

re : fclean all

.PHONY: all bonus clean fclean re
