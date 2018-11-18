/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:51:12 by azulu             #+#    #+#             */
/*   Updated: 2018/09/15 12:08:48 by azulu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int			does_piece_fit(t_fr *f, int yb, int xb)
{
	if (xb + f->x_piece > f->x_board)
		return (0);
	if (yb + f->y_piece > f->y_board)
		return (0);
	return (1);
}

int			check_position(t_fr *f, int yb, int xb)
{
	int		i;
	int		xp;
	int		yp;

	i = 0;
	yp = 0;
	while (yp < f->y_piece)
	{
		xp = 0;
		while (f->piece[yp][xp] != '\0')
		{
			if (f->piece[yp][xp] == '*')
				if (f->board[yb + yp][xb + xp] == f->m_l)
					i++;
			if (f->piece[yp][xp] == '*')
				if (f->board[yb + yp][xb + xp] == f->e_l)
					return (0);
			xp++;
		}
		yp++;
	}
	return (i == 1 ? 1 : 0);
}

void		move_towards(t_fr *f)
{
	int		yp;
	int		xp;
	int		len;

	yp = 0;
	len = 0;
	while (yp < f->y_piece)
	{
		xp = 0;
		while (f->piece[yp][xp] != '\0')
		{
			if (f->piece[yp][xp] == '*')
				len = len + ft_checksign(f->y_en - (f->y_bd + yp)) +
			ft_checksign(f->x_en - (f->x_bd + xp));
			xp++;
		}
		yp++;
	}
	is_close(f, len);
}

void		where_is_opponent(t_fr *f)
{
	int		x;
	int		y;

	y = 0;
	while (y < f->y_board)
	{
		x = 0;
		while (x < f->x_board)
		{
			if (f->board[y][x] == f->e_l)
			{
				f->y_en = y;
				f->x_en = x;
				move_towards(f);
			}
			x++;
		}
		y++;
	}
}

void		my_player(t_fr *f)
{
	int		xb;
	int		yb;

	yb = 0;
	while (yb < f->y_board)
	{
		xb = 0;
		while (xb < f->x_board)
		{
			if (does_piece_fit(f, yb, xb) == 1)
			{
				if (check_position(f, yb, xb) == 1)
				{
					f->x_bd = xb;
					f->y_bd = yb;
					where_is_opponent(f);
				}
			}
			xb++;
		}
		yb++;
	}
}
