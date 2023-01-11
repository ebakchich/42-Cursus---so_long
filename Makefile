# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 18:30:45 by ebakchic          #+#    #+#              #
#    Updated: 2023/01/11 02:41:52 by ebakchic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = main.c read_map.c ft_checkmap.c ft_error.c ft_check_path.c ft_creat_gm.c ft_utils.c ft_anim_c.c
NAME    = so_long
OBJS 	= ${SRCS:.c=.o}
AR		= libft/libft.a
CC		= cc
GFLAGS  = -Wall -Wextra -Werror -
MLX_FLAGS    = -lmlx -framework OpenGL -framework Appkit
MAKEC	= make clean
MAKEF	= make fclean
MAKER	= make re

all: $(NAME)

$(NAME): ${OBJS}
	@$(MAKE) -C libft
	@$(CC) $(CFLAGS) -c $(SRCS)
	@$(CC) $(MLX_FLAGS) -o ${NAME} ${AR} ${OBJS}

clean:
	@$(MAKEC) -C libft
	@${RM} ${OBJS}

fclean: clean
	@$(MAKEF) -C libft
	@${RM} ${NAME}

re: fclean all
	@$(MAKER) -C libft

.PHONY: all clean fclean re
