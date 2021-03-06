/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <taehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 23:01:52 by taehkim           #+#    #+#             */
/*   Updated: 2020/03/18 02:16:41 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
int		ft_reading(int fd, char **src)
{
	char			buf[BUFFER_SIZE + 1];
	int				temp;

	while ((temp = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[temp] = '\0';
		ft_strcat(src, buf, temp, 0);
		if (ft_has_new_line(buf))
			break ;
	}
	printf("%d\n", temp);
	if (temp == -1 || BUFFER_SIZE <= 0)
		return (-1);
	if (temp == 0 && !*src)
		return (0);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char		*src;
	int				temp;
	int				retcode;

	retcode = 1;
	if (!src || (src && !ft_has_new_line(src)))
		retcode = ft_reading(fd, &src);
	if (retcode == -1 || line == NULL)
		return (-1);
	if (retcode == 0 || !ft_has_new_line(src))
	{
		temp = ft_strlen(src);
		*line = ft_strndup(src, temp);
		if (src)
			free(src);
		src = NULL;
		return (0);
	}
	temp = ft_get_next_size(src);
	*line = ft_strndup(src, temp);
	ft_src_set(&src, temp + 1);
	return (retcode);
}
