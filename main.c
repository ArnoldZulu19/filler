/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 11:34:37 by azulu             #+#    #+#             */
/*   Updated: 2018/09/19 09:26:57 by azulu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

void		init_struct(t_fr *f)
{
	f->y = 0;
	f->x = 0;
	f->piece = NULL;
	f->board = NULL;
	f->line = NULL;
	f->y_board = 0;
	f->x_board = 0;
	f->y_piece = 0;
	f->x_piece = 0;
}

void		check_player(t_fr *f)
{
	get_next_line(0, &(f->line));
	f->player = ft_atoi(f->line + 10);
	if (f->player == 1)
	{
		f->m_l = 'O';
		f->e_l = 'X';
	}
	if (f->player == 2)
	{
		f->m_l = 'X';
		f->e_l = 'O';
	}
}

void		is_close(t_fr *f, int s)
{
	if (f->cur_len == -1 || s < f->cur_len)
		f->cur_len = s;
	if (f->prev_len == -1 || f->cur_len < f->prev_len)
	{
		f->prev_len = f->cur_len;
		f->x = f->x_bd;
		f->y = f->y_bd;
		f->i = 1;
	}
}

void		put_piece(t_fr *f)
{
	ft_putnbr(f->y);
	ft_putchar(' ');
	ft_putnbr(f->x);
	ft_putchar('\n');
}

int			main(void)
{
	t_fr	f;

	init_struct(&f);
	check_player(&f);
	while (get_next_line(0, &(f.line)) == 1)
	{
		f.i = 0;
		f.prev_len = -1;
		f.cur_len = -1;
		read_board(&f);
		read_piece(&f);
		my_player(&f);
		if (f.i == 1)
			put_piece(&f);
		else
		{
			f.x = 0;
			f.y = 0;
			put_piece(&f);
			return (0);
		}
	}
}
