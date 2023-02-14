/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:30:03 by sdanel            #+#    #+#             */
/*   Updated: 2023/02/10 14:37:37 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	search_freshpath(t_sl *sl)
{
	if (sl->cp2_map[sl->x + 1][sl->y] != '1' && sl->cp2_map[sl->x
		+ 1][sl->y] != 'X' && sl->cp2_map[sl->x + 1][sl->y] != 'N')
	{
		sl->cp2_map[sl->x][sl->y] = 'X';
		sl->x++;
	}
	else if (sl->cp2_map[sl->x - 1][sl->y] != '1' && sl->cp2_map[sl->x
			- 1][sl->y] != 'X' && sl->cp2_map[sl->x - 1][sl->y] != 'N')
	{
		sl->cp2_map[sl->x][sl->y] = 'X';
		sl->x--;
	}
	else if (sl->cp2_map[sl->x][sl->y + 1] != '1' && sl->cp2_map[sl->x][sl->y
			+ 1] != 'X' && sl->cp2_map[sl->x][sl->y + 1] != 'N')
	{
		sl->cp2_map[sl->x][sl->y] = 'X';
		sl->y++;
	}
	else if (sl->cp2_map[sl->x][sl->y - 1] != '1' && sl->cp2_map[sl->x][sl->y
			- 1] != 'X' && sl->cp2_map[sl->x][sl->y - 1] != 'N')
	{
		sl->cp2_map[sl->x][sl->y] = 'X';
		sl->y--;
	}
}

void	search_otherpath(t_sl *sl)
{
	if (check_around(sl) == 1)
	{
		if (sl->cp2_map[sl->x + 1][sl->y] == 'X')
		{
			sl->cp2_map[sl->x][sl->y] = 'N';
			sl->x++;
		}
		else if (sl->cp2_map[sl->x - 1][sl->y] == 'X')
		{
			sl->cp2_map[sl->x][sl->y] = 'N';
			sl->x--;
		}
		else if (sl->cp2_map[sl->x][sl->y + 1] == 'X')
		{
			sl->cp2_map[sl->x][sl->y] = 'N';
			sl->y++;
		}
		else if (sl->cp2_map[sl->x][sl->y - 1] == 'X')
		{
			sl->cp2_map[sl->x][sl->y] = 'N';
			sl->y--;
		}
	}
}

int	stop_algo(t_sl *sl, int i, int j)
{
	if (sl->x == i && sl->y == j)
		return (1);
	else if (onlywalls(sl, i, j) == 1)
		invalid_path(sl);
	else if (((sl->cp2_map[sl->x + 1][sl->y] == '1' || sl->cp2_map[sl->x
				+ 1][sl->y] == 'N') && (sl->cp2_map[sl->x - 1][sl->y] == '1'
					|| sl->cp2_map[sl->x - 1][sl->y] == 'N')
				&& (sl->cp2_map[sl->x][sl->y + 1] == '1'
					|| sl->cp2_map[sl->x][sl->y + 1] == 'N')
				&& (sl->cp2_map[sl->x][sl->y - 1] == '1'
					|| sl->cp2_map[sl->x][sl->y - 1] == 'N')
				&& sl->x == sl->perso.x && sl->y == sl->perso.y))
		invalid_path(sl);
	else if (check_stopalgo(sl) == 1)
	{
		sl->x = sl->perso.x;
		sl->y = sl->perso.y;
		find_path(sl, i, j);
	}
	return (0);
}

void	find_path(t_sl *sl, int i, int j)
{
	if (stop_algo(sl, i, j) == 1)
		return ;
	else
	{
		search_freshpath(sl);
		if (stop_algo(sl, i, j) == 1)
			return ;
		search_otherpath(sl);
	}
	find_path(sl, i, j);
}

void	check_path(t_sl *sl)
{
	int	i;
	int	j;

	perso_position(sl);
	exit_position(sl);
	copy_map(sl);
	while (sl->c > 0)
	{
		collec_position(sl);
		sl->x = sl->perso.x;
		sl->y = sl->perso.y;
		i = sl->collec.x;
		j = sl->collec.y;
		group_functions(sl, i, j);
		sl->c--;
	}
	sl->x = sl->perso.x;
	sl->y = sl->perso.y;
	i = sl->exit.x;
	j = sl->exit.y;
	group_functions(sl, i, j);
	check_collect(sl);
	free_cpmap(sl);
}
