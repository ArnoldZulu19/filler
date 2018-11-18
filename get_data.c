/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:39:01 by azulu             #+#    #+#             */
/*   Updated: 2018/09/19 09:25:25 by azulu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

void		save_board(t_fr *f)
{
	int		i;
	char	*s;

	i = 0;
	s = "\0";
	while (i < f->y_board)
	{
		get_next_line(0, &(f->line));
		if (ft_isdigit(f->line[0]))
		{
			s = ft_putline(s, f->line + 4);
			i++;
		}
	}
	f->board = ft_strsplit(s, '\n');
}

void		read_board(t_fr *f)
{
	f->y_board = ft_atoi(f->line + 8);
	f->x_board = ft_atoi(f->line + 11);
	save_board(f);
}

void		save_piece(t_fr *f)
{
	int		i;
	char	*s;

	i = 0;
	s = "\0";
	while (i < f->y_piece)
	{
		get_next_line(0, &(f->line));
		s = ft_putline(s, f->line);
		i++;
	}
	f->piece = ft_strsplit(s, '\n');
}

void		read_piece(t_fr *f)
{
	get_next_line(0, &(f->line));
	f->y_piece = ft_atoi(f->line + 6);
	f->x_piece = ft_atoi(f->line + 8);
	save_piece(f);
}
