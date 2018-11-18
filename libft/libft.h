/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:41:48 by azulu             #+#    #+#             */
/*   Updated: 2018/09/21 16:35:23 by azulu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFF_SIZE 42

void		ft_bzero(void *s, int n);
char		*ft_strcpy(char *dst, const char *src);
int			ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*ft_strchr(const char *s, int c);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
void		*ft_memalloc(size_t size);
void		*ft_memset(void *b, int c, size_t len);
char		*ft_strnew(size_t size);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_strsplit(char const *s, char c);
void		ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr(int n);
void		ft_putnbr_fd(int n, int fd);
int			ft_checksign(int n);
int			get_next_line(const int fd, char **line);
char		*ft_putline(char const *s1, char const *s2);
void		ft_putstr(char *str);

#endif
