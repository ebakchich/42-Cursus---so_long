# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 18:30:45 by ebakchic          #+#    #+#              #
#    Updated: 2023/01/12 23:47:14 by ebakchic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = mandatory/main.c mandatory/read_map.c mandatory/ft_checkmap.c mandatory/ft_error.c mandatory/ft_check_path.c mandatory/ft_creat_gm.c mandatory/ft_utils.c mandatory/ft_free.c
BSRCS    = bonus/main_bonus.c bonus/read_map_bonus.c bonus/ft_checkmap_bonus.c bonus/ft_error_bonus.c bonus/ft_check_path_bonus.c bonus/ft_creat_gm_bonus.c bonus/ft_utils_bonus.c bonus/ft_anim_c_bonus.c bonus/ft_free_bonus.c
NAME    = so_long
OBJS 	= ${SRCS:.c=.o}
BOBJS 	= ${BSRCS:.c=.o}
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
	@$(CC) $(MLX_FLAGS) -o ${NAME} ${AR} ${OBJS}

bonus: ${BOBJS}
	@$(MAKE) -C libft
	@$(CC) $(MLX_FLAGS) -o ${NAME} ${AR} ${BOBJS}

clean:
	@$(MAKEC) -C libft
	@${RM} ${OBJS}
	@${RM} ${BOBJS}

fclean: clean
	@$(MAKEF) -C libft
	@${RM} ${NAME}

re: fclean all
	@$(MAKER) -C libft

.PHONY: all clean fclean re
