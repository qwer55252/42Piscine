/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 22:02:29 by cyun              #+#    #+#             */
/*   Updated: 2022/06/06 00:23:12 by cyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	print_map(t_map *map, t_square *square)
{
	int	y_pos;

	fill_square_map(map, square);
	y_pos = -1;
	while (++y_pos < map->y_len)
	{
		write(1, map->filled_map[y_pos], map->x_len);
		ft_putchar('\n');
	}
}

void	fill_square_map(t_map *map, t_square *square)
{
	char	full_char;
	int		x_pos;
	int		y_pos;

	full_char = map->full_char;
	y_pos = square->y_point - square->square_length;
	while (++y_pos <= square->y_point)
	{
		x_pos = square->x_point - square->square_length;
		while (++x_pos <= square->x_point)
			map->filled_map[y_pos][x_pos] = full_char;
	}
}
