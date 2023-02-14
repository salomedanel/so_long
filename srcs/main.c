/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:01:22 by sdanel            #+#    #+#             */
/*   Updated: 2023/02/13 14:39:54 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_glb *glb)
{
	if (keycode == XK_w || keycode == XK_Up)
		move_up(glb);
	if (keycode == XK_s || keycode == XK_Down)
		move_down(glb);
	if (keycode == XK_a || keycode == XK_Left)
		move_left(glb);
	if (keycode == XK_d || keycode == XK_Right)
		move_right(glb);
	if (keycode == XK_Escape)
		quit(glb);
	return (0);
}

int	quit(t_glb *glb)
{
	free_map(&glb->sl);
	mlx_destroy_image(glb->mlx.mlx, glb->mlx.img_wall);
	mlx_destroy_image(glb->mlx.mlx, glb->mlx.img_floor);
	mlx_destroy_image(glb->mlx.mlx, glb->mlx.img_collect00);
	mlx_destroy_image(glb->mlx.mlx, glb->mlx.img_playerd);
	mlx_destroy_image(glb->mlx.mlx, glb->mlx.img_playerg);
	mlx_destroy_image(glb->mlx.mlx, glb->mlx.img_playerf);
	mlx_destroy_image(glb->mlx.mlx, glb->mlx.img_exit);
	mlx_destroy_image(glb->mlx.mlx, glb->mlx.img_player_exit);
	mlx_destroy_window(glb->mlx.mlx, glb->mlx.window);
	mlx_destroy_display(glb->mlx.mlx);
	free(glb->mlx.mlx);
	exit(0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_sl	sl;
	t_mlx	mlx;

	sl.file = check_arg(argc, argv);
	get_map(&sl, argv);
	check_path(&sl);
	mlx.mlx = mlx_init();
	sl.count_mv = 0;
	sl.map[sl.perso.x][sl.perso.y] = 'D';
	init_window(&sl, &mlx);
	init_img(&mlx);
	mlx_loop_hook(mlx.mlx, display, &mlx);
	mlx_hook(mlx.window, 2, 1L << 0, key_press, &mlx);
	mlx_hook(mlx.window, 17, 1L << 0, quit, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
