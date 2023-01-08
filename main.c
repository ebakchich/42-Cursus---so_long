/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:48:15 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/08 02:17:57 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_ber(char *s)
{
	int	l;
	int	i;
	char	*ar;

	ar = ".ber";
	l = ft_strlen(s);
	if (l <= 4)
		ft_error("Error\nCheck name of the map");
	while (s[l - 4 + i] != '\0' && i < 4)
	{
		if (s[l - 4 + i] != ar[i])
			ft_error("Error\nCheck name of the map");
		i++;
	}
}

int	main(int ac, char **av)
{
	int	fd;
	int	len;

	if (ac != 2)
		ft_error("Error\nthe number of parameters is not 1");
	ft_check_ber(av[1]);
	len = ft_strlen(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error("Error\nfd not valid");
	read_map(fd);
	close(fd);
	//system("leaks so_long");
	return (0);
}
