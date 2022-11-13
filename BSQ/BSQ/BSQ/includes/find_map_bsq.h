/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map_bsq.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:50:26 by cyun              #+#    #+#             */
/*   Updated: 2022/06/05 20:52:17 by cyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_MAP_BSQ_H
# define FIND_MAP_BSQ_H

# include "structs.h"
# include "stdlib.h"

int			ft_is_valid_map(char *line, t_map *map);
int			**make_integer_map(t_map *map);
void		find_max_square(int y_pos, t_map *map, int **dp, t_square *square);
t_square	*setting_find_square(t_map *map);

#endif
