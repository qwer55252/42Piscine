/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 22:06:43 by cyun              #+#    #+#             */
/*   Updated: 2022/06/06 22:21:07 by cyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_func.h"

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_strncpy(char *dest, char *src, int num)
{
	int	idx;

	idx = 0;
	while (idx < num)
	{
		dest[idx] = src[idx];
		idx++;
	}
}

void	print_err_msg(void)
{
	ft_putstr("map error\n");
}
