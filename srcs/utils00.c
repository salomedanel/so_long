/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:07:02 by sdanel            #+#    #+#             */
/*   Updated: 2023/02/07 17:45:39 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	perso_position(t_sl *sl)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < sl->nb_line - 1)
	{
		while (sl->map[i][j])
		{
			if (sl->map[i][j] == 'P')
			{
				sl->perso.x = i;
				sl->perso.y = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	exit_position(t_sl *sl)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < sl->nb_line - 1)
	{
		while (sl->map[i][j])
		{
			if (sl->map[i][j] == 'E')
			{
				sl->exit.x = i;
				sl->exit.y = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	collec_position(t_sl *sl)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < sl->nb_line - 1)
	{
		while (j < sl->width)
		{
			if (sl->cp_map[i][j] == 'C')
			{
				sl->collec.x = i;
				sl->collec.y = j;
				sl->cp_map[i][j] = 'R';
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	copy_map(t_sl *sl)
{
	int	i;

	i = 0;
	sl->cp_map = malloc(sizeof(char *) * (sl->nb_line));
	if (!sl->cp_map)
		free_error(sl, ERR_MLC);
	while (i < sl->nb_line)
	{
		sl->cp_map[i] = malloc(sizeof(char) * (sl->width));
		if (!sl->cp_map[i])
		{
			free(sl->cp_map);
			free_error(sl, ERR_MLC);
		}
		i++;
	}
	i = 0;
	while (i < sl->nb_line)
	{
		sl->cp_map[i] = ft_memcpy(sl->cp_map[i], sl->map[i], sl->width);
		i++;
	}
}

void	copy2_map(t_sl *sl)
{
	int	i;

	i = 0;
	sl->cp2_map = malloc(sizeof(char *) * (sl->nb_line));
	if (!sl->cp2_map)
		free_error(sl, ERR_MLC);
	while (i < sl->nb_line)
	{
		sl->cp2_map[i] = malloc(sizeof(char) * (sl->width));
		if (!sl->cp2_map[i])
		{
			free(sl->cp2_map);
			free_error(sl, ERR_MLC);
		}
		i++;
	}
	i = 0;
	while (i < sl->nb_line)
	{
		sl->cp2_map[i] = ft_memcpy(sl->cp2_map[i], sl->map[i], sl->width);
		i++;
	}
}
