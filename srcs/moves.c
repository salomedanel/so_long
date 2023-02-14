/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:36:22 by sdanel            #+#    #+#             */
/*   Updated: 2023/02/10 13:25:26 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_perso(t_glb *glb, int m, char s)
{
	glb->sl.count_mv = glb->sl.count_mv + 1;
	if (s == 'y')
		glb->sl.perso.y = glb->sl.perso.y + m;
	else if (s == 'x')
		glb->sl.perso.x = glb->sl.perso.x + m;
	ft_printf("count moves: %d\n", glb->sl.count_mv);
}

void	move_up(t_glb *glb)
{
	if (glb->sl.map[glb->sl.perso.x - 1][glb->sl.perso.y] != '1')
	{
		if (glb->sl.map[glb->sl.perso.x][glb->sl.perso.y] == 'S')
		{
			glb->sl.map[glb->sl.perso.x - 1][glb->sl.perso.y] = 'F';
			glb->sl.map[glb->sl.perso.x][glb->sl.perso.y] = 'E';
			move_perso(glb, -1, 'x');
		}
		else if (glb->sl.map[glb->sl.perso.x - 1][glb->sl.perso.y] != 'E')
		{
			glb->sl.map[glb->sl.perso.x - 1][glb->sl.perso.y] = 'F';
			glb->sl.map[glb->sl.perso.x][glb->sl.perso.y] = '0';
			move_perso(glb, -1, 'x');
		}
		else if (glb->sl.map[glb->sl.perso.x - 1][glb->sl.perso.y] == 'E'
				&& check_collect(&glb->sl) > 0)
		{
			glb->sl.map[glb->sl.perso.x - 1][glb->sl.perso.y] = 'S';
			glb->sl.map[glb->sl.perso.x][glb->sl.perso.y] = '0';
			move_perso(glb, -1, 'x');
		}
		else
			victoire(glb);
	}
}

void	move_down(t_glb *glb)
{
	if (glb->sl.map[glb->sl.perso.x + 1][glb->sl.perso.y] != '1')
	{
		if (glb->sl.map[glb->sl.perso.x][glb->sl.perso.y] == 'S')
		{
			glb->sl.map[glb->sl.perso.x + 1][glb->sl.perso.y] = 'F';
			glb->sl.map[glb->sl.perso.x][glb->sl.perso.y] = 'E';
			move_perso(glb, 1, 'x');
		}
		else if (glb->sl.map[glb->sl.perso.x + 1][glb->sl.perso.y] != 'E')
		{
			glb->sl.map[glb->sl.perso.x + 1][glb->sl.perso.y] = 'F';
			glb->sl.map[glb->sl.perso.x][glb->sl.perso.y] = '0';
			move_perso(glb, 1, 'x');
		}
		else if (glb->sl.map[glb->sl.perso.x + 1][glb->sl.perso.y] == 'E'
				&& check_collect(&glb->sl) > 0)
		{
			glb->sl.map[glb->sl.perso.x + 1][glb->sl.perso.y] = 'S';
			glb->sl.map[glb->sl.perso.x][glb->sl.perso.y] = '0';
			move_perso(glb, 1, 'x');
		}
		else
			victoire(glb);
	}
}

void	move_left(t_glb *glb)
{
	if (glb->sl.map[glb->sl.perso.x][glb->sl.perso.y - 1] != '1')
	{
		if (glb->sl.map[glb->sl.perso.x][glb->sl.perso.y] == 'S')
		{
			glb->sl.map[glb->sl.perso.x][glb->sl.perso.y - 1] = 'G';
			glb->sl.map[glb->sl.perso.x][glb->sl.perso.y] = 'E';
			move_perso(glb, -1, 'y');
		}
		else if (glb->sl.map[glb->sl.perso.x][glb->sl.perso.y - 1] != 'E')
		{
			glb->sl.map[glb->sl.perso.x][glb->sl.perso.y - 1] = 'G';
			glb->sl.map[glb->sl.perso.x][glb->sl.perso.y] = '0';
			move_perso(glb, -1, 'y');
		}
		else if (glb->sl.map[glb->sl.perso.x][glb->sl.perso.y - 1] == 'E'
				&& check_collect(&glb->sl) > 0)
		{
			glb->sl.map[glb->sl.perso.x][glb->sl.perso.y - 1] = 'S';
			glb->sl.map[glb->sl.perso.x][glb->sl.perso.y] = '0';
			move_perso(glb, -1, 'y');
		}
		else
			victoire(glb);
	}
}

void	move_right(t_glb *glb)
{
	if (glb->sl.map[glb->sl.perso.x][glb->sl.perso.y + 1] != '1')
	{
		if (glb->sl.map[glb->sl.perso.x][glb->sl.perso.y] == 'S')
		{
			glb->sl.map[glb->sl.perso.x][glb->sl.perso.y + 1] = 'D';
			glb->sl.map[glb->sl.perso.x][glb->sl.perso.y] = 'E';
			move_perso(glb, 1, 'y');
		}
		else if (glb->sl.map[glb->sl.perso.x][glb->sl.perso.y + 1] != 'E')
		{
			glb->sl.map[glb->sl.perso.x][glb->sl.perso.y + 1] = 'D';
			glb->sl.map[glb->sl.perso.x][glb->sl.perso.y] = '0';
			move_perso(glb, 1, 'y');
		}
		else if (glb->sl.map[glb->sl.perso.x][glb->sl.perso.y + 1] == 'E'
				&& check_collect(&glb->sl) > 0)
		{
			glb->sl.map[glb->sl.perso.x][glb->sl.perso.y + 1] = 'S';
			glb->sl.map[glb->sl.perso.x][glb->sl.perso.y] = '0';
			move_perso(glb, 1, 'y');
		}
		else
			victoire(glb);
	}
}
