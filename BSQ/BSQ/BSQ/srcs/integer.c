/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:36:49 by cyun              #+#    #+#             */
/*   Updated: 2022/06/05 21:40:30 by cyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "integer_func.h"

int	find_min(int a, int b, int c)
{
	int	min;

	min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return (min);
}

void	change_square(t_square *square, int x_pos, int y_pos, int length)
{
	square->x_point = x_pos;
	square->y_point = y_pos;
	square->square_length = length;
}

int	check_square(int **dp, int x_pos, int y_pos)
{
	int	min;

	min = find_min(dp[y_pos - 1][x_pos],
			dp[y_pos - 1][x_pos - 1], dp[y_pos][x_pos - 1]);
	dp[y_pos][x_pos] = min + 1;
	return (min + 1);
}

int	ft_atoi(char *str)
{
	int	num;
	int	idx;
	int	sign;

	idx = 0;
	num = 0;
	sign = 1;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			sign = -1;
		idx++;
	}
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		num = num * 10 + (str[idx] - '0') * sign;
		idx++;
	}
	return (num);
}
