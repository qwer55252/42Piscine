/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:15:32 by cyun              #+#    #+#             */
/*   Updated: 2022/06/06 22:48:56 by cyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "find_map_bsq.h"
#include "free.h"
#include "information.h"
#include "line.h"
#include "string_func.h"

int	check_read_map(int *idx, t_map *map, char *line)
{
	int	len;

	if (*idx == map->y_len || !ft_is_valid_map(line, map))
	{
		free(line);
		free_map(map, *idx);
		return (0);
	}
	len = ft_strlen(line);
	if (map->x_len == 0)
		map->x_len = len;
	if (len != map->x_len)
	{
		free(line);
		free_map(map, *idx);
		return (0);
	}
	map->filled_map[(*idx)++] = line;
	return (1);
}

t_map	*read_map(int fd, int idx, int cnt)
{
	char	*line;
	t_map	*map;
	char	c;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		exit(0);
	if (!parse_map_info(map, read_info(fd)))
		return (0);
	map->filled_map = (char **)malloc(sizeof(char *) * map->y_len);
	if (!map->filled_map)
		exit(0);
	map->x_len = 0;
	line = read_line(fd, &cnt);
	if (!check_read_map(&idx, map, line))
		return (0);
	while (line)
	{
		if (cnt == map->y_len)
			break ;
		line = read_line_faster(map, fd, &cnt);
		if (!check_read_map(&idx, map, line))
			return (0);
	}
	if (idx != map->y_len || (fd != 0 && read(fd, &c, 1)))
	{
		free_map(map, idx);
		return (0);
	}
	return (map);
}

t_map	*read_stdin(void)
{
	int	fd;
	int	idx;

	fd = 0;
	idx = 0;
	return (read_map(fd, idx, 0));
}

t_map	*read_file(char *file)
{
	int		fd;
	int		idx;
	t_map	*map;

	idx = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	map = read_map(fd, idx, 0);
	close(fd);
	return (map);
}

void	bsq(char *file)
{
	t_square	*square;
	t_map		*map;

	if (file)
		map = read_file(file);
	else
		map = read_stdin();
	if (!map)
	{
		print_err_msg();
		return ;
	}
	square = setting_find_square(map);
	if (!square->square_length)
		print_err_msg();
	else
		print_map(map, square);
	free_map(map, map->y_len);
	free(square);
}
