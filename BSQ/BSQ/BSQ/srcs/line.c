/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:40:39 by cyun              #+#    #+#             */
/*   Updated: 2022/06/06 22:22:04 by cyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"
#include "string_func.h"
#include "free.h"
#include "stdio.h"

char	*expand_line(char *origin_line, int *len)
{
	char	*new_line;

	new_line = (char *)malloc(sizeof(char) * (*len + 1));
	if (!new_line)
		exit(0);
	ft_strncpy(new_line, origin_line, *len);
	*len += 1;
	free(origin_line);
	return (new_line);
}

char	*read_info(int fd)
{
	char	*line;
	char	buf;
	int		idx;
	int		len;

	idx = 0;
	len = 2;
	line = (char *)malloc(sizeof(char) * len);
	if (!line)
		exit(0);
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
		{
			line[idx++] = '\0';
			break ;
		}
		if (idx + 1 == len)
			line = expand_line(line, &len);
		line[idx++] = buf;
	}
	if (idx == 0)
		return (free_line(line));
	return (line);
}

char	*read_line(int fd, int *cnt)
{
	char	*line;
	char	buf;
	int		idx;
	int		len;

	idx = 0;
	len = 2;
	line = (char *)malloc(sizeof(char) * len);
	if (!line)
		exit(0);
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
		{
			line[idx] = '\0';
			break ;
		}
		if (idx + 1 == len)
			line = expand_line(line, &len);
		line[idx++] = buf;
	}
	if (idx == 0)
		return (free_line(line));
	(*cnt)++;
	return (line);
}

char	*read_line_faster(t_map *map, int fd, int *cnt)
{
	char	*line;

	line = (char *)malloc(sizeof(char) * (map->x_len + 1));
	if (!line)
		exit(0);
	read(fd, line, map->x_len + 1);
	if (line[map->x_len] == '\n')
		line[map->x_len] = '\0';
	(*cnt)++;
	return (line);
}
