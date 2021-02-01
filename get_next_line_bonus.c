/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 09:17:44 by ebarguil          #+#    #+#             */
/*   Updated: 2021/01/29 14:19:04 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_saver(char *s)
{
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = ft_strl_n(s);
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	if (s && s[i])
		i++;
	j = 0;
	while (s && s[i])
		s[j++] = s[i++];
	s[j] = '\0';
	return (s);
}

char	*ft_strcut(char *s)
{
	char	*new;
	int		i;

	if (!(new = malloc(sizeof(char) * (ft_strl_n(s) + 1))))
		return (NULL);
	i = 0;
	if (s)
		while (s[i] && s[i] != '\n')
		{
			new[i] = s[i];
			i++;
		}
	new[i] = '\0';
	return (new);
}

int		get_next_line(int fd, char **line)
{
	static char	*s[1024];
	char		*tmp;
	char		buf[BUFFER_SIZE + 1];
	int			x;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	x = 1;
	while (check_n(s[fd]) == 0 && (x = read(fd, buf, BUFFER_SIZE)) != 0)
	{
		if (x == -1)
			return (-1);
		buf[x] = '\0';
		tmp = s[fd];
		s[fd] = ft_strjoin(tmp, buf);
		free(tmp);
	}
	*line = ft_strcut(s[fd]);
	s[fd] = ft_saver(s[fd]);
	if (x == 0)
		return (0);
	return (1);
}
