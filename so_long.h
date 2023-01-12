/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:40:17 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/12 17:59:28 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>

typedef struct a_list
{
	int		nc;
	int		ex;
	int		px;
	int		py;
	int		line_lenth;
	int		num_lines;
	char	**cmp;
}	t_list;

typedef struct b_list
{
	char	**mp;
	void	*mx;
	void	*wn;
	void	*p;
	void	*e;
	void	*c;
	void	*s;
	void	*w;
	void	*n;
	int		ln;
	int		nn;
	int		x;
	int		y;
	int		nc;
	int		nm;
	int		an;
}	t_listt;

typedef struct c_list
{
	int	wid;
	int	hei;

}	t_lst;

char	**ft_split(char const *s, char c);
void	read_map(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(int r, char *s1, char *s2);
void	ft_checkmap(char **mp);
void	ft_error(char *s);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	ft_check_path(char **mp, int k);
int		ft_check_content(int c, char **mp);
char	*ft_strdup(const char *s1);
void	ft_creat_gm(char **mp);
int		ft_action(void);
int		ft_manage_key(int k, t_listt *s);
void	ft_fill_mp(t_listt *s, char **mp, int i, int j);
char	*ft_itoa(int n);
void	ft_putstr(char *str);
int		ft_anim_c(t_listt *s);
void	ft_fill_mp(t_listt *s, char **mp, int i, int j);
void	ft_free(t_list *l);

#endif