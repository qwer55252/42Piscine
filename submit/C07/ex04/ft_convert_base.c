/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajung <sajung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:00:32 by sajung            #+#    #+#             */
/*   Updated: 2022/06/09 17:40:30 by sajung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen4(char *str);
int	is_space(char c);
int	base_loc(char *base, char c);
int	is_valid(char *base);
int	ft_atoi_base(char *str, char *base);

void	ft_itoa_base(int nbr, char *base, char *result)
{
	char	ch;
	int		base_size;
	int		i;

	i = 0;
	if (nbr < 0)
	{
		result[i] = '-';
		i++;
		nbr *= -1;
	}
	base_size = ft_strlen4(base);
	while (nbr > 0)
	{
		ch = base[nbr % ft_strlen4(base)];
		result[i] = ch;
		nbr /= base_size;
		i++;
	}
	result[i] = '\0';
}

int	find_result_size(int midnbr, int size)
{
	int	i;

	i = 0;
	if (midnbr == 0)
		return (1);
	if (midnbr < 0)
	{
		midnbr *= -1;
		i++;
	}
	while (midnbr > 0)
	{
		midnbr /= size;
		i++;
	}
	return (i);
}

void	reverse(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = ft_strlen4(str) - 1;
	if (str[i] == '-')
		i++;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		base_from_size;
	int		base_to_size;
	int		midnbr;
	char	*result;
	int		result_size;

	base_from_size = ft_strlen4(base_from);
	if (!is_valid(base_to) || !is_valid(base_from))
		return (0);
	midnbr = ft_atoi_base(nbr, base_from);
	base_to_size = ft_strlen4(base_to);
	result_size = find_result_size(midnbr, base_to_size) + 1;
	result = (char *)malloc(sizeof(char) * result_size);
	ft_itoa_base(midnbr, base_to, result);
	reverse(result);
	return (result);
}
