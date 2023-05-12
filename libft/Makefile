# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 18:05:31 by ecastong          #+#    #+#              #
#    Updated: 2023/05/12 11:58:05 by ecastong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:= libft.a
# >------------------------------< source files
LIBFT_SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

LIBFT_BONUS_SRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c\
ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

# >------------------------------< object files
LIBFT_OBJS			= $(addprefix $(CACHE), $(LIBFT_SRCS:.c=.o))
LIBFT_BONUS_OBJS	= $(addprefix $(CACHE), $(LIBFT_BONUS_SRCS:.c=.o))

# >------------------------------< directories
CACHE				:= ../.cache/

# >------------------------------< compilation/archival
CC					:= gcc
CFLAGS				:= -Wall -Wextra -Werror
LIBC				:= ar -rcs

all: $(NAME)
$(NAME): $(LIBFT_OBJS)
	$(LIBC) $(NAME) $(LIBFT_OBJS)
bonus: $(LIBFT_BONUS_OBJS)
	$(LIBC) $(NAME) $(LIBFT_BONUS_OBJS)
$(CACHE):
	mkdir -p $(CACHE)
$(CACHE)%.o: %.c | $(CACHE)
	$(CC) $(CFLAGS) -c $< -o $@
	$(LIBC) $(NAME) $@

# >------------------------------< clean directories
REMOVE				:= rm -f
clean:
	$(REMOVE) $(LIBFT_OBJS) $(LIBFT_BONUS_OBJS)
	$(REMOVE) -r $(CACHE)*
fclean: clean
	$(REMOVE) $(NAME)
re: fclean all
rebonus: fclean bonus
reall: fclean all bonus

# >------------------------------< protect makefile
.PHONY: all bonus clean fclean re rebonus reall