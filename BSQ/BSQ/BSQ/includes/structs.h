/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:40:00 by cyun              #+#    #+#             */
/*   Updated: 2022/06/05 19:41:09 by cyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_square
{
	int	x_point;
	int	y_point;
	int	square_length;
}				t_square;

typedef struct s_map
{
	char	full_char;
	char	empty_char;
	char	obstacle_char;
	char	**filled_map;
	int		x_len;
	int		y_len;
}				t_map;

#endif
