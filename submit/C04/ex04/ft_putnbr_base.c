/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajung <sajung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 01:01:22 by sajung            #+#    #+#             */
/*   Updated: 2022/06/02 18:37:14 by sajung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen4(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_valid4(char *base)
{
	int	i;
	int	j;

	if (ft_strlen4(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
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

void	check_negative(long long *long_nbr)
{
	if (*long_nbr < 0)
	{
		*long_nbr = *long_nbr * -1;
		write(1, "-", 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	char		result[2000];
	int			i;
	long long	size;
	long long	long_nbr;

	long_nbr = nbr;
	if (!is_valid4(base))
		return ;
	size = ft_strlen4(base);
	i = 0;
	check_negative(&long_nbr);
	while (long_nbr > 0)
	{
		result[i] = base[long_nbr % size];
		long_nbr /= size;
		i++;
	}
	while (i > 0)
		write(1, &result[--i], 1);
}

