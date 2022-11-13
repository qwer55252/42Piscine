/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map_bsq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:24:07 by cyun              #+#    #+#             */
/*   Updated: 2022/06/06 21:08:29 by cyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_map_bsq.h"
#include "integer_func.h"

int	ft_is_valid_map(char *line, t_map *map)
{
	int	idx;

	idx = 0;
	while (line[idx])
	{
		if (line[idx] != map->empty_char && line[idx] != map->obstacle_char)
			return (0);
		idx++;
	}
	return (1);
}

int	**make_integer_map(t_map *map)
{
	int	y_pos;
	int	x_pos;
	int	**buf;

	buf = (int **)malloc(sizeof(int *) * (map->y_len));
	if (!buf)
		exit(0);
	y_pos = -1;
	while (++y_pos < map->y_len)
	{
		buf[y_pos] = (int *)malloc(sizeof(int) * (map->x_len));
		if (!buf[y_pos])
			exit(0);
		x_pos = -1;
		while (++x_pos < map->x_len)
		{
			if (map->filled_map[y_pos][x_pos] == map->obstacle_char)
				buf[y_pos][x_pos] = 0;
			else
				buf[y_pos][x_pos] = 1;
		}
	}
	return (buf);
}

void	find_max_square(int y_pos, t_map *map, int **dp, t_square *square)
{
	int	x_pos;
	int	max_len;

	x_pos = -1;
	while (++x_pos < map->x_len)
	{
		if (y_pos == 0 || x_pos == 0)
			if (dp[y_pos][x_pos] > square->square_length)
				change_square(square, x_pos, y_pos, dp[y_pos][x_pos]);
		if (y_pos == 0 || x_pos == 0)
			continue ;
		if (dp[y_pos][x_pos] == 1)
		{
			max_len = check_square(dp, x_pos, y_pos);
			if (max_len > square->square_length)
				change_square(square, x_pos, y_pos, max_len);
		}
	}
}

t_square	*setting_find_square(t_map *map)
{
	t_square	*square;
	int			**dp;
	int			y_pos;

	square = (t_square *)malloc(sizeof(t_square));
	if (!square)
		exit(0);
	change_square(square, -1, -1, 0);
	dp = make_integer_map(map);
	y_pos = -1;
	while (++y_pos < map->y_len)
		find_max_square(y_pos, map, dp, square);
	y_pos = 0;
	while (y_pos < map->y_len)
		free(dp[y_pos++]);
	free(dp);
	return (square);
}
