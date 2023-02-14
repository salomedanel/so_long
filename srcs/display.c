/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:06:21 by sdanel            #+#    #+#             */
/*   Updated: 2023/02/13 14:02:51 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display(t_glb *glb)
{
	display_background(glb);
	display_player(glb);
	return (0);
}

void	display_img(t_mlx *mlx, int i, int j, void *img)
{
	mlx_put_image_to_window(mlx->mlx, mlx->window, img, mlx->width * j,
		mlx->height * i);
}

int	display_background(t_glb *glb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < glb->sl.nb_line)
	{
		while (glb->sl.map[i][j])
		{
			if (glb->sl.map[i][j] == '1')
				display_img(&glb->mlx, i, j, glb->mlx.img_wall);
			if (glb->sl.map[i][j] == '0')
				display_img(&glb->mlx, i, j, glb->mlx.img_floor);
			if (glb->sl.map[i][j] == 'C')
				display_img(&glb->mlx, i, j, glb->mlx.img_collect00);
			if (glb->sl.map[i][j] == 'E')
				display_img(&glb->mlx, i, j, glb->mlx.img_exit);
			if (glb->sl.map[i][j] == 'S')
				display_img(&glb->mlx, i, j, glb->mlx.img_player_exit);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int	display_player(t_glb *glb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < glb->sl.nb_line)
	{
		while (glb->sl.map[i][j])
		{
			if (glb->sl.map[i][j] == 'D')
				display_img(&glb->mlx, i, j, glb->mlx.img_playerd);
			if (glb->sl.map[i][j] == 'G')
				display_img(&glb->mlx, i, j, glb->mlx.img_playerg);
			if (glb->sl.map[i][j] == 'F')
				display_img(&glb->mlx, i, j, glb->mlx.img_playerf);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}
