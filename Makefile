# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 18:30:45 by ebakchic          #+#    #+#              #
#    Updated: 2023/01/17 18:12:08 by ebakchic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = mandatory/main.c mandatory/read_map.c mandatory/ft_checkmap.c mandatory/ft_error.c mandatory/ft_check_path.c mandatory/ft_creat_gm.c mandatory/ft_utils.c mandatory/ft_free.c
LBFT	= libft/ft_isalpha.c libft/ft_isprint.c libft/ft_memmove.c libft/ft_strlcat.c libft/ft_strncmp.c libft/ft_toupper.c libft/ft_bzero.c libft/ft_isascii.c libft/ft_memchr.c  libft/ft_memset.c  libft/ft_strlcpy.c libft/ft_strrchr.c libft/ft_isalnum.c libft/ft_isdigit.c libft/ft_memcpy.c  libft/ft_strchr.c  libft/ft_strlen.c  libft/ft_tolower.c libft/ft_memcmp.c libft/ft_strnstr.c libft/ft_atoi.c libft/ft_calloc.c libft/ft_strdup.c libft/ft_substr.c libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c  libft/ft_strmapi.c libft/ft_putchar_fd.c libft/ft_putnbr_fd.c libft/ft_putendl_fd.c libft/ft_putstr_fd.c libft/ft_itoa.c libft/ft_striteri.c libft/ft_putstr.c
BSRCS    = bonus/main_bonus.c bonus/read_map_bonus.c bonus/ft_checkmap_bonus.c bonus/ft_error_bonus.c bonus/ft_check_path_bonus.c bonus/ft_creat_gm_bonus.c bonus/ft_utils_bonus.c bonus/ft_anim_c_bonus.c bonus/ft_free_bonus.c
NAME    = so_long
OBJS 	= ${SRCS:.c=.o}
BOBJS 	= ${BSRCS:.c=.o}
CC		= cc
GFLAGS  = -Wall -Wextra -Werror
MLX_FLAGS    = -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): ${OBJS} 
	@$(CC) $(MLX_FLAGS) -o ${NAME} ${LBFT} ${OBJS}

bonus: ${BOBJS}
	@$(CC) $(MLX_FLAGS) -o ${NAME} ${LBFT} ${BOBJS}

clean:
	@${RM} ${OBJS}
	@${RM} ${BOBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
