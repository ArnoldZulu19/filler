/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:45:37 by azulu             #+#    #+#             */
/*   Updated: 2018/09/11 10:45:39 by azulu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_cpy_contents(const int fd, char **line)
{
	char		*buffer;
	char		*temp;
	int			value;

	if (!(buffer = (char *)malloc(sizeof(*buffer) * (BUFF_SIZE + 1))))
		return (-1);
	value = read(fd, buffer, BUFF_SIZE);
	if (value > 0)
	{
		buffer[value] = '\0';
		temp = ft_strjoin(*line, buffer);
		free(*line);
		*line = temp;
	}
	free(buffer);
	return (value);
}

int				get_next_line(const int fd, char **line)
{
	static char	*stack = NULL;
	char		*line_feed;
	int			value;

	if ((!stack && (stack = (char*)malloc(sizeof(*stack))) == NULL) || !line
			|| fd < 0 || BUFF_SIZE < 0)
		return (-1);
	line_feed = ft_strchr(stack, '\n');
	while (line_feed == '\0')
	{
		value = ft_cpy_contents(fd, &stack);
		if (value == 0)
		{
			if (ft_strlen(stack) == 0)
				return (0);
			stack = ft_strjoin(stack, "\n");
		}
		if (value < 0)
			return (-1);
		else
			line_feed = ft_strchr(stack, '\n');
	}
	*line = ft_strsub(stack, 0, ft_strlen(stack) - ft_strlen(line_feed));
	stack = ft_strdup(line_feed + 1);
	return (1);
}
