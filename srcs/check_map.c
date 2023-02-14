/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:12:47 by sdanel            #+#    #+#             */
/*   Updated: 2023/02/13 14:33:37 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_mapsize(t_sl *sl)
{
	int	i;

	i = 0;
	sl->width = ft_strlen(sl->map[i]);
	i++;
	while (i < sl->nb_line)
	{
		if (ft_strlen(sl->map[i]) != sl->width)
		{
			free_map(sl);
			ft_error(ERR_FMT);
		}
		i++;
	}
}

void	check_mapwalls(t_sl *sl)
{
	int	i;
	int	j;

	i = 0;
	while (i < sl->nb_line)
	{
		if (i == 0 || i == sl->nb_line - 1)
		{
			j = 0;
			while (sl->map[i][j])
			{
				if (sl->map[i][j] != 49)
					free_error(sl, ERR_WALL);
				j++;
			}
		}
		else if (i != 0 && i != sl->width)
		{
			if (sl->map[i][0] != 49 || sl->map[i][sl->width - 1] != 49)
				free_error(sl, ERR_WALL);
		}
		i++;
	}
}

void	charvalue(t_sl *sl, int i, int j)
{
	while (sl->map[i][j])
	{
		if (sl->map[i][j] == 'E')
			sl->e = sl->e + 1;
		if (sl->map[i][j] == 'P')
			sl->p = sl->p + 1;
		if (sl->map[i][j] == 'C')
			sl->c = sl->c + 1;
		if (sl->map[i][j] != 'E' && sl->map[i][j] != 'P' && sl->map[i][j] != 'C'
			&& sl->map[i][j] != '1' && sl->map[i][j] != 48)
			free_error(sl, ERR_UKNOWN);
		j++;
	}
}

void	check_mapchar(t_sl *sl)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < sl->nb_line - 1)
	{
		charvalue(sl, i, j);
		j = 0;
		i++;
	}
	if (sl->e != 1 || sl->p != 1)
		free_error(sl, ERR_PE);
	else if (sl->c < 1)
		free_error(sl, ERR_C);
}
