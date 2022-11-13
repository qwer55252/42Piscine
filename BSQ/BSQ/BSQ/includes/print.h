/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:57:16 by cyun              #+#    #+#             */
/*   Updated: 2022/06/05 22:16:26 by cyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "structs.h"
# include "unistd.h"
# include "string_func.h"

void	print_map(t_map *map, t_square *square);
void	fill_square_map(t_map *map, t_square *square);

#endif
