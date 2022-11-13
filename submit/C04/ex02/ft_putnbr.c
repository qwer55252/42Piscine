/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajung <sajung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 00:46:08 by sajung            #+#    #+#             */
/*   Updated: 2022/06/02 00:52:17 by sajung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	int_len(int nb)
{
	int	len;

	if (nb < 0)
		nb *= -1;
	len = 0;
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbr_positive(int nb, int nb_len)
{
	int		i;
	char	ch;
	char	str[20];

	i = 0;
	while (nb > 0)
	{
		ch = nb % 10 + '0';
		str[i] = ch;
		nb /= 10;
		i++;
	}
	i = 0;
	while (i < nb_len)
	{
		ch = str[nb_len - 1 - i];
		write(1, &ch, 1);
		i++;
	}
}

void	ft_putnbr_negative(int nb, int nb_len)
{
	int		i;
	char	ch;
	char	str[20];

	nb *= -1;
	i = 0;
	while (nb > 0)
	{
		ch = nb % 10 + '0';
		str[i] = ch;
		nb /= 10;
		i++;
	}
	i = 0;
	write(1, "-", 1);
	while (i < nb_len)
	{
		ch = str[nb_len - 1 - i];
		write(1, &ch, 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	int	nb_len;

	nb_len = int_len(nb);
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
		ft_putnbr_negative(nb, nb_len);
	else if (nb > 0)
		ft_putnbr_positive(nb, nb_len);
	else
		write(1, "0", 1);
}
