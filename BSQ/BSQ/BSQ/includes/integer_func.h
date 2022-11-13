/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_func.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:54:44 by cyun              #+#    #+#             */
/*   Updated: 2022/06/06 11:05:23 by cyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGER_FUNC_H
# define INTEGER_FUNC_H

# include "structs.h"

int		find_min(int a, int b, int c);
void	change_square(t_square *square, int x_pos, int y_pos, int length);
int		check_square(int **dp, int x_pos, int y_pos);
int		ft_atoi(char *str);

#endif
