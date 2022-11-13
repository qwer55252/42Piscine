/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   information.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:31:33 by cyun              #+#    #+#             */
/*   Updated: 2022/06/06 22:21:27 by cyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "information.h"
#include "integer_func.h"
#include "stdio.h"

int	is_printable(char c)
{
	if (' ' <= c && c <= '~')
		return (1);
	return (0);
}

int	is_valid_map_info(t_map *map)
{
	if (is_printable(map->full_char))
		return (1);
	else if (is_printable(map->obstacle_char))
		return (1);
	else if (is_printable(map->empty_char))
		return (1);
	return (0);
}

int	is_valid_char_info(t_map *map)
{
	if (map->empty_char == map->obstacle_char)
		return (0);
	else if (map->empty_char == map->full_char)
		return (0);
	else if (map->obstacle_char == map->full_char)
		return (0);
	else if (!is_valid_map_info(map))
		return (0);
	return (1);
}

int	init_map_info(t_map *map, char *info)
{
	int	len;

	len = ft_strlen(info);
	if (!info || len < 4)
		return (0);
	map->full_char = info[len - 1];
	map->obstacle_char = info[len - 2];
	map->empty_char = info[len - 3];
	if (map->empty_char == map->obstacle_char
		|| map->empty_char == map->full_char
		|| map->obstacle_char == map->full_char
		|| !is_valid_map_info(map))
		return (0);
	info[len - 3] = 'a';
	map->y_len = ft_atoi(info);
	if (!map->y_len || map->y_len < 0)
		return (0);
	return (1);
}

int	parse_map_info(t_map *map, char *info)
{
	int	tmp;

	tmp = init_map_info(map, info);
	if (!tmp)
		free(map);
	free(info);
	return (tmp);
}
