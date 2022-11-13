/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   information.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:53:11 by cyun              #+#    #+#             */
/*   Updated: 2022/06/05 22:16:50 by cyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFORMATION_H
# define INFORMATION_H

# include "structs.h"
# include "string_func.h"
# include "stdlib.h"

int	is_printable(char c);
int	is_valid_map_info(t_map *map);
int	is_valid_char_info(t_map *map);
int	init_map_info(t_map *map, char *info);
int	parse_map_info(t_map *map, char *info);

#endif
