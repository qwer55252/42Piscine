/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajung <sajung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:59:08 by sajung            #+#    #+#             */
/*   Updated: 2022/06/09 17:56:11 by sajung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen4(char *str);
int	is_space(char c);
int	base_loc(char *base, char c);
int	is_valid(char *base);
int	ft_atoi_base(char *str, char *base);

int	ft_strlen4(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_space(char c)
{
	if (c >= 9 && c <= 13)
		return (1);
	else if (c == ' ')
		return (1);
	return (0);
}

int	base_loc(char *base, char c)
{
	int	i;

	i = 0;
	while (i < ft_strlen4(base))
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	is_valid(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (ft_strlen4(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || is_space(base[i]))
			return (0);
		i++;
	}
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	result;
	int	minus;

	i = 0;
	minus = 1;
	result = 0;
	if (!is_valid(base))
		return (0);
	while (is_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (base_loc(base, str[i]) != -1)
	{
		result = base_loc(base, str[i]) + result * ft_strlen4(base);
		i++;
	}
	return (minus * result);
}
