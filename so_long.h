/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:40:17 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/06 01:28:44 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int	nc;
    int ex;
    int px;
    int py;
    int line_lenth;
    int num_lines;
    char    **cmp;
}	t_list;

char	**ft_split(char const *s, char c);
void	read_map(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_checkmap(char **mp);
void	ft_error(char *s);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void    ft_check_path(char **mp);
int     ft_check_content(int c, char **mp);
char	*ft_strdup(const char *s1);

#endif