/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:59:22 by sdanel            #+#    #+#             */
/*   Updated: 2023/02/10 14:37:02 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	group_functions(t_sl *sl, int i, int j)
{
	copy2_map(sl);
	find_path(sl, i, j);
	free_cp2map(sl);
}

int	check_around(t_sl *sl)
{
	if ((sl->cp2_map[sl->x + 1][sl->y] == '1' || sl->cp2_map[sl->x
			+ 1][sl->y] == 'X' || sl->cp2_map[sl->x + 1][sl->y] == 'N')
		&& (sl->cp2_map[sl->x - 1][sl->y] == '1' || sl->cp2_map[sl->x
			- 1][sl->y] == 'X' || sl->cp2_map[sl->x - 1][sl->y] == 'N')
		&& (sl->cp2_map[sl->x][sl->y + 1] == '1' || sl->cp2_map[sl->x][sl->y
			+ 1] == 'X' || sl->cp2_map[sl->x][sl->y + 1] == 'N')
		&& (sl->cp2_map[sl->x][sl->y - 1] == '1' || sl->cp2_map[sl->x][sl->y
			- 1] == 'X' || sl->cp2_map[sl->x][sl->y - 1] == 'N'))
		return (1);
	return (0);
}

int	check_stopalgo(t_sl *sl)
{
	if ((sl->cp2_map[sl->x + 1][sl->y] == '1' || sl->cp2_map[sl->x
			+ 1][sl->y] == 'N') && (sl->cp2_map[sl->x - 1][sl->y] == '1'
			|| sl->cp2_map[sl->x - 1][sl->y] == 'N')
		&& (sl->cp2_map[sl->x][sl->y + 1] == '1' || sl->cp2_map[sl->x][sl->y
			+ 1] == 'N') && (sl->cp2_map[sl->x][sl->y - 1] == '1'
			|| sl->cp2_map[sl->x][sl->y - 1] == 'N'))
		return (1);
	return (0);
}

int	onlywalls(t_sl *sl, int i, int j)
{
	if (sl->cp2_map[i + 1][j] == '1' && sl->cp2_map[i - 1][j] == '1'
		&& sl->cp2_map[i][j + 1] == '1' && sl->cp2_map[i][j - 1] == '1')
		return (1);
	return (0);
}

void	invalid_path(t_sl *sl)
{
	free_cpmap(sl);
	free_cp2map(sl);
	free_error(sl, ERR_PATH);
}
