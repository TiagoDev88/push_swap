# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/03 10:51:27 by tfilipe-          #+#    #+#              #
#    Updated: 2025/06/05 16:16:57 by tfilipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

CC = cc
CFLAGS =   -I includes -I libft

LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

SRC_DIR = src
SRCS = src/main_tester.c src/init_stack.c src/validate_args.c src/utils_stack.c \
		src/oper_swap.c src/oper_push.c src/oper_reverse.c src/oper_rotate.c \
		src/push_swap.c

SRC_DIR_BONUS = src_bonus
SRCS_BONUS = 

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

RM = rm -f

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "✅  $(NAME) Compiled successfully!"

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)
	@echo "clean: object files removed"

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "fclean: executable removed"

bonus: $(LIBFT) $(NAME_BONUS)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(SRC_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)
	@echo "✅  $(NAME_BONUS) Compiled successfully with bonus!"

re: fclean all

.PHONY: all clean fclean re