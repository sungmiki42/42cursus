CC = cc
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
M_SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
		 ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
		 ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c\
		 ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c\
		 ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c\
		 ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
		 ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
B_SRCS = ft_first_bonus.c ft_second_bonus.c
M_OBJS = $(M_SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)
FLAG_FILES = basic_create bonus_create

all: $(NAME)

$(NAME): basic_create

bonus: bonus_create

basic_create : $(M_OBJS)
	rm -f bonus_create
	ar rc $(NAME) $^
	touch $@

bonus_create: $(M_OBJS) $(B_OBJS)
	rm -f basic_create
	ar rc $(NAME) $^
	touch $@

clean:
	rm -f $(M_OBJS) $(B_OBJS) $(FLAG_FILES)

fclean: clean
	rm -f $(NAME) $(FLAG_FILES)

re: fclean all

.PHONY: all re clean fclean bonus
