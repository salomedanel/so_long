/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:06:08 by sdanel            #+#    #+#             */
/*   Updated: 2023/02/13 16:12:40 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_arg(int argc, char **argv)
{
	int	map;
	int	argv_len;

	if (argc != 2)
		ft_error(ERR_ARG);
	argv_len = ft_strlen(argv[1]) - 1;
	if (argv[1][argv_len] == 'r')
		argv_len--;
	if (argv[1][argv_len] == 'e')
		argv_len--;
	if (argv[1][argv_len] == 'b')
		argv_len--;
	if (argv[1][argv_len] == '.')
		argv_len--;
	if (argv_len != ft_strlen(argv[1]) - 5)
		ft_error(ERR_BER);
	map = open(argv[1], O_RDONLY);
	if (map < 0)
		ft_error(ERR_MAP);
	return (map);
}

void	malloc_map(t_sl *sl)
{
	int	i;

	i = 0;
	sl->line = get_next_line(sl->file, 0);
	while (sl->line)
	{
		free(sl->line);
		sl->line = get_next_line(sl->file, 0);
		i++;
	}
	free(sl->line);
	sl->nb_line = i;
	if (sl->nb_line == 0)
	{
		close(sl->file);
		ft_error(ERR_EMPTY);
	}
	sl->map = malloc(sizeof(char *) * sl->nb_line);
	if (sl->map == NULL)
	{
		close(sl->file);
		ft_error(ERR_MLC);
	}
	close(sl->file);
}

char	*strdup_sl(t_sl *sl, int line)
{
	int		i;
	char	*s_dup;

	i = -1;
	s_dup = malloc(sizeof(char) * ft_strlen(sl->line) + 1);
	if (s_dup == NULL)
		return (0);
	if (line == (sl->nb_line - 1) && ft_strlen(sl->line) == sl->width
		&& sl->line[sl->width - 1] != '\n')
	{
		free(s_dup);
		return (0);
	}
	if (line == (sl->nb_line - 1) && ft_strlen(sl->line) < sl->width)
	{
		while (sl->line[++i])
			s_dup[i] = sl->line[i];
	}
	else
	{
		while (sl->line[++i + 1])
			s_dup[i] = sl->line[i];
	}
	s_dup[i] = '\0';
	return (s_dup);
}

void	init_variables(t_sl *sl)
{
	sl->e = 0;
	sl->p = 0;
	sl->c = 0;
	sl->width = ft_strlen(sl->line);
}

void	get_map(t_sl *sl, char **argv)
{
	int	i;

	i = 0;
	malloc_map(sl);
	sl->file = open(argv[1], O_RDONLY);
	sl->line = get_next_line(sl->file, 0);
	init_variables(sl);
	while (i < sl->nb_line)
	{
		sl->map[i] = strdup_sl(sl, i);
		if (sl->map[i] == 0)
		{
			free(sl->line);
			get_next_line(sl->file, 1);
			free_map(sl);
			ft_error(ERR_FMT);
		}
		free(sl->line);
		sl->line = get_next_line(sl->file, 0);
		i++;
	}
	free(sl->line);
	check_mapsize(sl);
	check_mapwalls(sl);
	check_mapchar(sl);
}
