/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:53:41 by azulu             #+#    #+#             */
/*   Updated: 2018/09/11 10:53:43 by azulu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"

typedef struct	s_fr
{
	int		player;
	char	m_l;
	char	e_l;
	char	*line;
	char	**board;
	char	**piece;
	int		y_board;
	int		x_board;
	int		y_piece;
	int		x_piece;
	int		y_en;
	int		x_en;
	int		y_bd;
	int		x_bd;
	int		x;
	int		y;
	int		i;
	int		cur_len;
	int		prev_len;
}				t_fr;

void			read_piece(t_fr *f);
void			read_board(t_fr *f);
void			my_player(t_fr *f);
void			is_close(t_fr *f, int s);

#endif
