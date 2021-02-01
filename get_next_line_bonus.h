/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 09:21:57 by ebarguil          #+#    #+#             */
/*   Updated: 2021/01/29 14:18:28 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
char	*ft_strcut(char *s);
char	*ft_saver(char *s);
int		check_n(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
int		ft_strl_n(char *s);

#endif
