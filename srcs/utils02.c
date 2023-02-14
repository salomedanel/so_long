/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:27:36 by sdanel            #+#    #+#             */
/*   Updated: 2023/02/13 14:39:39 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_sl *sl, t_mlx *mlx)
{
	mlx->window = mlx_new_window(mlx->mlx, sl->width * 64, sl->nb_line * 64,
			"SO_LONG");
	if (mlx->window == NULL)
	{
		free(mlx->mlx);
		free_error(sl, ERR_WIN);
	}
}

void	init_img(t_mlx *mlx)
{
	mlx->img_wall = mlx_xpm_file_to_image(mlx->mlx, WALL, &mlx->width,
			&mlx->height);
	mlx->img_floor = mlx_xpm_file_to_image(mlx->mlx, FLOOR, &mlx->width,
			&mlx->height);
	mlx->img_collect00 = mlx_xpm_file_to_image(mlx->mlx, COLLECT00, &mlx->width,
			&mlx->height);
	mlx->img_playerd = mlx_xpm_file_to_image(mlx->mlx, PLAYERD, &mlx->width,
			&mlx->height);
	mlx->img_playerg = mlx_xpm_file_to_image(mlx->mlx, PLAYERG, &mlx->width,
			&mlx->height);
	mlx->img_playerf = mlx_xpm_file_to_image(mlx->mlx, PLAYERF, &mlx->width,
			&mlx->height);
	mlx->img_exit = mlx_xpm_file_to_image(mlx->mlx, EXIT, &mlx->width,
			&mlx->height);
	mlx->img_player_exit = mlx_xpm_file_to_image(mlx->mlx, PLAY_EXIT,
			&mlx->width, &mlx->height);
}

int	check_collect(t_sl *sl)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	sl->c = 0;
	while (i < sl->nb_line)
	{
		while (j < sl->width)
		{
			if (sl->map[i][j] == 'C')
				sl->c = sl->c + 1;
			j++;
		}
		i++;
		j = 0;
	}
	return (sl->c);
}

void	victoire(t_glb *glb)
{
	if (check_collect(&glb->sl) == 0)
	{
		glb->sl.count_mv = glb->sl.count_mv + 1;
		ft_printf("Victoire en %d coups ! 🌟\n", glb->sl.count_mv);
		quit(glb);
	}
}
