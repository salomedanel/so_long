/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:17:26 by sdanel            #+#    #+#             */
/*   Updated: 2023/02/13 16:12:12 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *err)
{
	write(1, err, ft_strlen(err));
	exit(EXIT_FAILURE);
}

void	free_map(t_sl *sl)
{
	int	i;

	i = 0;
	while (i < sl->nb_line)
	{
		free(sl->map[i]);
		i++;
	}
	free(sl->map);
	close(sl->file);
}

void	free_cpmap(t_sl *sl)
{
	int	i;

	i = 0;
	while (i < sl->nb_line)
	{
		free(sl->cp_map[i]);
		i++;
	}
	free(sl->cp_map);
}

void	free_cp2map(t_sl *sl)
{
	int	i;

	i = 0;
	while (i < sl->nb_line)
	{
		free(sl->cp2_map[i]);
		i++;
	}
	free(sl->cp2_map);
}

void	free_error(t_sl *sl, char *err)
{
	int	i;

	i = 0;
	write(1, err, ft_strlen(err));
	while (i < sl->nb_line)
	{
		free(sl->map[i]);
		i++;
	}
	free(sl->map);
	close(sl->file);
	exit(EXIT_FAILURE);
}
