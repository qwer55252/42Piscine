/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:52:23 by cyun              #+#    #+#             */
/*   Updated: 2022/06/05 22:14:32 by cyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "structs.h"
# include "stdlib.h"

void	free_map(t_map *map, int size);
char	*free_line(char *line);

#endif
