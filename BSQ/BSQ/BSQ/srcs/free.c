/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:30:39 by cyun              #+#    #+#             */
/*   Updated: 2022/06/05 21:31:23 by cyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	free_map(t_map *map, int size)
{
	int	idx;

	idx = -1;
	while (++idx < size)
		free(map->filled_map[idx]);
	free(map->filled_map);
	free(map);
}

char	*free_line(char *line)
{
	free(line);
	return (0);
}
