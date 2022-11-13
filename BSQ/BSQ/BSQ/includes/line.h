/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:56:18 by cyun              #+#    #+#             */
/*   Updated: 2022/06/06 22:05:07 by cyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include <stdlib.h>
# include "structs.h"

char	*expand_line(char *origin_line, int *len);
char	*read_info(int fd);
char	*read_line(int fd, int *cnt);
char	*read_line_faster(t_map *map, int fd, int *cnt);

#endif
