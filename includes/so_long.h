/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:39:39 by sdanel            #+#    #+#             */
/*   Updated: 2023/02/13 16:11:23 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define ERR_ARG "Error\n[⛔ 🗺️ ] This programm needs only one map as argument.\n"
# define ERR_BER "Error\n[⛔ 🍻] Map has to be a .ber format.\n"
# define ERR_MAP "Error\n[⛔ 📁] This map doesn't exist.\n"
# define ERR_EMPTY "Error\n[⛔ 🧐] Empty map.\n"
# define ERR_FMT "Error\n[⛔ 💵] Map needs rectangular or square format.\n"
# define ERR_WALL "Error\n[⛔ 🧱] Map is not framed by walls.\n"
# define ERR_PE "Error\n[⛔ 🏁] Map needs (only)one player and (only)one exit.\n"
# define ERR_C "Error\n[⛔ 🪙 ] Map needs at least one collectible.\n"
# define ERR_UKNOWN "Error\n[⛔ ❓] Map contains a non valid element.\n"
# define ERR_PATH "Error\n[⛔ 🪱 ] No valid path for this map.\n"
# define ERR_MLC "Error\nMalloc issue.\n"
# define ERR_WIN "Error\nWindow couldn't be opened.\n"
# define FLOOR "./texture/floor.xpm"
# define WALL "./texture/pwall.xpm"
# define COLLECT00 "./texture/pcollect00.xpm"
# define PLAYERD "./texture/playerd.xpm"
# define PLAYERG "./texture/playerg.xpm"
# define PLAYERF "./texture/pplayerf.xpm"
# define EXIT "./texture/pexit.xpm"
# define PLAY_EXIT "./texture/pexit_player.xpm"

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_sl
{
	int		file;
	char	*line;
	char	**map;
	char	**cp2_map;
	char	**cp_map;
	int		nb_line;
	int		width;
	int		e;
	int		p;
	int		c;
	t_pos	perso;
	t_pos	perso_move;
	t_pos	exit;
	t_pos	collec;
	int		x;
	int		y;
	int		count_mv;
}			t_sl;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	void	*img_wall;
	void	*img_floor;
	void	*img_collect00;
	void	*img_playerd;
	void	*img_playerg;
	void	*img_playerf;
	void	*img_exit;
	void	*img_player_exit;
	int		width;
	int		height;
}			t_mlx;

typedef struct s_glb
{
	t_mlx	mlx;
	t_sl	sl;
}			t_glb;

// get_map
int			check_arg(int argc, char **argv);
void		malloc_map(t_sl *sl);
char		*strdup_sl(t_sl *sl, int line);
void		init_variables(t_sl *sl);
void		get_map(t_sl *sl, char **argv);
//check_map
void		check_mapsize(t_sl *sl);
void		check_mapwalls(t_sl *sl);
void		charvalue(t_sl *sl, int i, int j);
void		check_mapchar(t_sl *sl);
// utils00
void		perso_position(t_sl *sl);
void		exit_position(t_sl *sl);
void		collec_position(t_sl *sl);
void		copy_map(t_sl *sl);
void		copy2_map(t_sl *sl);
//utils01
void		group_functions(t_sl *sl, int i, int j);
int			check_around(t_sl *sl);
int			check_stopalgo(t_sl *sl);
int			onlywalls(t_sl *sl, int i, int j);
void		invalid_path(t_sl *sl);
//utils02
void		init_window(t_sl *sl, t_mlx *mlx);
void		init_img(t_mlx *mlx);
int			check_collect(t_sl *sl);
void		victoire(t_glb *glb);
// check_path
void		search_freshpath(t_sl *sl);
void		search_otherpath(t_sl *sl);
int			stop_algo(t_sl *sl, int i, int j);
void		find_path(t_sl *sl, int i, int j);
void		check_path(t_sl *sl);
// free
void		ft_error(char *err);
void		free_map(t_sl *sl);
void		free_cpmap(t_sl *sl);
void		free_cp2map(t_sl *sl);
void		free_error(t_sl *sl, char *err);
// visu
void		display_img(t_mlx *mlx, int i, int j, void *img);
int			display(t_glb *glb);
int			display_background(t_glb *glb);
int			display_player(t_glb *glb);
//moves
void		move_perso(t_glb *glb, int m, char s);
void		move_up(t_glb *glb);
void		move_down(t_glb *glb);
void		move_left(t_glb *glb);
void		move_right(t_glb *glb);
//main
int			key_press(int keycode, t_glb *glb);
int			quit(t_glb *glb);
#endif
