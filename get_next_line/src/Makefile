# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 18:05:31 by ecastong          #+#    #+#              #
#    Updated: 2023/06/08 16:16:07 by ecastong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBRARY := libget_next_line.a
.PHONY: all clean fclean re
# >------------------------------< compilation/archival
CC := gcc
CFLAGS := -Wall -Wextra -g

# >------------------------------< directories
SRC_DIR := ./
OBJ_DIR := ../.cache/

# >------------------------------< filesS))
SRCS := $(wildcard $(SRC_DIR)*.c)
OBJS := $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# >------------------------------< build lib
all: $(LIBRARY)

$(LIBRARY): $(LFT_OBJS) $(OBJS)
	ar rcs $@ $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# >------------------------------< cleaning
clean:
	rm -rf $(LFT_OBJS)

fclean:
	rm -rf $(OBJ_DIR) $(LIBRARY)

re: fclean all