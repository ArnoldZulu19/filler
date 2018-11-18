/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:44:49 by azulu             #+#    #+#             */
/*   Updated: 2018/09/11 10:50:25 by azulu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_putline(char const *s1, char const *s2)
{
	char	*new_str;
	char	*str_j;

	str_j = ft_strjoin(s1, s2);
	new_str = ft_strjoin(str_j, "\n");
	return (new_str);
}
