/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:43:27 by azulu             #+#    #+#             */
/*   Updated: 2018/09/11 10:43:30 by azulu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	s2 = ft_strnew(len);
	if (s2 == NULL)
		return (NULL);
	while (len > 0)
	{
		s2[i] = s[start + i];
		i++;
		len--;
	}
	return (s2);
}
