/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:45:11 by cyun              #+#    #+#             */
/*   Updated: 2022/06/06 22:05:33 by cyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include "structs.h"
# include "stdlib.h"
# include "fcntl.h"
# include "print.h"

int		check_read_map(int *idx, t_map *map, char *line);
t_map	*read_map(int fd, int idx, int cnt);
t_map	*read_stdin(void);
t_map	*read_file(char *file);
void	bsq(char *file);

#endif
